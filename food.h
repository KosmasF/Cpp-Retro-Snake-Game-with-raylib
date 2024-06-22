#pragma once

#include <raylib.h>
#include "snake.h"

extern const int cellSize;
extern const int cellCount;
extern const int offset;

class Food
{
public:
    MovementDirection position;
    static Image image;
    static Texture2D texture;
    static bool initialized;

    Food(Snake* snake);

    void Draw();

    MovementDirection GenerateRandomCell();

    MovementDirection GenerateRandomPos(Snake* snake);


};