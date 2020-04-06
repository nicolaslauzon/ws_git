#include "Window.hpp"
#include "SlIterator.h"
#include "Solver.h"

#define MAZE mazeC

Window* window;

Window::Square maze_[53][53];

Solver solver(MAZE);
Stack<Position> current_solution_;
SlIterator<Position> solution_iterator_;


// Appelée qu'une seule fois avant l'ouverture de la fenêtre.
void onInit() {

    // initialisation de maze_
    for (int i = 0; i < 53; ++i) {
        for (int j = 0; j < 53; ++j) {
            maze_[i][j] = MAZE[i][j];
        }
    }

    // retourne le stack contenant le chemin à emprunter
    current_solution_ = solver.Solution();

    // Création d'un itérateur de SlNode pour se déplacer dans le stack 'current_solution_'
    solution_iterator_ = current_solution_.begin();

    // La première valeur empilé c'est le départ.
    // Cette instruction permet de passer à la prochaine instruction
    // parce qu'on ne veut pas modifier le départ.
    solution_iterator_.Iterate();
}

// Appelée pour effectuer un déplacement d'une case.
void onWalk() {

    // Si il l'itérateur n'est pas à la fin,
    // Change la valeur à l'endroit où on est rendu
    // pour PATH. Sinon on n'effectue rien.
    if (solution_iterator_.End()) {
        maze_[solution_iterator_.Data().X()][solution_iterator_.Data().Y()] = Window::PATH;
        solution_iterator_.Iterate();
    }
}

// Appelée environ 60 fois par seconde lors de l'exécution du programme.
void onDraw() {

    // Affiche le Array 'maze_' comme il est en ce moment.
    for (int x = 0; x < 53; ++x) {
        for (int y = 0; y < 53; ++y) {
            window->drawSquare( x, y, maze_[x][y]);
        }
    }
}

// Appelée qu'une seule fois après la fermeture de la fenêtre.
void onClose() {
}

int main(int argc, char* argv[]) {
    window = new Window(onInit, onWalk, onDraw, onClose);
    window->open();
    delete window;

    return 0;
}