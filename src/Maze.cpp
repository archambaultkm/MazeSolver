//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#include "../inc/Maze.h"
#include <fstream>
#include <iostream>

Maze::Maze(const std::string& file_name) {

    m_maze_start = Position(1, 0); // assumes maze entrance is always the first cell on the left
    m_maze_end = Position(MAZE_SIZE-2, MAZE_SIZE-1); //assumes maze exit is always last cell on the right

    std::ifstream ifs;
    std::string line;

    try {
        ifs.open(file_name, std::fstream::in);

        if (ifs.fail()) {
            std::cout << "Could not open file.";
        }

        int row = 0;
        while (getline(ifs, line)) {

            int column = 0;
            for (char ch: line) {
                m_maze[row][column] = ch;
                m_solution[row][column] =ch; // TODO do I want to initialize solution file this way?
                column++;
            }
            //move to the next line
            row++;
        }

    }  catch (std::ifstream::failure &e) {
        std::cout << "Exception opening/closing/reading file" << std::endl;
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

bool Maze::exists_at(Position p) {
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
        if (ofs.fail()) {
            std::cout << "Could not open file.";
        }

        for (auto & i : m_solution) {
            for (char j : i) {
                ofs << j;
            }
            ofs << std::endl;
        }

    }  catch (std::ofstream::failure &e) {
        std::cout << "Exception opening/closing/reading file" << std::endl;
    }
}
