#ifndef _Game_
#define _Game_

#include "SDL.h"

class Game{
  public:
  Game(){ }
  ~Game() {}
  
  bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();
SDL_Texture* m_pTexture;
SDL_Rect m_sourceRectangle;
SDL_Rect m_destinationRectangle;


  private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;
};

#endif