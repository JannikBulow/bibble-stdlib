cmake_minimum_required(VERSION 3.26)

add_custom_target(bibble_stdlib
    COMMAND "${BIBBLEC_EXECUTABLE}" ${BIBBLE_STDLIB_SOURCES}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    DEPENDS bibble_stdlib_native
    VERBATIM
)