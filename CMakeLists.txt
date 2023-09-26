cmake_minimum_required(VERSION 3.26)
project(Porjet_C C)

set(CMAKE_C_STANDARD 23)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)  # Add this line to find SDL_ttf

add_executable(Porjet_C hello_sdl.c)

target_link_libraries(Porjet_C PRIVATE ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})  # Link against SDL2_ttf
target_include_directories(Porjet_C PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})  # Include SDL2_ttf headers