cmake_minimum_required(VERSION 3.13)

# 不再写 project()，避免和父项目冲突
# 如果单独构建，可以用 option 控制是否定义项目名

# 源文件目录
set(LUA_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 核心源文件（CORE_O）
set(LUA_CORE_SOURCES
    ${LUA_SRC_DIR}/lapi.c
    ${LUA_SRC_DIR}/lcode.c
    ${LUA_SRC_DIR}/lctype.c
    ${LUA_SRC_DIR}/ldebug.c
    ${LUA_SRC_DIR}/ldo.c
    ${LUA_SRC_DIR}/ldump.c
    ${LUA_SRC_DIR}/lfunc.c
    ${LUA_SRC_DIR}/lgc.c
    ${LUA_SRC_DIR}/llex.c
    ${LUA_SRC_DIR}/lmem.c
    ${LUA_SRC_DIR}/lobject.c
    ${LUA_SRC_DIR}/lopcodes.c
    ${LUA_SRC_DIR}/lparser.c
    ${LUA_SRC_DIR}/lstate.c
    ${LUA_SRC_DIR}/lstring.c
    ${LUA_SRC_DIR}/ltable.c
    ${LUA_SRC_DIR}/ltm.c
    ${LUA_SRC_DIR}/lundump.c
    ${LUA_SRC_DIR}/lvm.c
    ${LUA_SRC_DIR}/lzio.c
)

# 标准库源文件（LIB_O）
set(LUA_LIB_SOURCES
    ${LUA_SRC_DIR}/lauxlib.c
    ${LUA_SRC_DIR}/lbaselib.c
    ${LUA_SRC_DIR}/lcorolib.c
    ${LUA_SRC_DIR}/ldblib.c
    ${LUA_SRC_DIR}/liolib.c
    ${LUA_SRC_DIR}/lmathlib.c
    ${LUA_SRC_DIR}/loadlib.c
    ${LUA_SRC_DIR}/loslib.c
    ${LUA_SRC_DIR}/lstrlib.c
    ${LUA_SRC_DIR}/ltablib.c
    ${LUA_SRC_DIR}/lutf8lib.c
    ${LUA_SRC_DIR}/linit.c
)

# 创建静态库
add_library(lua_static STATIC ${LUA_CORE_SOURCES} ${LUA_LIB_SOURCES})
set_target_properties(lua_static PROPERTIES OUTPUT_NAME "lua")

# 头文件目录，PUBLIC 让父项目自动获得
target_include_directories(lua_static PUBLIC ${LUA_SRC_DIR})

# 目标级 C 标准，避免污染父项目
target_compile_features(lua_static PUBLIC c_std_99)

# 目标级编译选项
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(lua_static PRIVATE -Wall -Wextra -O2)
endif()

# 数学库
if(UNIX)
    target_link_libraries(lua_static PUBLIC m)
endif()

# 平台相关配置
if(APPLE)
    target_compile_definitions(lua_static PUBLIC LUA_USE_MACOSX)
    target_link_libraries(lua_static PUBLIC readline)
elseif(UNIX)
    target_compile_definitions(lua_static PUBLIC LUA_USE_LINUX)
    target_link_libraries(lua_static PUBLIC dl)
    target_link_options(lua_static INTERFACE -Wl,-E)
endif()

# 别名，方便父项目统一用 Lua::lua 引用
add_library(Lua::lua ALIAS lua_static)

# 可选：是否构建 lua / luac 可执行文件
option(LUA_BUILD_EXECUTABLES "Build lua and luac executables" OFF)

if(LUA_BUILD_EXECUTABLES)
    add_executable(lua ${LUA_SRC_DIR}/lua.c)
    target_link_libraries(lua PRIVATE lua_static)

    add_executable(luac ${LUA_SRC_DIR}/luac.c)
    target_link_libraries(luac PRIVATE lua_static)
endif()

# 可选：是否安装
option(LUA_INSTALL "Install Lua targets" OFF)

if(LUA_INSTALL)
    install(TARGETS lua_static
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
    )
    if(LUA_BUILD_EXECUTABLES)
        install(TARGETS lua luac
            RUNTIME DESTINATION bin
        )
    endif()
    install(FILES
        ${LUA_SRC_DIR}/lua.h
        ${LUA_SRC_DIR}/luaconf.h
        ${LUA_SRC_DIR}/lualib.h
        ${LUA_SRC_DIR}/lauxlib.h
        DESTINATION include
    )
endif()
