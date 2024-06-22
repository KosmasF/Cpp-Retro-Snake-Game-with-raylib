#include "snake.h"

void Snake::Draw()
{
    for (int i = 0; i < bodyCount; i++)
    {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = Rectangle{offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize};
        DrawRectangleRounded(segment, 0.5, 6, darkGreen);
    }
}

void Snake::Update()
{
    for (int i = bodyCount - 1; i > 0; i--)
    {
        body[i] = body[i - 1];
    }
    body[0] = body[1] + direction;
}

void Snake::Reset()
{
    body[0] = {6, 9}, body[1] = {5, 9},body[2] = {4, 9};
    direction = {1, 0};
    bodyCount = 3;
}

bool Snake::SnakeIncludes(MovementDirection pos, MovementDirection* body, int bodyCount)
{
    for (int i = 0; i < bodyCount; i++)
    {
        if(body[i] == pos)
            return true;
    }

    return false;
}

Snake::Snake()
{
    Reset();
}

Snake::~Snake()
{
    delete[] body;
}
