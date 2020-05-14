import json
import pathlib
import io
import os
import sys
import shutil

class hpp_type_bool:
    def __init__(self, name, values, default):
        self.name = name
        self.values = values
        self.default = default


class hpp_type_int:
    def __init__(self, name, values: list, default):
        self.name = name
        self.__str_to_int(values)
        assert self.__check_contiguous(values)
        self.values = values
        self.default = default

    @staticmethod
    def __str_to_int(values: list):
        for num, val in enumerate(values):
            values[num] = int(val)

    @staticmethod
    def __check_contiguous(values: list):
        length = len(values)
        last = int(values[0])
        index = 1
        while index < length:
            if values[index] != (last + 1):
                return False
            last = values[index]
            index += 1
        return True

    def get_largest_value(self):
        largest = 0
        for val in self.values:
            if val > largest:
                largest = val
        return largest

    def type_str(self):
        largest_value = self.get_largest_value()
        if largest_value <= 15:
            return "uint8_t"
        if largest_value <= 65535:
            return "uint16_t"
        else:
            assert False


class hpp_type_enum:
    def __init__(self, name, values: list, default):
        self.name = name
        self.values = values
        self.default = default

    def type_str(self):
        num_values = len(self.values)
        if num_values <= 15:
            return "uint8_t"
        if num_values <= 65535:
            return "uint16_t"
        else:
            assert False

    def class_name(self):
        return "{}_type".format(self.name)


def property_type_determiner(name, values: list, default):
    if len(values) == 2:
        # Check if its a bool
        if values[0] == 'true' and values[1] == 'false':
            return hpp_type_bool(name, values, default)
        elif values[0] == 'false' and values[1] == 'true':
            return hpp_type_bool(name, values, default)
    if values[0].isnumeric():  # int
        # make sure its contiguous
        return hpp_type_int(name, values, default)
    else:  # enum
        return hpp_type_enum(name, values, default)


class minecraft_block:
    def __init__(self, name: str, properties: dict = None, states: list = None):
        self.complete_name = name

        self.states = states
        if properties is not None:
            properties, self.states = minecraft_block.change_invalid_tags(properties, states)
            self.properties = self.generate_hpp_properties_type(properties)
        else:
            self.properties = None

    @staticmethod
    def change_invalid_tags(properties, states):
        invalid_tags = {'short', 'double'}
        new_properties = {}
        for key, value in properties.items():  # rebuild properties
            if key in invalid_tags:
                new_value = []
                for val in value:
                    if val in invalid_tags:
                        new_value.append("{}_".format(val))
                    else:
                        new_value.append(val)
                new_properties["{}_".format(key)] = new_value
            else:
                new_value = []
                for val in value:
                    if val in invalid_tags:
                        new_value.append("{}_".format(val))
                    else:
                        new_value.append(val)
                new_properties[key] = new_value
        new_states = []
        for state in states:
            tmp = dict()
            tmp['properties'] = dict()
            for key, value in state['properties'].items():
                if key in invalid_tags:
                    if value in invalid_tags:
                        value = "{}_".format(value)
                    tmp['properties']["{}_".format(key)] = value
                else:
                    if value in invalid_tags:
                        value = "{}_".format(value)
                    tmp['properties'][key] = value
            if state.get('default'):
                tmp['default'] = True
            tmp['id'] = state['id']
            new_states.append(tmp)
        return new_properties, new_states

    def get_type_of_property(self, key):
        for item in self.properties:
            if item.name == key:
                return type(item)

    def has_properties(self):
        return self.properties is not None

    def struct_name(self):
        return self.complete_name[10:]

    def get_default_property_val(self, property_name):
        for state in self.states:
            if state.get("default"):
                return state['properties'][property_name]
        assert False  # Should always find a default

    def generate_hpp_properties_type(self, properties):
        parsed_properties = []
        for key, val in properties.items():
            parsed_properties.append(property_type_determiner(key, val, self.get_default_property_val(key)))
        return parsed_properties

    def get_only_id(self):
        assert self.properties is None
        return self.states[0]['id']


