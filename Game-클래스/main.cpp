#include <stdio.h>
#include "Game.h"
Game* g_game=0;

int main(int argc, char* args[])
{
  g_game=new Game(); // Game 클래스를 상속
  g_game->init("Game Class",100,100,640,480,0);

  while(g_game->running());
  {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
  }
  g_game->Clean();
  return 0;
}
// 명규 ... 