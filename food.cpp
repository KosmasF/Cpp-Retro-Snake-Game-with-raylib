#include "food.h"
#include <iostream>

//Image Food::image 
//Texture2D Food::texture = LoadTextureFromImage(image);
Image Food::image; // Definition of static member variable
Texture2D Food::texture; // Definition of static member variable
bool Food::initialized = false;

Food::Food(std::deque<Vector2> snakeBody)
{
    position = GenerateRandomPos(snakeBody);

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

Vector2 Food::GenerateRandomCell()
{
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}

Vector2 Food::GenerateRandomPos(std::deque<Vector2> snakeBody)
{
    Vector2 position = GenerateRandomCell();
    while (ElementInDeque(position, snakeBody))
    {
        position = GenerateRandomCell();
    }
    return position;
}