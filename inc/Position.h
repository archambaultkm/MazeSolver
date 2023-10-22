//
// Created by Kaitlyn Archambault on 2023-10-04.
//

#ifndef ASSIGNMENT_2_POSITION_H
#define ASSIGNMENT_2_POSITION_H

#include <array>

class Position {
private:
    int x;
    int y;

public:
    Position() : x(0), y(0) {};
    Position(int x, int y) : x(x), y(y) {};
    Position(const Position & p)= default;
    ~Position() = default;

    int get_x() const {
        return this->x;
    }

    int get_y() const {
        return this->y;
    }

    // returns an array of positions north, east, south, west of the current position
    std::array<Position, 4> get_adjacent_positions() const {

        std::array<Position, 4> options;

        options[0] = Position(this->x + 1, this->y); // east
        options[1] = Position(this->x, this->y + 1); // south
        options[2] = Position(this->x, this->y - 1); // north
        options[3] = Position(this->x - 1, this->y); // west

        return options;
    }

    bool operator==(const Position& p) const {
        return (this->x == p.x) && (this->y == p.y);
    }
};


#endif //ASSIGNMENT_2_POSITION_H
