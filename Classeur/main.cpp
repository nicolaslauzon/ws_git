#include "Window.hpp"
// TODO: Inclusions.


// TODO: Déclaration des variables globales.

void onInit() {
  // TODO: Initialisations, instanciations et chargement.
}

void onClick(const SDL_Point& cursor, const bool& rightButton, const bool& ctrl) {
  // TODO: Gestion d'un click de souris.
}

void onMenuClick(const unsigned long& item) {
  // TODO: Gestion d'un click sur un élément du menu contextuel.
}

void onDraw() {
  // TODO: Affichage.
}

void onClose() {
  // TODO: Sauvegarde et libérations.
}

int main(int argc, char* argv[]) {
  window.open(onInit, onClick, onMenuClick, onDraw, onClose);
  return 0;
}
