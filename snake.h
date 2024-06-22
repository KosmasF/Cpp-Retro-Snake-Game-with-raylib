#pragma once 

#include "raylib.h"
#include "raymath.h"

struct MovementDirection
{
    int x, y;

    bool operator==(const MovementDirection& other)
    {
        if (other.x == x && other.y == y)
            return true;
        return false;
    }

    MovementDirection operator+(const MovementDirection& other)
    {
        return {x + other.x, y + other.y};
    }
};

extern const int cellSize;
extern const int cellCount;
extern const int offset;
extern const Color darkGreen;

class Snake
{
public:
    MovementDirection* body = new MovementDirection[cellSize*cellSize];
    int bodyCount;
    MovementDirection direction;

    void Draw();

    void Update();

    void Reset();

    bool SnakeIncludes(MovementDirection pos, MovementDirection* body, int bodyCount);

    Snake();

    ~Snake();
};