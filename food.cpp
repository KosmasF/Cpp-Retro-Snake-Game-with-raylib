#include "food.h"
#include <iostream>

//Image Food::image 
//Texture2D Food::texture = LoadTextureFromImage(image);
Image Food::image; // Definition of static member variable
Texture2D Food::texture; // Definition of static member variable
bool Food::initialized = false;

Food::Food(Snake* snake)
{
    position = GenerateRandomPos(snake);

    if(!initialized)
    {
        image = LoadImage("Graphics/food.png");
        texture = LoadTextureFromImage(image);
        std::cout<<"Init Food"<<std::endl;
        initialized = true;
    }
}

void Food::Draw()
{
    DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
}

MovementDirection Food::GenerateRandomCell()
{
    int x = GetRandomValue(0, cellCount - 1);
    int y = GetRandomValue(0, cellCount - 1);
    return {x, y};
}

MovementDirection Food::GenerateRandomPos(Snake* snake)
{
    MovementDirection position = GenerateRandomCell();
    while (snake->SnakeIncludes(position, snake->body, snake->bodyCount))
    {
        position = GenerateRandomCell();
    }
    return position;
}