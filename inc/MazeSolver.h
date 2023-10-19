//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#ifndef ASSIGNMENT_2_MAZESOLVER_H
#define ASSIGNMENT_2_MAZESOLVER_H


#include <vector>
#include "Stack.h"
#include "Maze.h"
#include "Position.h"

class MazeSolver {
private:
    Stack<Position> m_successful_moves;
    std::vector<Position> m_attempted_moves;

public:
    MazeSolver();
    ~MazeSolver();

    bool solve(Maze& maze);
    void try_available_paths(Maze& maze, Position position);
};


#endif //ASSIGNMENT_2_MAZESOLVER_H
