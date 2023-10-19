//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#include "../inc/MazeSolver.h"

#include <iostream>

MazeSolver::MazeSolver() = default;
MazeSolver::~MazeSolver() = default;

bool MazeSolver::solve(Maze& maze) {

    Position current_position = maze.get_maze_start();

    bool solved = false;
    m_successful_moves.push(current_position);

    while (!solved && !m_successful_moves.empty()) {

        current_position = m_successful_moves.pop();
        this->try_available_paths(maze, current_position);

        // if successful moves is empty after checking available paths, break so there's no peek
        if (m_successful_moves.get_size() < 1) break;

        //check if the maze is solved:
        if (m_successful_moves.peek() == maze.get_maze_end()) {
            //need to determine size before the loop bc the size will decrease as you pop
            int stack_size = m_successful_moves.get_size();
            for (int i=0; i< stack_size; i++) {
                maze.set_solution_at(m_successful_moves.pop(), '#');
            }

            solved = true;
        }
    }

    return solved;
}

void MazeSolver::try_available_paths(Maze& maze, Position position) {
    //build an array of positions north, east, south, west of the current position
    Position options[4] {
            Position(position.get_x() +1, position.get_y()), //east
            Position(position.get_x(), position.get_y() + 1), //south
            Position(position.get_x() -1 , position.get_y()), //west
            Position(position.get_x(), position.get_y() - 1), //north
    };

    // attempt the available options, and move to that position
    // if it's a valid space and hasn't been attempted yet
    for (auto & option : options) {
        if (maze.contains(option)) {
            // if option has already been tried or is part of a wall:
            if (std::find(m_attempted_moves.begin(), m_attempted_moves.end(), option) != m_attempted_moves.end()
                || maze.at(option) != ' ') {

                // log as attempted and move on to the next option
                m_attempted_moves.push_back(option);
                continue;
            }

            // log valid option as attempted and successful, and return the last position to the stack
            m_attempted_moves.push_back(option);
            m_successful_moves.push(position);
            m_successful_moves.push(option);

            break;
        }
    }
}

