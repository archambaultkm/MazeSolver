//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#include "../inc/MazeSolver.h"

#include <iostream>

MazeSolver::MazeSolver() = default;

void MazeSolver::solve(Maze& maze) {

    Position current_position = maze.get_maze_start();

    bool solved = false;
    m_successful_moves.push(current_position);

    while (!solved && !m_successful_moves.empty()) {

        current_position = m_successful_moves.pop();

        //build an array of positions north, east, south, west of the current position
        Position options[4] {
            Position(current_position.get_x() +1, current_position.get_y()), //east
            Position(current_position.get_x(), current_position.get_y() + 1), //south
            Position(current_position.get_x() -1 , current_position.get_y()), //west
            Position(current_position.get_x(), current_position.get_y() - 1), //north
        };

        // attempt the available options, and move to that position
        // if it's a valid space and hasn't been attempted yet
        for (auto & option:  options) {
            if (maze.exists_at(option)) {

                //TODO this is formatted weird
                if (std::find(m_attempted_moves.begin(), m_attempted_moves.end(), option) != m_attempted_moves.end()
                    || maze.at(option) != ' ') {
                    // expression will evaluate to true if:
                    // the position has already been attempted
                    // the position contains an unsurpassable character

                    // move on to the next position
                    m_attempted_moves.push_back(option);
                    continue;
                }

                m_attempted_moves.push_back(option);
                maze.set_solution_at(option, '*'); // TODO just for funsies

                m_successful_moves.push(current_position); // TODO is this right?
                m_successful_moves.push(option);

                break; //you have to exit the loop when you find a valid spot
            }
        }

        if (m_successful_moves.peek() == maze.get_maze_end()) {
            std::cout << "Solved!" <<std::endl;

            //need to do this outside the loop bc the size will decrease as you pop
            int stack_size = m_successful_moves.get_size();

            for (int i=0; i< stack_size; i++) {
                maze.set_solution_at(m_successful_moves.pop(), '#');
            }

            maze.save_to_file("../tests/solution.txt");
            std::cout << maze; // TODO debug

            solved = true;
        }
    }
}

MazeSolver::~MazeSolver() = default;
