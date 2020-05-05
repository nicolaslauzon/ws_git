#ifndef POSITION_H
#define POSITION_H

#include "Window.hpp"

#include <vector>

// Enum représentant les directions qu'on pourrait potentiellement emprunter.
enum Direction {
    North = 1,
    West = 2,
    South = 3,
    East = 4,
    Undefined = 0
};

class Position {

    // Coordonnées pour situer la Position dans le maze.
    int x_;
    int y_;

    // Vecteur contenant les directions pouvant être emprunté.
    std::vector<Direction> possible_direction_;

public:

    // Constructeur de base.
    Position();

    // Constructeur principal permettant d'initialiser une instance de Position.
    Position(int x, int y, const Window::Square maze[53][53], Position last_position);

    // Copy constructeur.
    Position(const Position& position);

    // If 'possible_direction_' est vide retourne false, sinon retourne true.
    bool IsNotEmpty() {return !possible_direction_.empty();}

    // Retourne les coordonnées x et y actuelles.
    int X() { return x_; }
    int Y() { return y_; }

    // Retourne la direction qui se trouve en dessous du vecteur et l'efface.
    // 'used_direction_' est affecté à la direction retournée par cette fonction.
    Direction GetRandomDirection();
};
#endif //POSITION_H