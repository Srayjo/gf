#include "TextureManager.h"
#include "GameObject.h"

void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
  m_x = x;
  m_y = y;
  m_width = width;
  m_height = height;
  m_textureID = textureID;

  m_currentRow = 0;
  m_currentFrame = 0;

}

void GameObject::draw(SDL_Renderer* pRenderer)
{   
    // TextureManager 클래스의 drawFrame()함수 이용
    TheTextureManager::Instance()
            ->drawFrame(m_textureID,
                 m_x, m_y,
                 m_width, m_height, 
                 m_currentRow, m_currentFrame, 
                 pRenderer);
}

void GameObject::update()
{
    m_x += 1;
}