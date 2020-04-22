
hunter_config(OpenSSL VERSION 1.1.1a)

hunter_config(utf8cpp
        GIT_SUBMODULE git-deps/utfcpp
        CONFIGURATION_TYPES Release
        CMAKE_ARGS UTF8_TESTS=OFF UTF8_INSTALL=ON UTF8_SAMPLES=OFF)

hunter_config(WiseEnum
        GIT_SUBMODULE git-deps/WiseEnum
        CONFIGURATION_TYPES Release)

hunter_config(BoostWebclient
        GIT_SUBMODULE git-deps/boost-webclient
        CONFIGURATION_TYPES Release RelWithDebInfo Debug
        CMAKE_ARGS BOOST_WEBCLIENT_USE_HUNTER=ON)

hunter_config(boost_json
        GIT_SUBMODULE git-deps/boost_json
        CONFIGURATION_TYPES Release
        CMAKE_ARGS BOOST_JSON_ALLOW_TESTS=NO)
