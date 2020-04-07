#include "Window.hpp"
#include "SlIterator.h"
#include "Solver.h"

#define MAZE mazeC

Window* window;
Solver solver(MAZE);
Stack<Position> current_solution_;

// Appelée qu'une seule fois avant l'ouverture de la fenêtre.
void onInit() {
}

// Appelée pour effectuer un déplacement d'une case.
void onWalk() {

    // retourne le stack contenant le chemin à emprunter
    current_solution_ = solver.Solution();
    if (MAZE[current_solution_.top().X()][current_solution_.top().Y()] != Window::ENTRY)
        solver.Solve();
}

// Appelée environ 60 fois par seconde lors de l'exécution du programme.
void onDraw() {

    // Affiche le Array 'maze_' comme il est en ce moment.
    for (int x = 0; x < 53; ++x) {
        for (int y = 0; y < 53; ++y) {
            window->drawSquare( x, y, MAZE[x][y]);
        }
    }

    // Création d'un itérateur de SlNode pour se déplacer dans le stack 'current_solution_'
    SlIterator<Position> solution_iterator_;

    // retourne le stack contenant le chemin à emprunter
    current_solution_ = solver.Solution();
    solution_iterator_ = current_solution_.begin();
    // Si il l'itérateur n'est pas à la fin,
    // Change la valeur à l'endroit où on est rendu
    // pour PATH. Sinon on n'effectue rien.

    while (solution_iterator_.End()) {
        window->drawSquare(solution_iterator_.Data().X(), solution_iterator_.Data().Y(), Window::PATH);
        solution_iterator_.Iterate();
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