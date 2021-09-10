#include <stdio.h>
#include<SDL.h>
SDL_Window* g_pWindow=0;
SDL_Renderer* g_pRenderer=0;
bool g_bRunning = false;

bool init(const char* title,int xpos,int ypos, int height,
int width, int flags) 
{
  if(SDL_Init(SDL_INIT_EVERYTHING)>=0) // SDL 초기화
  {
    g_pWindow =SDL_CreateWindow(title,xpos,ypos,height,width,flags); 
    // 윈도우 생성

    if(g_pWindow !=0) 
    {
      g_pRenderer=SDL_CreateRenderer(g_pWindow,-1,0); // 랜더러 생성
    }
  }
  else
  {
    return false;
  }

  SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255); 

  return true;
}

void UpDate() // 업데이트 후 윈도우 이름과 크기 * 색 변경 / 실습 
{
  if(init("Windows UpDate After HelloSDL",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,740,640, SDL_WINDOW_SHOWN))
  SDL_SetRenderDrawColor(g_pRenderer,15,145,245,250);
}

void render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* args[])
{
  if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
  {
    if(init("Breaking Up HelloSDL",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640,480, SDL_WINDOW_SHOWN))
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
    SDL_Delay(5000); 
    UpDate(); // 업데이트하여 화면 변환
    render();
    SDL_Delay(5000);
    g_bRunning=false; // 무한반복문 탈출 / 실습
    SDL_Quit();
  }
  }
  return 0;
}
// 명규 ... 