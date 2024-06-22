#include "food.h"

Image Food::image = LoadImage("Graphics/food.png");
Texture2D Food::texture = LoadTextureFromImage(image);

Food::Food(std::deque<Vector2> snakeBody)
{
    position = GenerateRandomPos(snakeBody);
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