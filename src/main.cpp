//
// main.cpp
// Created by Kaitlyn Archambault on 2023-10-03.
//

#include <iostream>
#include <regex>
#include "../inc/colours.h"
#include "../inc/maze.h"
#include "../inc/maze_solver.h"

using namespace std;

const string expected_arg_format = "\"./solve ../tests/test.txt solution.txt\"";

bool is_valid_file_path(const string &provided_file_path);

int main(int argc, char *argv[]) {

    // validate program arguments for maze and solution files
    if (argc != 3) {
        cerr << RED << "Invalid arguments: expected input resembling " << expected_arg_format << RESET << endl;

        return 1;
    }

    if (!is_valid_file_path(argv[1]) || !is_valid_file_path(argv[2])) {
        cerr << RED << "Must enter a valid .txt format file name for both the maze and solution file." << RESET << endl;
        cout << CYAN << "Arguments should resemble " << expected_arg_format << RESET << endl;

        return 1;
    }

    // proceed with valid file names
    string maze_file = argv[1];
    string solution_file = argv[2];

    // initialize maze and solver
    Maze maze(maze_file);
    MazeSolver maze_solver;

    // attempt to solve the maze and indicate the result
    if (maze_solver.solve(maze)) {
        cout << GREEN << "Solved maze at " << maze_file << " in " << maze_solver.get_elapsed_time() << " microseconds" << RESET << endl;
        maze.save_to_file(solution_file);
    } else {
        cout << RED << "Could not find a solution. Make sure the provided file is a valid maze." << RESET << endl;
    }

    return 0;
}

/**
 * Validate provided file path with regex
 *
 * @param provided_file_path file path input by user
 *
 * @returns true if the provided file path is in a valid format, false otherwise
 * @note Expected file path format is "(/path/)file_name.txt"
 */
bool is_valid_file_path(const string &provided_file_path) {
    regex valid_file_path(R"(^(?:..)?\/?(?:[a-zA-Z0-9_-]+[\/])?(?:[a-zA-Z0-9_-])+\.txt$)");

    return regex_match(provided_file_path, valid_file_path);
}