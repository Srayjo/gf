#ifndef _GameObject_
#define _GameObject_

#include "SDL.h"
#include "map"

class GameObject{

  public:

    void load(int x, int y, int width, int height, std::string textureID);

    void draw(SDL_Renderer* pRenderer);
    void update();

    void clean();

  protected:
    std::string m_textureID;

    int m_x;
    int m_y;
    int m_width;
    int m_height;

    int m_currentFrame;
    int m_currentRow;
};

#endif