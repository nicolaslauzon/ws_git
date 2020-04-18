#include "Solver.h"

Solver::Solver(const Window::Square maze[53][53]) {
    for (int x = 0; x < 53; ++x) {
        for (int y = 0; y < 53; ++y) {
            if (maze[x][y] == Window::ENTRY) {
                direction_.push(Position(x, y, maze, Position()));
            }
        }
    }
}

void Solver::PossibleWay(const Window::Square maze[53][53]) {
    if (direction_.size()) {
        int tmp_x = direction_.top().X(), tmp_y = direction_.top().Y();
        move(direction_.top().GetRandomDirection(), tmp_x, tmp_y);
        Position newPosition( tmp_x, tmp_y, maze, direction_.top());
        direction_.push(newPosition);
    }
}

void Solver::DeadEnd() {
    direction_.pop();
}

void Solver::move(const Direction direction, int& x, int& y) {
    switch (direction) {
        case North:
            --y;
            break;
        case South:
            ++y;
            break;
        case West:
            --x;
            break;
        case East:
            ++x;
            break;
        case Undefined:
            std::cerr << "Undefined direction" << std::endl;
    }


}
void Solver::Solve(const Window::Square maze[53][53]) {
    if (direction_.size()) {
        if (direction_.top().IsNotEmpty()) {
            PossibleWay(maze);
        }
        else {
            DeadEnd();
        }
    }
}