class BlocksParser:

    @staticmethod
    def get_json_path_from_generated_dir(generated_dir: pathlib.Path) -> pathlib.Path:

        json_path = generated_dir / 'reports' / 'blocks.json'
        assert json_path.is_file()
        return json_path

    def __init__(self, path_to_json):
        with open(path_to_json, 'r') as fh:
            if not fh.readable():
                raise RuntimeError("unable to read: {}".format(path_to_json))
            self.raw_text = fh.read()
        self.json_obj = json.loads(self.raw_text)
        self.blocks = []

    def do_parse(self):

        for name, value in self.json_obj.items():
            properties = value.get('properties')
            states = value.get('states')
            block = minecraft_block(name, properties, states)
            self.blocks.append(block)

        print("There are {} blocks".format(len(self.blocks)))


class BlockWriter:
    def __init__(self, fh):
        self.fh: io.TextIOBase = fh

    def start_struct(self, struct_name):
        self.fh.write("struct {}\n{{".format(struct_name))

    def end_struct(self):
        self.fh.write("};\n")

    def write_property(self, block_property):
        if type(block_property) is hpp_type_bool:
            self.fh.write("bool {} = {};\n".format(block_property.name, block_property.default))

        if type(block_property) is hpp_type_int:
            self.fh.write(
                "std::{} {} = {};\n".format(block_property.type_str(), block_property.name, block_property.default))

        if type(block_property) is hpp_type_enum:
            self.fh.write(
                "enum class {} : std::{}\n{{\n".format(block_property.class_name(), block_property.type_str()))
            first = True
            for value in block_property.values:
                if first:
                    self.fh.write("{}".format(value))
                    first = False
                    continue
                self.fh.write(",\n{}".format(value))
            self.fh.write(
                "\n}} {} = {}::{};\n".format(block_property.name, block_property.class_name(), block_property.default))

    def to_id_execute_stack(self, property_stack, states_index, states):
        current_property = property_stack.pop()

        self.fh.write("switch ({})\n{{\n".format(current_property.name))  # start switch statement
        for value in current_property.values:
            if type(current_property) is hpp_type_enum:
                self.fh.write("case {}::{}:\n".format(current_property.class_name(), value))
            else:
                self.fh.write("case {}:\n".format(value))
            if len(property_stack) != 0:
                states_index = self.to_id_execute_stack(property_stack, states_index, states)
                continue
            else:  # bottom of the stack, out job to write the ID
                self.fh.write("return {};\n".format(states[states_index]['id']))
                states_index += 1

        self.fh.write("}\n")  # end the switch statement
        property_stack.append(current_property)
        return states_index

    def write_to_id_func(self, block: minecraft_block):
        self.fh.write("constexpr block_id_type to_id() const {\n")
        if not block.has_properties():  # Write the simple function
            self.fh.write("return {};".format(block.get_only_id()))

        else:  # write the switch statement function
            states_index = 0
            property_stack = []

            # populate the stack in reverse order
            for block_property in reversed(block.properties):
                property_stack.append(block_property)

            states_index = self.to_id_execute_stack(property_stack, states_index, block.states)
            assert states_index == (len(block.states))

        self.fh.write("}\n")

    def write_from_id_func(self, block: minecraft_block):
        if block.has_properties():
            self.fh.write("constexpr static {} from_id(block_id_type id)\n{{\n".format(block.struct_name()))
        else:
            self.fh.write("constexpr static {} from_id(block_id_type)\n{{\n".format(block.struct_name()))

        if not block.has_properties():
            self.fh.write("return {}();\n".format(block.struct_name()))

        else:
            self.fh.write("switch (id)\n{\n")
            for state in block.states:

                self.fh.write("case {}:\nreturn {{".format(state['id']))
                first = True
                for key, val in state['properties'].items():
                    if first:
                        if block.get_type_of_property(key) == hpp_type_enum:
                            self.fh.write(".{} = {}_type::{}".format(key, key, val))
                        else:
                            self.fh.write(".{} = {}".format(key, val))
                        first = False
                    else:
                        if block.get_type_of_property(key) == hpp_type_enum:
                            self.fh.write(", .{} = {}_type::{}".format(key, key, val))
                        else:
                            self.fh.write(", .{} = {}".format(key, val))
                self.fh.write("};\n")
            self.fh.write("}")

        self.fh.write("}\n")

    def to_string_execute_stack(self, property_stack, string_so_far):
        current_property = property_stack.pop()

        self.fh.write("switch ({})\n{{\n".format(current_property.name))  # start switch statement
        for value in current_property.values:
            if type(current_property) is hpp_type_enum:
                self.fh.write("case {}::{}:\n".format(current_property.class_name(), value))
            else:
                self.fh.write("case {}:\n".format(value))
            if len(property_stack) != 0:
                self.to_string_execute_stack(property_stack, string_so_far + ":{}".format(value))
                continue
            else:  # bottom of the stack, out job to write the ID
                self.fh.write("return \"{}\";\n".format(string_so_far + ":{}".format(value)))

        self.fh.write("}\n")  # end the switch statement
        property_stack.append(current_property)

    def write_to_string_func(self, block):
        self.fh.write("constexpr std::string_view to_string() const\n{")
        if not block.has_properties():
            self.fh.write("return \"{}\";".format(block.complete_name))

        else:
            property_stack = []
            # populate the stack in reverse order
            for block_property in reversed(block.properties):
                property_stack.append(block_property)
            self.to_string_execute_stack(property_stack, block.complete_name)

        self.fh.write("}")

    def write_block(self, block: minecraft_block):
        self.start_struct(block.struct_name())

        if block.has_properties():  # write properties
            for block_property in block.properties:
                self.write_property(block_property)

        self.write_to_id_func(block)
        self.write_from_id_func(block)
        # write to_string() function
        self.write_to_string_func(block)

        self.end_struct()


