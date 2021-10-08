
#ifndef _TextureManager_
#define _TextureManager_

#include "SDL.h"
#include "map"
#include "SDL_image.h"

class TextureManager  {
  public:
    static TextureManager* Instance()
    {
      if(s_pInstance ==0 )
         s_pInstance = new TextureManager();
         return s_pInstance;
    }

    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    // fileName : 이용할 이미지 파일 이름, id : 텍스처를 참조하기 위해 이용할 이름

    // 멤버 함수 : draw(), drawFrame()
    // id : 그리기 원하는 텍스쳐 id, x.y : 화면의 위치, width.height : 프레임(이미지) 크기
    // FLIP : 기본값 - SDL_FLIP_NONE
    // currentFrame : 나타낼 프레임, currentRow : 시트의 줄
    
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    private:
      TextureManager() {}
     static TextureManager * s_pInstance;
      
       std::map<std::string, SDL_Texture*> m_textureMap;
};
typedef TextureManager TheTextureManager;

#endif