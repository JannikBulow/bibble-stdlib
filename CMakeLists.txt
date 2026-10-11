cmake_minimum_required(VERSION 3.26)
project(bibble_stdlib VERSION 0.0.1 LANGUAGES NONE)

set(BIBBLEC_EXECUTABLE "" CACHE FILEPATH "bibblec executable")

file(GLOB_RECURSE BIBBLE_STDLIB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/stdlib/src/*.bibl")

if(NOT BIBBLEC_EXECUTABLE)
    message(FATAL_ERROR "no bibblec")
endif()

enable_testing()

add_subdirectory(native)
add_subdirectory(stdlib)
add_subdirectory(tests)