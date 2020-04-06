#ifndef SOLVER_H
#define SOLVER_H

#include "Window.hpp"
#include "Stack.h"
#include "SlIterator.h"
#include "Position.h"
class Solver {
    void PossibleWay();
    void DeadEnd();
    void move(const Direction& direction);
    void Solve();

    Window::Square maze_[53][53];
    Stack<Position> direction_;
    int x_;
    int y_;
public:
    Solver(const Window::Square maze[53][53]);
    const Stack<Position>& Solution() const { return direction_;}
};


#endif //SOLVER_H