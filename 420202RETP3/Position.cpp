#include <random>
#include <algorithm>

#include "Position.h"

Position::Position() {
    x_ = y_ = 0;
    used_direction_ = Undefined;
}

Position::Position(int x, int y, const Window::Square maze[53][53], int last_x, int last_y) {
    x_ = x;
    y_ = y;
    used_direction_ = Undefined;
    if ((maze[x + 1][y] == Window::WAY || maze[x + 1][y] == Window::EXIT || maze[x + 1][y] == Window::ENTRY) && !(x + 1 == last_x && y == last_y)) {
        possible_direction_.push_back(East);
    }
    if ((maze[x - 1][y] == Window::WAY || maze[x - 1][y] == Window::EXIT || maze[x - 1][y] == Window::ENTRY) && !(x - 1 == last_x && y == last_y)) {
        possible_direction_.push_back(West);
    }
    if ((maze[x][y + 1] == Window::WAY || maze[x][y + 1] == Window::EXIT || maze[x][y + 1] == Window::ENTRY) && !(x == last_x && y + 1 == last_y)) {
        possible_direction_.push_back(South);
    }
    if ((maze[x][y - 1] == Window::WAY || maze[x][y - 1] == Window::EXIT || maze[x][y - 1] == Window::ENTRY) && !(x == last_x && y - 1 == last_y)) {
        possible_direction_.push_back(North);
    }
    if (possible_direction_.size() > 1) {
        std::random_device randomDevice;
        std::mt19937 g(randomDevice());
        std::shuffle(possible_direction_.begin(), possible_direction_.end(), g);
    }

}

Position::Position(const Position& position) {
    used_direction_ = position.used_direction_;
    x_ = position.x_;
    y_ = position.y_;
    possible_direction_ = position.possible_direction_;
}

Direction& Position::GetRandomDirection() {
    used_direction_ = possible_direction_.back();
    possible_direction_.pop_back();
    return used_direction_;
}

Direction Position::ReverseDirection(Direction direction) {
    switch(direction) {
        case North:
            return South;
        case South:
            return North;
        case West:
            return East;
        case East:
            return West;
        case Undefined:
            break;
    }
    return Undefined;
}
