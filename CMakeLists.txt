cmake_minimum_required(VERSION 4.0)
project(image_generation)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
link_directories(include)

add_executable(image_generation main.cpp include/lodepng/lodepng.cpp)
