#ifndef SOLVER_H
#define SOLVER_H

#include "Window.hpp"
#include "Stack.h"
#include "SlIterator.h"
#include "Position.h"

class Solver {

    // Est appelé si il y a une direction qui peut être emprunté.
    void PossibleWay();

    // Est appelé si il n'y a pas de direction qui peut être emprunté.
    void DeadEnd();

    // Permet de déplacer les coordonnées x_ et y_ à partir d'une direction.
    void move(const Direction& direction);

    // Est appelé dans le constructeur. Permet de trouver la solution.
    void Solve();

    // Le maze qui doit être solutionné.
    Window::Square maze_[53][53];

    // Le Stack contenant les positions que l'algorithme emprunte.
    Stack<Position> direction_;

    // Coordonnées de la position actuelle.
    int x_;
    int y_;

public:

    // Consructeur qui permet, à partir d'un maze de trouver une solution sous forme d'un stack.
    Solver(const Window::Square maze[53][53]);

    // Permet d'obtenir la solution.
    const Stack<Position>& Solution() const { return direction_;}
};
#endif //SOLVER_H