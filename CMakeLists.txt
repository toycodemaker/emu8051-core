cmake_minimum_required(VERSION 3.21)

project(emu8051_core LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(
    LIB_SRCS
    ./src/assert.c
    ./src/emu8051.c
)
add_library(emu8051_core STATIC ${LIB_SRCS})
target_include_directories(emu8051_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(r src/main.c)
add_subdirectory(./third/lua)
target_link_libraries(r PRIVATE emu8051_core Lua::lua)
