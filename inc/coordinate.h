//
// coordinate.h
// Created by Kaitlyn Archambault on 2023-10-04.
//

#ifndef ASSIGNMENT_2_COORDINATE_H
#define ASSIGNMENT_2_COORDINATE_H

#include <array>
#include <concepts>

/**
 * @brief A concept for arithmetic types (integral or floating-point).
 *
 */
template<typename T>
concept numeric = std::integral<T> or std::floating_point<T>;

/**
 * @brief A class representing 2D coordinates with x and y values of a numeric type.

 *
 * @tparam T The type for x and y values (must satisfy numeric concept).
 */
template<class T> requires numeric<T>
class Coordinate {
private:
    T m_x; // x-coordinate
    T m_y; // y-coordinate

public:
    /**
     * @brief Constructor, initializes x and y to 0.
     */
    Coordinate() : m_x(0), m_y(0) {};

    /**
     * @brief Constructor to initialize coordinates with specified values.
     *
     * @param x coordinate.
     * @param y coordinate.
     */
    Coordinate(T x, T y) : m_x(x), m_y(y) {};

    /**
    * @brief Copy constructor.
    *
    * @param p The Coordinate to copy.
    */
    Coordinate(const Coordinate &p) = default;

    /**
     * @brief Default destructor.
     */
    ~Coordinate() = default;

    T get_x() const {
        return this->m_x;
    }

    T get_y() const {
        return this->m_y;
    }

    /**
     * @brief Get an array of coordinates north, east, south, west of the current coordinate
     *
     * @param step_size distance between coordinates
     *
     * @returns An array of 4 Coordinate objects
     */
    std::array<Coordinate, 4> get_adjacent_coordinates(T step_size) const {

        std::array<Coordinate, 4> options;

        options[0] = Coordinate(this->m_x + step_size, this->m_y); // east
        options[1] = Coordinate(this->m_x, this->m_y + step_size); // south
        options[2] = Coordinate(this->m_x, this->m_y - step_size); // north
        options[3] = Coordinate(this->m_x - step_size, this->m_y); // west

        return options;
    }

    /**
     * @brief Equality comparison operator.
     *
     * @param p The Coordinate to compare with.
     * @return bool
     */
    bool operator==(const Coordinate &p) const {
        return (this->m_x == p.m_x) && (this->m_y == p.m_y);
    }
};


#endif //ASSIGNMENT_2_COORDINATE_H
