#ifndef _Player_
#define _Player_

#include "GameObject.h"

class Player : public GameObject // GameObject 클래스 상속
{
  public:

      // 멤버 함수 각각 재정의 
    
      void load(int x, int y, int width, int height, std::string textureID);
      void draw(SDL_Renderer* pRenderer);
      void update();
      void clean();
};

#endif