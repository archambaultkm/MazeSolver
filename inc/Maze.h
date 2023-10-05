//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <string>
#include "Position.h"

const int MAZE_SIZE = 51;

class Maze {
private:
    char m_maze[MAZE_SIZE][MAZE_SIZE]{};
    char m_solution[MAZE_SIZE][MAZE_SIZE]{};

    Position m_maze_start;
    Position m_maze_end;

public:
    explicit Maze(const std::string& maze_file);
    ~Maze();

    void set_solution_at(Position p, char c);
    void save_to_file(std::string filename);
    Position get_maze_start() const;
    Position get_maze_end() const;
    char at(Position p);
    bool exists_at(Position p);

    friend std::ostream& operator<<(std::ostream& output, Maze& maze);
};


#endif //ASSIGNMENT_2_MAZE_H
