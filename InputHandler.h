#pragma once
#include "SDL.h"

class InputHandler {
public:
    ~ InputHandler(){}
    static InputHandler* Instance(){
      if(s_pInstance == 0){
         s_pInstance = new InputHandler();
      }
      return s_pInstance;
    }
    // 키 값 입력 받을 함수
    bool isKeyDown(SDL_Scancode key);
    void update();
    void clean() {}

private:
    InputHandler(){}
    static InputHandler* s_pInstance;
    
    // 키보드 상태 확인할 수 있는 배열 
    const Uint8* m_keystates;
};
typedef InputHandler TheInputHandler;