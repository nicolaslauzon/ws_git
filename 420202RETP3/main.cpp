#include "Window.hpp"
#include "SlIterator.h"
#include "Solver.h"

#define MAZE mazeC

// Variables essentiels
Window* window;
SlIterator<Position> solution_iterator_;

// Variables optionels
Window::Square maze_[53][53];
Stack<Position> current_solution_;
Solver solver(MAZE);

// Appelée qu'une seule fois avant l'ouverture de la fenêtre.
void onInit() {
    for (int i = 0; i < 53; ++i) {
        for (int j = 0; j < 53; ++j) {
            maze_[i][j] = MAZE[i][j];
        }
    }
    current_solution_= solver.Solution();
    solution_iterator_ = current_solution_.begin();
    solution_iterator_.Iterate();
}

// Appelée pour effectuer un déplacement d'une case.
void onWalk() {
    if (solution_iterator_.End()) {
        maze_[solution_iterator_.Data().X()][solution_iterator_.Data().Y()] = Window::PATH;
        solution_iterator_.Iterate();
    }
}

// Appelée environ 60 fois par seconde lors de l'exécution du programme.
void onDraw() {
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