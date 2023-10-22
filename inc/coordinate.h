//
// Created by Kaitlyn Archambault on 2023-10-04.
//

#ifndef ASSIGNMENT_2_COORDINATE_H
#define ASSIGNMENT_2_COORDINATE_H

#include <array>
#include <concepts>

/**
 * @brief A concept for arithmetic types (integral or floating-point).
 *
 * https://stackoverflow.com/questions/14294267/class-template-for-numeric-types
 */
template<typename T>
concept numeric = std::integral<T> or std::floating_point<T>;

/**
 * @brief A class representing 2D coordinates with x and y values of a numeric type.

 *
 * @tparam T The type for x and y values (must satisfy numeric concept).
 */
template<class T>
requires numeric<T>
class Coordinate {
private:
    T x; // x-coordinate
    T y; // y-coordinate

public:
    /**
     * @brief Constructor, initializes x and y to 0.
     */
    Coordinate() : x(0), y(0) {};

    /**
     * @brief Constructor to initialize coordinates with specified values.
     *
     * @param x coordinate.
     * @param y coordinate.
     */
    Coordinate(T x, T y) : x(x), y(y) {};

    /**
    * @brief Copy constructor.
    *
    * @param p The Coordinate to copy.
    */
    Coordinate(const Coordinate & p) = default;

    /**
     * @brief Default destructor.
     */
    ~Coordinate() = default;

    T get_x() const {
        return this->x;
    }

    T get_y() const {
        return this->y;
    }

    /**
     * @brief Get an array of coordinates north, east, south, west of the current coordinate
     *
     * @param step_size distance between coordinates
     *
     * @returns An array of 4 Coordinate objects
     * @note in the future, step_size will ideally be determined within this class
     */
    std::array<Coordinate, 4> get_adjacent_coordinates(T step_size) const {

        std::array<Coordinate, 4> options;

        options[0] = Coordinate(this->x + step_size, this->y); // east
        options[1] = Coordinate(this->x, this->y + step_size); // south
        options[2] = Coordinate(this->x, this->y - step_size); // north
        options[3] = Coordinate(this->x - step_size, this->y); // west

        return options;
    }

    /**
     * @brief Equality comparison operator.
     *
     * @param p The Coordinate to compare with.
     * @return bool
     */
    bool operator==(const Coordinate& p) const {
        return (this->x == p.x) && (this->y == p.y);
    }
};


#endif //ASSIGNMENT_2_COORDINATE_H
