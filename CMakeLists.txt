cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assignment_2
        src/main.cpp
        src/MazeSolver.cpp
        inc/MazeSolver.h
        src/Maze.cpp
        inc/Maze.h
        inc/Stack.h
        inc/Coordinate.h)
