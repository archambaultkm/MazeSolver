//
// Created by Kaitlyn Archambault on 2023-10-04.
//

#ifndef ASSIGNMENT_2_COORDINATE_H
#define ASSIGNMENT_2_COORDINATE_H

#include <array>

template <class T>
class Coordinate {
private:
    T x;
    T y;

public:
    Coordinate() : x(0), y(0) {};
    Coordinate(T x, T y) : x(x), y(y) {};
    Coordinate(const Coordinate & p)= default;
    ~Coordinate() = default;

    int get_x() const {
        return this->x;
    }

    int get_y() const {
        return this->y;
    }

    // returns an array of positions north, east, south, west of the current position
    std::array<Coordinate, 4> get_adjacent_positions(T step) const {

        std::array<Coordinate, 4> options;

        options[0] = Coordinate(this->x + step, this->y); // east
        options[1] = Coordinate(this->x, this->y + step); // south
        options[2] = Coordinate(this->x, this->y - step); // north
        options[3] = Coordinate(this->x - step, this->y); // west

        return options;
    }

    bool operator==(const Coordinate& p) const {
        return (this->x == p.x) && (this->y == p.y);
    }
};


#endif //ASSIGNMENT_2_COORDINATE_H
