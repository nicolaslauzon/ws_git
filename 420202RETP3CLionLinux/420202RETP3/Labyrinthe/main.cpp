#include "Window.hpp"
#include <QDebug>
#define MAZE mazeC

// Appelée qu'une seule fois avant l'ouverture de la fenêtre.
void onInit() {
    qCritical().noquote()<< "onInit()"<<endl;
}

// Appelée pour effectuer un déplacement d'une case.
void onWalk() {
  //  qCritical().noquote()<< "onWalk()"<<endl;
}

// Appelée environ 60 fois par seconde lors de l'exécution du programme.
void onDraw() {
  //  qCritical().noquote()<< "onDraw()"<<endl;
}

// Appelée qu'une seule fois après la fermeture de la fenêtre.
void onClose() {
    qCritical().noquote()<< "onClose()"<<endl;
}

int main(int argc, char* argv[]) {

  /*  SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;*/


  Window *window = new Window(onInit, onWalk, onDraw, onClose);
  window->open();
  for (int x = 0; x < 53; x++)
      for (int y = 0; y < 53; y++)
           window->drawSquare(x, y, Window::WALL);
  delete window;

  return 0;
}
