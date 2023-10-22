//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#include "../inc/maze.h"
#include <fstream>
#include <iostream>

Maze::Maze(const std::string& maze_file) {

    m_maze_start = Coordinate<int>(1, 0); // assumes maze entrance is always the first cell on the left
    m_maze_end = Coordinate<int>(MAZE_SIZE - 2, MAZE_SIZE - 1); //assumes maze exit is always last cell on the right

    std::ifstream ifs;
    std::string line;

    //attempt to open the provided file and read its contents into the maze grid
    try {
        ifs.open(maze_file, std::fstream::in);

        int row = 0;
        while (getline(ifs, line)) {
            int column = 0;
            for (char ch: line) {
                //initialize the unsolved maze
                m_maze[row][column] = ch;
                column++;
            }
            //move to the next line
            row++;
        }
    }  catch (std::ifstream::failure &e) {
        std::cout << "Exception reading source file" << std::endl;
    }
}

Coordinate<int> Maze::get_maze_start() const {
    return m_maze_start;
}

Coordinate<int> Maze::get_maze_end() const {
    return m_maze_end;
}

std::ostream &operator<<(std::ostream &output, Maze& maze) {
    // print maze grid character by character
    for (auto & i : maze.m_maze) {
        for (char j : i) {
            output << j << ' ';
        }
        //move to the next line
        output << std::endl;
    }

    return output;
}

void Maze::set_solution_at(Coordinate<int> p, char ch) {
    m_maze[p.get_x()][p.get_y()] = ch;
}

char Maze::at(Coordinate<int> p) {
    return m_maze[p.get_x()][p.get_y()];
}

bool Maze::contains(Coordinate<int> p) {
    return  p.get_x() < MAZE_SIZE &&
            p.get_x() >= 0 &&
            p.get_y() < MAZE_SIZE &&
            p.get_y() >= 0;

}

void Maze::save_to_file(std::string file_name) {
    std::ofstream ofs;
    std::string line;

    try {
        //overwrite the file completely if it already exists
        ofs.open(file_name, std::fstream::trunc );

        //copy maze grid character by character into the file
        for (auto & i : m_maze) {
            for (char j : i) {
                ofs << j;
            }
            ofs << std::endl;
        }

    }  catch (std::ofstream::failure &e) {
        std::cout << "Exception writing to solution file" << std::endl;
    }

    std::cout << "Solution saved to " << file_name << std::endl;
}
