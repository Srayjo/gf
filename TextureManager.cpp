#include "TextureManager.h"


class Singleton{

  private:
    Singleton() {};
    static Singleton* instance;

  public:
    static Singleton* GetInstance()
    {
      if(instance == NULL)
         instance = new Singleton();
         return instance;
    }
};

Singleton* Singleton::instance = NULL;

bool TextureManager::load(std::string fileName,std::string id,SDL_Renderer* pRenderer){

  fileName = "Assets/animate-alpha.png";
  id = "animate";
   SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if(pTempSurface==0) {
    return false;
  }
  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);
  if(pTexture !=0){
    m_textureMap[id] = pTexture;
    return true;
  }
  return false;
}

TextureManager* TextureManager::s_pInstance = 0;


/* void TextureManager::drawbackground(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopy(pRenderer, m_textureMap[id], &srcRect, &destRect);
} */

/* void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
} */

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = width * currentFrame;
  srcRect.y = height * currentRow;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

 
  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
