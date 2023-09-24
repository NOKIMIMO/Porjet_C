cmake_minimum_required(VERSION 3.26)
project(Porjet_C C)

set(CMAKE_C_STANDARD 23)

set(SDL2_PATH "C:\\dev\\SDL2")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Porjet_C hello_sdl.c)
target_link_libraries(Porjet_C ${SDL2_LIBRARY})