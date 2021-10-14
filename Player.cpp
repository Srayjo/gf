#include "Player.h"


void Player::load(int x, int y, int width, int height, std::string textureID)
{
  // GameObject load() 함수 재정의 
  GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
  // GameObject draw() 함수 재정의 
  GameObject::draw(pRenderer);
}

void Player::update()
{
  // GameObject 멤버 변수 m_x 재정의 후 덮어쓰기
    m_x -= 1;
}