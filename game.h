#pragma once

#include "raylib.h"
#include "food.h"
#include "snake.h"
#include "gameStates.h"
#include "button.hpp"

#define FONT_SIZE 40

extern const Color green;

void EnterGame(void* game);

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

    TextButton mainMenuEnter = TextButton("Play", GetScreenWidth() / 2 - 200, 200, 400, 100, FONT_SIZE);

};