#pragma once

#include "raylib.h"
#include "food.h"
#include "snake.h"
#include "gameStates.h"

inline bool allowMove;

class Game
{
public:
    //Game state: in game
    Snake snake = Snake();
    Food food = Food(&snake);
    int score = 0;
    Sound eatSound;
    Sound wallSound;

    States state = InGameRunning;

    Game();

    ~Game();

    void Draw();

    void Update();

    void MoveSnake(MovementDirection direction);

private:
    void CheckCollisionWithFood();

    void CheckCollisionWithEdges();

    void GameOver();

    void CheckCollisionWithTail();
};