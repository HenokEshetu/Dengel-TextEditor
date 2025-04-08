cmake_minimum_required(VERSION 3.14)

project(dengel_text_editor VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(vendor/SDL)

add_subdirectory(lib/core)
add_subdirectory(lib/ui)
add_subdirectory(src)
