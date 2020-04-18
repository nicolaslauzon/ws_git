#ifndef SOLVER_H
#define SOLVER_H

#include "Window.hpp"
#include "Stack.h"
#include "SlIterator.h"
#include "Position.h"

class Solver {

    // Est appelé si il y a une direction qui peut être emprunté.
    void PossibleWay(const Window::Square maze[53][53]);

    // Est appelé si il n'y a pas de direction qui peut être emprunté.
    void DeadEnd();

    // Permet de déplacer les coordonnées x_ et y_ dans une direction à partir de celle-ci.
    void move(const Direction direction, int& x, int& y);

    // Le Stack contenant les positions que l'algorithme emprunte.
    Stack<Position> direction_;

public:

    // Consructeur qui permet, à partir d'un maze de trouver une solution sous forme d'un stack.
    Solver(const Window::Square maze[53][53]);

    // Permet d'obtenir la solution.
    const Stack<Position>& Solution() const { return direction_;}

    // Avance d'une case.
    void Solve(const Window::Square maze[53][53]);
};
#endif //SOLVER_H