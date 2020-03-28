#include "Window.hpp"

#define MAZE mazeC

// Appelée qu'une seule fois avant l'ouverture de la fenêtre.
void onInit() {
}

// Appelée pour effectuer un déplacement d'une case.
void onWalk() {
}

// Appelée environ 60 fois par seconde lors de l'exécution du programme.
void onDraw() {
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