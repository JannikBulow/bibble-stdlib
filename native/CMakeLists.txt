cmake_minimum_required(VERSION 3.26)
enable_language(C)

include(FetchContent)

find_package(Bibble CONFIG REQUIRED)

FetchContent_Declare(libos
    GIT_REPOSITORY https://github.com/JannikBulow/libos
    GIT_TAG master
)
FetchContent_MakeAvailable(libos)

set(SOURCES
    src/io.c
)

set(HEADERS
)

source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

add_library(bibble_stdlib_native SHARED ${SOURCES} ${HEADERS})

target_include_directories(bibble_stdlib_native
    PRIVATE
        include
)

target_compile_features(bibble_stdlib_native PRIVATE c_std_11)

set_target_properties(bibble_stdlib_native PROPERTIES
    C_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
)

target_link_libraries(bibble_stdlib_native INTERFACE Bibble::BibbleVM-native-interface PUBLIC libos-shared)

set_target_properties(bibble_stdlib_native PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/tests"
    OUTPUT_NAME "bibble_stdlib"
)