//
// maze_solver.h
// Created by Kaitlyn Archambault on 2023-10-03.
//

#ifndef ASSIGNMENT_2_MAZE_SOLVER_H
#define ASSIGNMENT_2_MAZE_SOLVER_H


#include <vector>
#include "../inc/stack.h"
#include "maze.h"
#include "../inc/coordinate.h"

/**
 * @class MazeSolver
 *
 * @brief A class for solving grid-based mazes using a stack data structure.
 */
class MazeSolver {
private:
    Stack<Coordinate<int>> m_successful_moves; // stores maze solution
    std::vector<Coordinate<int>> m_attempted_moves; // stores all moves attempted
    long m_elapsed_time{}; // how long it took to solve the maze

public:
    /**
     * @brief Default constructor.
     */
    MazeSolver() = default;

    /**
     * @brief Default destructor.
     */
    ~MazeSolver() = default;

    /**
     * @brief Solves a maze using depth first search and a stack
     *
     * The main algorithm loop will run until available path options are exhausted or a solution is found.
     *
     * @param maze The Maze object to be solved.
     * @return `true` if the maze is able to be solved, `false` otherwise.
     */
    bool solve(Maze &maze);

    /**
     * @brief Tries available paths from a given position in the maze.
     *
     * Loops through adjacent options for the given position, attempts the first valid path, and
     * updates both the attempted and successful moves.
     *
     * @param maze The Maze object to navigate.
     * @param position The current position in the maze.
     */
    void try_available_paths(Maze &maze, Coordinate<int> position);

    /**
     * @brief Gets the elapsed time for solving the maze.
     *
     * @return The elapsed time in microseconds.
     */
    long get_elapsed_time() const;
};


#endif //ASSIGNMENT_2_MAZE_SOLVER_H
