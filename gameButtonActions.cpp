#include "game.h"

void EnterGame(void* game)
{
    ((Game*)game)->state = InGameRunningNoAllowMove;
}