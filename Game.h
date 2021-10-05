#ifndef _Game_
#define _Game_

#include "SDL.h"
#include "TextureManager.h"

class Game {
  public:
    Game(){}
    ~Game(){}

    bool Init(const char *title, int xpos, int ypos, int width, int height, int flags);
    
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

    TextureManager m_textureManager;
    int m_currentFrame;

  private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;  
    
};

#endif