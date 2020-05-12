#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define NEW_FOLDER 1
#define NEW_NOTE 2
#define RENAME 4
#define DELETE 8
#define ENCODE 16
#define DECODE 32
#define SELECT_ALL 64

#define FOLDER 0
#define NOTE 2
#define ENCODED 4

#define ICON_WIDTH 114
#define ICON_HEIGHT 128

class Window {
private:
  SDL_Event sdlEvent;
  SDL_Window* sdlWindow;
  SDL_Renderer* sdlRenderer;
  TTF_Font* ttfFont;
  SDL_Point cursor;

  bool menuIsVisible, itemIsVisible, itemEnable[7];
  SDL_Rect menuRect, itemRect, textRect, iconRect;
  SDL_Texture* itemTextures[7], * disableTextures[7], * icons[6], * textTextures[25];
  unsigned long itemsEnabled;
  void (*onDraw)();

public:
  Window();
  ~Window();

  void drawIcon(const int& x, const int& y, const unsigned char& type, const bool& selected = false);
  void drawString(const int& x, const int& y, const char* text);
  int getStringWidth(const char* text);
  int getHeight();
  int getWidth();
  void open(void (*onInit)(), void (*onClick)(const SDL_Point& cursor, const bool& rightButton, const bool& ctrl), void (*onMenuItemClick)(const unsigned long& item), void (*onDraw)(), void (*onClose)());
  void setTitle(const char* title);
  std::string showTextBox(const std::string& note);
  std::string showTextField(const std::string& name);
  void openContextMenu(const SDL_Point& position, const unsigned long& enabled = 0);
};

Window window;

#endif