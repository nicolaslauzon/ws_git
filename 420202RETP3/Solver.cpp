#include "Solver.h"

Solver::Solver(const Window::Square maze[53][53]) {
    for (int x = 0; x < 53; ++x) {
        for (int y = 0; y < 53; ++y) {
            maze_[x][y] =  maze[x][y];
            if (maze[x][y] == Window::ENTRY) {
                x_ = x;
                y_ = y;
            }
        }
    }
    direction_.push(Position(x_, y_, maze_, Position()));
}

void Solver::PossibleWay() {
    if (direction_.size()) {
        move(direction_.top().GetRandomDirection());
        Position newPosition(x_, y_, maze_, direction_.top());
        direction_.push(newPosition);
    }
}

void Solver::DeadEnd() {
    direction_.pop();
    if (direction_.size()) {
        move(Position::ReverseDirection(direction_.top().UsedDirection()));
    }

}

void Solver::move(const Direction& direction) {
    switch (direction) {
        case North:
            --y_;
            break;
        case South:
            ++y_;
            break;
        case West:
            --x_;
            break;
        case East:
            ++x_;
            break;
        case Undefined:
            std::cerr << "Undefined direction" << std::endl;
    }


}
void Solver::Solve() {
    if (direction_.size()) {
        if (direction_.top().IsNotEmpty()) {
            PossibleWay();
        }
        else {
            DeadEnd();
        }
    }
}