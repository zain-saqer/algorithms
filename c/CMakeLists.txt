cmake_minimum_required(VERSION 3.17)
project(algorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(algorithms main.c median.c median.h)
target_link_libraries(algorithms m)