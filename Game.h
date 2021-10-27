#ifndef _Game_
#define _Game_

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

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

  GameObject m_go;
  Player m_player;

  private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;
};

#endif