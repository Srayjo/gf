  #pragma once
#include "SDL.h"
#include <vector>
#include "Vector2D.h"

class InputHandler {
public:
  ~ InputHandler(){}
    static InputHandler* Instance(){
      if(s_pInstance == 0){
         s_pInstance = new InputHandler();
      }
      return s_pInstance;
    }
    enum mouse_buttons {
      LEFT = 0,
      MIDDLE = 1,
      RIGHT = 2
    };
    bool isKeyDown(SDL_Scancode key);
    void update();
    void clean() {}
    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();

private:
    InputHandler();
    static InputHandler* s_pInstance;
    const Uint8* m_keystates;
    // 마우스를 눌렀는지, 안눌렀는지
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;
};
typedef InputHandler TheInputHandler;