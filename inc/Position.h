//
// Created by Kaitlyn Archambault on 2023-10-04.
//

#ifndef ASSIGNMENT_2_POSITION_H
#define ASSIGNMENT_2_POSITION_H


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

    bool operator==(const Position& p) const {
        return (this->x == p.x) && (this->y == p.y);
    }
};


#endif //ASSIGNMENT_2_POSITION_H
