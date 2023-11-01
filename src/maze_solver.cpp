//
// maze_solver.cpp
// Created by Kaitlyn Archambault on 2023-10-03.
//

#include "maze_solver.h"

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

long MazeSolver::get_elapsed_time() const {
    return m_elapsed_time;
}

bool MazeSolver::solve(Maze &maze) {

    // start the timer
    auto start = Clock::now();

    // initialize starting position and solved status
    Coordinate<int> current_position = maze.get_maze_start();
    bool solved = false;
    m_successful_moves.push(current_position);

    while (!solved && !m_successful_moves.empty()) {

        // try to move forwards along an available path from the current position
        current_position = m_successful_moves.pop();
        this->try_available_paths(maze, current_position);

        // If the stack is empty at this point the maze can't be solved- don't allow .peek() on an empty stack.
        if (m_successful_moves.empty()) break;

        // check if the maze is solved:
        if (m_successful_moves.peek() == maze.get_maze_end()) {

            // stop the timer
            auto duration = Clock::now();
            m_elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(duration - start).count();

            // add special characters to the maze solution file along the successful path
            int stack_size = m_successful_moves.get_size();
            for (int i = 0; i < stack_size; i++) {
                maze.set_solution_at(m_successful_moves.pop(), '#');
            }

            solved = true;
        }
    }

    return solved;
}

void MazeSolver::try_available_paths(Maze &maze, Coordinate<int> position) {
    // get an array of coordinates 1 step in each compass direction from the current coordinate
    auto options = position.get_adjacent_coordinates(1);

    // from the available options, only move to a space if it's valid and hasn't been attempted yet
    for (auto &&option: options) {
        if (maze.contains(option) &&
            maze.at(option) == ' ' &&
            std::find(m_attempted_moves.begin(), m_attempted_moves.end(), option) == m_attempted_moves.end()) {

            // log valid option as attempted and successful, and return the last coordinate to the stack
            m_attempted_moves.push_back(option);
            m_successful_moves.push(position);
            m_successful_moves.push(option);

            // break after finding a valid move
            break;
        }
    }
}