class IndividualBlockFileGenerator:
    def __init__(self, block, hpp_file_path):
        self.block = block
        self.hpp_file_path = hpp_file_path
        self.fh: io.TextIOBase = None

    def open_fh(self):
        if os.path.exists(self.hpp_file_path):
            os.remove(self.hpp_file_path)
        self.fh = open(self.hpp_file_path, 'w')
        assert self.fh.writable()

    def close_fh(self):
        self.fh.close()

    def write_header(self):
        self.fh.write("#pragma once\n")
        self.fh.write("#include <string_view>\n\n")

    def start_namespace(self, namespace):
        self.fh.write("namespace {}\n{{\n".format(namespace))

    def end_namespace(self, namespace):
        self.fh.write("}}   // namespace {}\n".format(namespace))

    def write_using_statements(self):
        self.fh.write("using block_id_type = std::uint16_t;\n")

    def write_clang_pragmas(self):
        self.fh.write("#pragma clang diagnostic push\n")
        self.fh.write("#pragma clang diagnostic ignored \"-Wreturn-type\"\n")
        self.fh.write("#pragma clang diagnostic ignored \"-Wswitch-bool\"\n")

    def end_clang_pragmas(self):
        self.fh.write("\n#pragma clang diagnostic pop\n")

    def start(self):
        self.open_fh()
        self.write_header()

        self.write_clang_pragmas()

        self.start_namespace("minecraft::blocks")
        self.write_using_statements()

        # write the block
        block_writer = BlockWriter(self.fh)
        block_writer.write_block(self.block)

        self.end_namespace("minecraft::blocks")

        self.end_clang_pragmas()

        self.close_fh()


