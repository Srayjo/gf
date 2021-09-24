#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"

bool Game::Init(const char *title, int xpos, int ypos, int width, int height, int flags) // 1
{
  // 윈도우 * 랜더러 등 생성을 위해 SDL_Init() 정의
  if (SDL_Init(SDL_INIT_EVERYTHING)==0){
    m_pWindow = SDL_CreateWindow(title,xpos,ypos,width,height,SDL_WINDOW_SHOWN);
    
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

      // SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

      // png 파일을 불러오기 위한 image.h의 함수 호출
      SDL_Surface* pTempSurface=IMG_Load("Assets/rider.bmp");

      m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
      // SurFace에 저장된 rider.bmp 를 받고 화면에 그려줌

      SDL_FreeSurface(pTempSurface);

      SDL_QueryTexture(m_pTexture,NULL,NULL,&m_sourceRectangle.w,
      &m_sourceRectangle.h); // 원본 상자의 너비*높이 설정 

       // 원본상자의 이미지 크기 설정

     /* m_sourceRectangle.w=70;  
       m_sourceRectangle.h=70; */

      m_sourceRectangle.w=width; 
      m_sourceRectangle.h=height; 
      // 전체화면

      // 대상상자 너비*높이 설정 -> 원본상자의 사이즈 그대로 가져옴
      m_destinationRectangle.w=m_sourceRectangle.w; 
      m_destinationRectangle.h=m_sourceRectangle.h;

      m_sourceRectangle.w=width;
      m_sourceRectangle.h=height;

      // 원본 상자의 이미지에서 내가 쓸 부분 출력

     /* m_sourceRectangle.x=-20; -> 말 머리 부분
      m_sourceRectangle.y=-20; */

      /*m_sourceRectangle.x=50; -> 말 꼬리 부분
      m_sourceRectangle.y=50; */ 

      // 윈도우 상에 이미지를 어디 축에 출력할지
     /* m_destinationRectangle.x=100;
      m_destinationRectangle.y=100; */

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