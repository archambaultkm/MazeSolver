//
// Created by Kaitlyn Archambault on 2023-10-04.
//

#ifndef ASSIGNMENT_2_COORDINATE_H
#define ASSIGNMENT_2_COORDINATE_H

#include <array>
#include <concepts>

// "arithmetic" concept from https://stackoverflow.com/questions/14294267/class-template-for-numeric-types
template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template<class T>
requires arithmetic<T>
class Coordinate {
private:
    T x;
    T y;

public:
    Coordinate() : x(0), y(0) {};
    Coordinate(T x, T y) : x(x), y(y) {};
    Coordinate(const Coordinate & p)= default;
    ~Coordinate() = default;

    T get_x() const {
        return this->x;
    }

    T get_y() const {
        return this->y;
    }

    // returns an array of positions north, east, south, west of the current position
    std::array<Coordinate, 4> get_adjacent_positions(T step_size) const {

        std::array<Coordinate, 4> options;

        options[0] = Coordinate(this->x + step_size, this->y); // east
        options[1] = Coordinate(this->x, this->y + step_size); // south
        options[2] = Coordinate(this->x, this->y - step_size); // north
        options[3] = Coordinate(this->x - step_size, this->y); // west

        return options;
    }

    bool operator==(const Coordinate& p) const {
        return (this->x == p.x) && (this->y == p.y);
    }
};


#endif //ASSIGNMENT_2_COORDINATE_H
