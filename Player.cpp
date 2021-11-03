#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
   m_currentFrame = ((SDL_GetTicks()/100)%6);
   m_acceleration.setX(10);
   m_velocity.setX(5);
   SDLGameObject::update();
}

void Player::clean(){}