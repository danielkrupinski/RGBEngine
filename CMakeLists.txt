cmake_minimum_required(VERSION 3.10.2)
project(RGBEngine)

set(CMAKE_BUILD_TYPE Release)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")
set(CMAKE_C_FLAGS_RELEASE "-std=c18 -m64 -Ofast -flto -march=native -funroll-loops -fno-builtin -no-pie")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(RGBEngine ${SOURCES})
target_link_libraries(RGBEngine m glfw GL)
