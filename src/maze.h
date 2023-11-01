//
// maze.h
// Created by Kaitlyn Archambault on 2023-10-03.
//

#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <string>
#include "../inc/coordinate.h"

const int MAZE_SIZE = 51;

/**
 * @class Maze
 *
 * @brief A class representing a 2D maze from a text file in coordinates.
 *
 */
class Maze {
private:
    char m_maze[MAZE_SIZE][MAZE_SIZE]{}; // The maze grid

    Coordinate<int> m_maze_start; // coordinate representing start of the maze
    Coordinate<int> m_maze_end;  // coordinate representing end of the maze

public:
    /**
     * @brief Constructor to create a Maze object from a maze file.
     *
     * Initializes the maze grid and the maze start/end coordinates by reading a file.
     *
     * @param maze_file The file containing the maze data.
     */
    explicit Maze(const std::string &maze_file);

    /**
    * @brief Destructor.
    */
    ~Maze() = default;

    /**
     * @brief Get the start coordinate of the maze.
     *
     * @return The start coordinate.
     */
    Coordinate<int> get_maze_start() const;

    /**
     * @brief Get the end coordinate of the maze.
     *
     * @return The end coordinate.
     */
    Coordinate<int> get_maze_end() const;

    /**
     * @brief Indicate the solution with a special character at a specific coordinate.
     *
     * @param p The coordinate at which to set the character.
     * @param c The character to set at the coordinate.
     *
     * @note permanently alters the maze grid, should only be used when the full solution has been found
     */
    void set_solution_at(Coordinate<int> p, char c);

    /**
     * @brief Get the character at a specific coordinate in the maze.
     *
     * @param p The coordinate for which to get the character.
     * @return The character at the specified coordinate.
     */
    char at(Coordinate<int> p);

    /**
     * @brief Check if a coordinate is within the bounds of the maze.
     *
     * @param p The coordinate to check.
     * @return `true` if the coordinate is within the maze bounds, `false` otherwise.
     */
    bool contains(Coordinate<int> p);

    /**
     * @brief Save the maze solution to a file.
     *
     * @param filename The name of the file to save the solution to.
     */
    void save_to_file(std::string filename);


    /**
     * @brief  operator to print the maze.
     *
     * @param output The output stream.
     * @param maze The Maze object to print.
     * @return The output stream with the printed maze.
     */
    friend std::ostream &operator<<(std::ostream &output, Maze &maze);
};


#endif //ASSIGNMENT_2_MAZE_H
