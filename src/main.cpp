#include <iostream>
#include "../inc/Maze.h"
#include "../inc/MazeSolver.h"

using namespace std;

int main() {
    Maze maze("../tests/test3.txt");
    cout << maze << endl;

    MazeSolver maze_solver;
    maze_solver.solve(maze);

    return 0;
}