#include <random>
#include <algorithm>

#include "Position.h"

Position::Position() {
    x_ = y_ = 0;
}

Position::Position(int x, int y, const Window::Square maze[53][53], Position last_position) {
    x_ = x;
    y_ = y;
    if ((maze[x + 1][y] == Window::WAY || maze[x + 1][y] == Window::EXIT) && !(x + 1 == last_position.X() && y == last_position.Y())) {
        possible_direction_.push_back(East);
    }
    if ((maze[x - 1][y] == Window::WAY || maze[x - 1][y] == Window::EXIT) && !(x - 1 == last_position.X() && y == last_position.Y())) {
        possible_direction_.push_back(West);
    }
    if ((maze[x][y + 1] == Window::WAY || maze[x][y + 1] == Window::EXIT) && !(x == last_position.X() && y + 1 == last_position.Y())) {
        possible_direction_.push_back(South);
    }
    if ((maze[x][y - 1] == Window::WAY || maze[x][y - 1] == Window::EXIT) && !(x == last_position.X() && y - 1 == last_position.Y())) {
        possible_direction_.push_back(North);
    }
    if (possible_direction_.size() > 1) {
        std::random_device randomDevice;
        std::mt19937 g(randomDevice());
        std::shuffle(possible_direction_.begin(), possible_direction_.end(), g);
    }

}

Position::Position(const Position& position) {
    x_ = position.x_;
    y_ = position.y_;
    possible_direction_ = position.possible_direction_;
}

Direction Position::GetRandomDirection() {
    Direction used_direction = possible_direction_.back();
    possible_direction_.pop_back();
    return used_direction;
}