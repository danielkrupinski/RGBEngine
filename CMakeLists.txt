cmake_minimum_required(VERSION 3.10.2)
project(RGBEngine)

set(CMAKE_BUILD_TYPE Release)

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(RGBEngine ${SOURCES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

if(WIN32)
    message(FATAL_ERROR "WIN32 TEST")
elseif(UNIX)
    if(APPLE)
        message(FATAL_ERROR "macOS is not supported!")
    endif(APPLE)

set(CMAKE_C_FLAGS_RELEASE "-std=c18 -m64 -Ofast -flto -march=native -funroll-loops -fno-builtin -s")
target_link_libraries(RGBEngine m glfw GL)
