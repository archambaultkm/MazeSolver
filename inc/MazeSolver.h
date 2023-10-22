//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#ifndef ASSIGNMENT_2_MAZESOLVER_H
#define ASSIGNMENT_2_MAZESOLVER_H


#include <vector>
#include <chrono>
#include "Stack.h"
#include "Maze.h"
#include "Coordinate.h"

class MazeSolver {
private:
    Stack<Coordinate<int>> m_successful_moves;
    std::vector<Coordinate<int>> m_attempted_moves;
    long m_elapsed_time {};

public:
    MazeSolver();
    ~MazeSolver();

    bool solve(Maze& maze);
    void try_available_paths(Maze& maze, Coordinate<int> position);
    long get_elapsed_time() const;
};


#endif //ASSIGNMENT_2_MAZESOLVER_H
