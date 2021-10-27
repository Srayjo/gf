#ifndef _Game_
#define _Game_

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

class Game {
private:
   Game(){}
   static Game* s_pInstance;
public:
    ~Game(){}

    static Game* Instance(){
    if(s_pInstance==0){
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }


    bool Init(const char *title, int xpos, int ypos, int width, int height, int flags);

    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

    SDL_Renderer* getRenderer() const {return m_pRenderer;}

    int m_currentFrame;

    // 각 클래스에 대한 멤버 변수 추가
    GameObject m_go; 
    Player m_player;

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;  
    
};

typedef Game TheGame;
#endif