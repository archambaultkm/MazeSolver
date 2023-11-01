cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assignment_2
        src/main.cpp
        src/maze_solver.cpp
        src/maze_solver.h
        src/maze.cpp
        src/maze.h
        inc/stack.h
        inc/coordinate.h
        inc/colours.h)

add_executable(solve
        src/main.cpp
        src/maze_solver.cpp
        src/maze_solver.h
        src/maze.cpp
        src/maze.h
        inc/stack.h
        inc/coordinate.h
        inc/colours.h)
