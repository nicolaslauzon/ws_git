#ifndef POSITION_H
#define POSITION_H

#include "Window.hpp"

#include <vector>
enum Direction {
    North = 1,
    West = 2,
    South = 3,
    East = 4,
    Undefined = 0
};
class Position {
    int x_;
    int y_;
    std::vector<Direction> possible_direction_;
    Direction used_direction_;
public:
    Position();
    Position(int x, int y, const Window::Square maze[53][53], int last_x = 0, int last_y = 0);
    Position(const Position& position);
    bool IsNotEmpty() {return possible_direction_.empty() == 0;}
    int X() { return x_; }
    int Y() { return y_; }
    const Direction& UsedDirection() const { return used_direction_; }
    static Direction ReverseDirection(Direction direction);
    Direction& GetRandomDirection();

};
#endif //POSITION_H