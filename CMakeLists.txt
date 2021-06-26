cmake_minimum_required(VERSION 3.17)
project(SignalSimulation)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(SignalSimulation main.cpp src/area.cpp src/snake.cpp src/box.cpp src/snakes.cpp src/object.cpp)