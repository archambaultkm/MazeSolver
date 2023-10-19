//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#include "../inc/Maze.h"
#include <fstream>
#include <iostream>

Maze::Maze(const std::string& maze_file) {

    m_maze_start = Position(1, 0); // assumes maze entrance is always the first cell on the left
    m_maze_end = Position(MAZE_SIZE-2, MAZE_SIZE-1); //assumes maze exit is always last cell on the right

    std::ifstream ifs;
    std::string line;

    try {
        ifs.open(maze_file, std::fstream::in);

        int row = 0;
        while (getline(ifs, line)) {
            int column = 0;
            for (char ch: line) {
                //initialize both the unsolved maze and the solution while reading in the file
                m_maze[row][column] = ch;
                m_solution[row][column] =ch;
                column++;
            }
            //move to the next line
            row++;
        }

    }  catch (std::ifstream::failure &e) {
        std::cout << "Exception reading file" << std::endl;
    }
}

Maze::~Maze() = default;

Position Maze::get_maze_start() const {
    return m_maze_start;
}

Position Maze::get_maze_end() const {
    return m_maze_end;
}

std::ostream &operator<<(std::ostream &output, Maze& maze) {
    // print maze
    for (auto & i : maze.m_solution) { // TODO switch back to normal m_maze
        for (char j : i) {
            output << j << ' ';
        }
        output << std::endl;
    }

    return output;
}

void Maze::set_solution_at(Position p, char ch) {
    m_solution[p.get_x()][p.get_y()] = ch;
}

char Maze::at(Position p) {
    return m_maze[p.get_x()][p.get_y()];
}

bool Maze::contains(Position p) {
    return  p.get_x() < MAZE_SIZE &&
            p.get_x() > 0 &&
            p.get_y() < MAZE_SIZE &&
            p.get_y() > 0;

}

void Maze::save_to_file(std::string file_name) {
    std::ofstream ofs;
    std::string line;

    try {
        ofs.open(file_name, std::fstream::trunc );

        for (auto & i : m_solution) {
            for (char j : i) {
                ofs << j;
            }
            ofs << std::endl;
        }

    }  catch (std::ofstream::failure &e) {
        std::cout << "Exception writing to file" << std::endl;
    }

    std::cout << "Solution saved to " << file_name << std::endl;
}
