#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::update()
{
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT){
      TheGame::Instance()->quit();
    }
    // 키보드 눌린 것이 올라갔을 때
    if(event.type == SDL_KEYUP){
      m_keystates = SDL_GetKeyboardState(0);
    }
    // 키보드를 눌렀을 때
    if(event.type == SDL_KEYDOWN){
      m_keystates = SDL_GetKeyboardState(0);
    }
  }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(m_keystates !=0 ){
      if(m_keystates[key] == 1){
        return true;
      } else { return false; }
    }
    return false;
}