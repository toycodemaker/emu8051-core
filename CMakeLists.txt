cmake_minimum_required(VERSION 3.21)

project(emu8051_core LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_library(emu8051_core STATIC src/1.c)
target_include_directories(emu8051_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(r src/main.c)
target_link_libraries(r PRIVATE emu8051_core)