class BlockhppWriter:
    def __init__(self, blocks, hppfiles, path):
        self.blocks = blocks
        self.hppfiles = hppfiles
        self.path = path
        self.fh: io.TextIOBase = None

    def open_fh(self):
        if os.path.exists(self.path):
            os.remove(self.path)
        self.fh = open(self.path, 'w')
        assert self.fh.writable()

    def close_fh(self):
        self.fh.close()

    def write_header(self):
        self.fh.write("#pragma once\n")
        self.fh.write("#include <string_view>\n\n")
        # Include all hpp files
        for file in self.hppfiles:
            self.fh.write("#include \"{}\"\n".format(file))

        self.fh.write("\n\n")

    def start_namespace(self, namespace):
        self.fh.write("namespace {}\n{{\n".format(namespace))

    def end_namespace(self, namespace):
        self.fh.write("}}   // namespace {}\n".format(namespace))

    def write_using_statements(self):
        self.fh.write("using block_id_type = std::uint16_t;\n")

    def write_clang_pragmas(self):
        self.fh.write("#pragma clang diagnostic push\n")
        self.fh.write("#pragma clang diagnostic ignored \"-Wreturn-type\"\n")
        self.fh.write("#pragma clang diagnostic ignored \"-Wswitch-bool\"\n")

    def end_clang_pragmas(self):
        self.fh.write("\n#pragma clang diagnostic pop\n")

    def write_to_string_func(self):
        self.fh.write(
            "constexpr std::string_view id_to_string(block_id_type id){return visit_block_id([](auto && block){return block.to_string();}, id);}")

    def write_to_block_func(self):
        self.fh.write("constexpr block_variant to_block(block_id_type id)\n{\n")

        self.fh.write("switch (id)\n{")
        for block in self.blocks:
            for state in block.states:
                self.fh.write("case {}:\n".format(state['id']))
            self.fh.write("return {}::from_id(id);\n".format(block.struct_name()))
        self.fh.write("}\n")  # close the switch statement

        self.fh.write("}\n")  # close the function

    def write_visit_block_id(self):
        self.fh.write(
            "template <class F>\nconstexpr auto visit_block_id(F && func, block_id_type id) -> decltype(auto)\n{\n")
        self.fh.write("switch (id)\n{")
        for block in self.blocks:
            for state in block.states:
                self.fh.write("case {}:\n".format(state['id']))
            self.fh.write("return func({}::from_id(id));\n".format(block.struct_name()))
        self.fh.write("}\n")  # close the switch statement
        self.fh.write("}\n")  # close the function

    def start(self):
        self.open_fh()

        self.write_header()

        self.write_clang_pragmas()
        self.start_namespace("minecraft::blocks")
        self.write_using_statements()

        self.write_visit_block_id()
        self.write_to_string_func()
        # self.write_to_block_func()

        self.end_namespace("minecraft::blocks")
        self.end_clang_pragmas()
        self.close_fh()


class BlocksCodeGenerator:

    def __init__(self, blocks: list, hpp_file_path):
        self.blocks = blocks
        self.hpp_file_path = hpp_file_path

    def check_dir(self):
        path = pathlib.Path(self.hpp_file_path + '/blocks')
        if path.exists():
            if path.is_dir():
                shutil.rmtree(self.hpp_file_path + '/blocks')
            elif path.is_file():
                path.unlink()
            else:
                assert False
        path.mkdir()

    def start(self):

        # Check of the 'blocks' dir exists, if it does, remove it.
        self.check_dir()

        hpp_files = []

        # Iterate through all blocks, creating a file for each one.
        for block in self.blocks:
            filename = block.struct_name() + ".hpp"
            full_path = self.hpp_file_path + "blocks/" + filename
            hpp_files.append(filename)

            block_gen = IndividualBlockFileGenerator(block, full_path, )
            block_gen.start()

        # write block.hpp
        blockhpp_writer = BlockhppWriter(self.blocks, hpp_files, self.hpp_file_path + "blocks/block.hpp")
        blockhpp_writer.start()


def test_data_path(generated_path):
    print("path opened at: {}".format(generated_path.absolute()))

    print("subdirs:")
    # List subdirs
    found_subdirs = set()
    for x in generated_path.iterdir():
        if x.is_dir():
            found_subdirs.add(x.name)

    if "reports" in found_subdirs and "data" in found_subdirs:
        print("valid 'generated' dir")
    else:
        print("'generated; dir has an invalid structure.")
        return False

    return True


if __name__ == '__main__':

    if len(sys.argv) < 3:
        print("Invalid quantity of arguments, expecting: data_path, output_path")
        exit(0)

    str_path = sys.argv[1]
    generated_path = pathlib.Path(str_path)

    if not test_data_path(generated_path):
        exit(0)

    output_str_path = sys.argv[2]

    # get data path from 'generated' dir
    json_path = BlocksParser.get_json_path_from_generated_dir(generated_path)

    # parse blocks
    parser = BlocksParser(json_path)
    parser.do_parse()

    # generate code
    blocks_code_gen = BlocksCodeGenerator(parser.blocks, output_str_path)
    blocks_code_gen.start()
