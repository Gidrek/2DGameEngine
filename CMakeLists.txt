cmake_minimum_required(VERSION 3.20)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include_directories(${PROJECT_SOURCE_DIR}/Libraries/include)
link_directories(${PROJECT_SOURCE_DIR}/Libraries/libs)

find_package(SDL2_image REQUIRED)

add_executable(2DGameEngine Source/main.cpp Source/Game.cpp Source/Game.h)

target_link_libraries(2DGameEngine SDL2main SDL2 SDL2_image)
