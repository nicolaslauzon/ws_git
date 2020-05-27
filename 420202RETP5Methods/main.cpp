#include "Sort.h"
/*#include "Window.hpp"
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
*/
int main(int argc, char* argv[]) {
    //Window window;

    //window.open(onInit, onClick, onMenuClick, onDraw, onClose);
    int tabEntier [10] = {1, 9 , 8, 3, 2, 7, 5, 5, 3, 0};
    int *p = &tabEntier[0];
    p = p+1;
    Sort::QuickSort(&tabEntier[0], &tabEntier[9]);
    return 0;
}
