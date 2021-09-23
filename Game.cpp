#include "Game.h"
#include "SDL.h"

bool Game::Init(const char *title, int xpos, int ypos, int width, int height, int flags) // 1
{
  // 윈도우 * 랜더러 등 생성을 위해 SDL_Init() 정의
  if (SDL_Init(SDL_INIT_EVERYTHING)==0){
    m_pWindow = SDL_CreateWindow(title,xpos,ypos,width,height,SDL_WINDOW_MAXIMIZED);
    
    if (m_pWindow !=0){
      m_pRenderer = SDL_CreateRenderer(m_pWindow,-1,0);

      if(m_pRenderer !=0){
        SDL_SetRenderDrawColor(m_pRenderer,255,255,255,255);
      } else{
        return false; // 랜더링 생성 실패
      }
      } else{
        return false; // 윈도우가 거짓이기에 생성 실패 
      } 

      SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

      m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
      // SurFace에 저장된 rider.bmp 를 받고 화면에 그려줌

      SDL_FreeSurface(pTempSurface);

      SDL_QueryTexture(m_pTexture,NULL,NULL,&m_sourceRectangle.w,
      &m_sourceRectangle.h); // 원본 상자의 너비*높이 설정


      // 대상상자 너비*높이 설정
      m_destinationRectangle.w=m_sourceRectangle.w; 
      m_destinationRectangle.h=m_sourceRectangle.h;


      // 원본&대상상자의 위치 설정
      m_destinationRectangle.x=m_sourceRectangle.x;
      m_destinationRectangle.y=m_sourceRectangle.y;
    } else{
      return false; // SDL 초기화에 대한 if문이 거짓이기에 실패
    }

    m_bRunning=true; // SDL,Window,Renderer 생성 및 초기화 성공으로 정상 작동
    return true;
  }

  void Game::update()
  {
  }

  void Game::render()
  {
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer,m_pTexture,&m_sourceRectangle,&m_destinationRectangle);
    SDL_RenderPresent(m_pRenderer);
    // Texture 일부 영역을 Render의 일부 영역에 복사
  }

  bool Game::running()
  {
    return m_bRunning; // true & false 게임 루프 작동시킬건지 멈출건지
  }  

  void Game::handleEvents()
  {
    SDL_Event event;
    if(SDL_PollEvent(&event)){
      switch(event.type){
        case SDL_QUIT:
        m_bRunning =false; // 게임 루프 종료
        break;
        default:
        break;
      }
    }
  }
  void Game::clean() // 사용이 끝난 윈도우&랜더러 삭제 및 SDL 종료
  {
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
 }