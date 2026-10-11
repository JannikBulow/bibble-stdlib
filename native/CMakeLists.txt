cmake_minimum_required(VERSION 3.26)
enable_language(C)

find_package(Bibble CONFIG REQUIRED)

add_library(bibble_stdlib_native SHARED
    src/file.c
)

target_include_directories(bibble_stdlib_native
    PRIVATE
        include
)

target_compile_features(bibble_stdlib_native PRIVATE c_std_11)

set_target_properties(bibble_stdlib_native PROPERTIES
    C_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
)

target_link_libraries(Bibble::BibbleVM-native-interface)

set_target_properties(bibble_stdlib_native PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/tests"
    OUTPUT_NAME "bibble_stdlib"
)