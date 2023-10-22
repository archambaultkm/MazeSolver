#include <iostream>
#include <regex>
#include "../inc/Maze.h"
#include "../inc/MazeSolver.h"

using namespace std;

bool isValidFilePath(const string &provided_file_path);

int main(int argc, char *argv[]) {

    // validate program arguments for maze and solution files
    if (argc == 3) {
        if (!isValidFilePath(argv[1]) || !isValidFilePath(argv[2])) {
            cout << "Must enter a valid .txt format file name for both the maze and solution file." << endl;
            cout << "arguments should resemble \"solve_maze ../tests/test.txt ../solved/solution.txt\" " << endl;

            return 1;
        }
    } else {
        cout << "Invalid arguments: should resemble \"solve_maze ../tests/maze.txt ../solved/solution.txt\" " << endl;

        return 1;
    }

    string maze_file = argv[1];
    string solution_file = argv[2];

    //read file into maze
    Maze maze(maze_file);

    //solve the maze
    MazeSolver maze_solver;
    if (maze_solver.solve(maze)) {
        cout << "Solved maze at " << maze_file << " in " << maze_solver.get_elapsed_time() << " microseconds" << endl;
        maze.save_to_file(solution_file);
    } else {
        cout << "Could not find a solution. Make sure the provided file is a valid maze." << endl;
    }

    return 0;
}

/**
 * Validate provided file path with regex
 *
 * @param provided_file_path file path input by user
 *
 * @returns bool
 * @note Expected file path format is "(/path/)m_file_name.txt"
 */
bool isValidFilePath(const string &provided_file_path) {
    regex valid_file_path(R"(^(?:..)?\/?(?:[a-zA-Z0-9_-]+[\/])?(?:[a-zA-Z0-9_-])+\.txt$)");

    return regex_match(provided_file_path, valid_file_path);
}