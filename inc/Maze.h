//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <string>
#include "Coordinate.h"

const int MAZE_SIZE = 51;

class Maze {
private:
    char m_maze[MAZE_SIZE][MAZE_SIZE]{};
    char m_solution[MAZE_SIZE][MAZE_SIZE]{};

    Coordinate<int> m_maze_start;
    Coordinate<int> m_maze_end;

public:
    explicit Maze(const std::string& maze_file);
    ~Maze();

    Coordinate<int> get_maze_start() const;
    Coordinate<int> get_maze_end() const;
    void set_solution_at(Coordinate<int> p, char c);
    char at(Coordinate<int> p);
    bool contains(Coordinate<int> p);
    void save_to_file(std::string filename);

    friend std::ostream& operator<<(std::ostream& output, Maze& maze);
};


#endif //ASSIGNMENT_2_MAZE_H
