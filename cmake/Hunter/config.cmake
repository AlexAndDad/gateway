
hunter_config(OpenSSL VERSION 1.1.1a)

hunter_config(utf8cpp
        GIT_SUBMODULE git-deps/utfcpp
        CONFIGURATION_TYPES Release
        CMAKE_ARGS UTF8_TESTS=OFF UTF8_INSTALL=ON UTF8_SAMPLES=OFF)

hunter_config(WiseEnum
        GIT_SUBMODULE git-deps/WiseEnum
        CONFIGURATION_TYPES Release)

hunter_config(boost_webclient
        GIT_SUBMODULE git-deps/boost-webclient
        CONFIGURATION_TYPES Release Debug
        CMAKE_ARGS
            BOOST_WEBCLIENT_USE_HUNTER=ON
            BUILD_TESTING=OFF)

hunter_config(boost_json
        GIT_SUBMODULE git-deps/boost_json
        CONFIGURATION_TYPES Release
        CMAKE_ARGS BOOST_JSON_ALLOW_TESTS=NO)

hunter_config(uriparser
        URL https://github.com/uriparser/uriparser/releases/download/uriparser-0.9.3/uriparser-0.9.3.tar.gz
        SHA1 5f041e89e90c53717f047ddca01871afc45010a3
        CMAKE_ARGS
        BUILD_SHARED_LIBS=OFF
        URIPARSER_BUILD_DOCS=OFF
        URIPARSER_BUILD_TESTS=OFF
        URIPARSER_BUILD_TOOLS=OFF)
