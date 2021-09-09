#include <stdio.h>
#include<SDL.h>
SDL_Window* g_pWindow=0;
SDL_Renderer* g_pRenderer=0;
bool g_bRunning = false;

int main(int argc, char* args[])
{
    if(init("Breaking Up HelloSDL",SDL_WINDOWPOS_CENTERED,       SDL_WINDOWPOS_CENTERED,640,480, SDL_WINDOW_SHOWN))
  {
    g_bRunning=true;
  }
  else
  {
    return 1;
  }

  while(g_bRunning)
  {
    render();
  }

  SDL_Quit();
  return 0;
}
// 명규 ... 