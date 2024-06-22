#include "game.h"


Game::Game()
{
    InitAudioDevice();
    eatSound = LoadSound("Sounds/eat.mp3");
    wallSound = LoadSound("Sounds/wall.mp3");
}

Game::~Game()
{
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
}

void Game::Draw()
{
    
    if(state == InGameRunning || state == InGameStopped)
    {
        food.Draw();
        snake.Draw();
    }
    if(state == InGameStopped)
    {
        int size = 100;
        Vector2 textOffset = MeasureTextEx(GetFontDefault(), "Game paused!", 100, size/10);
        DrawText("Game paused!", offset + (cellSize * cellCount / 2) - (textOffset.x / 2), offset + (cellSize * cellCount / 2) - (textOffset.y / 2), size, BLACK);
    }
}

void Game::Update()
{
    if(state == InGameRunning)
    {
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
}

void Game::MoveSnake(MovementDirection direction)
{
    snake.direction = direction;
    state = InGameRunning;
    allowMove = false;
}

void Game::CheckCollisionWithFood()
{
    if (snake.body[0].x == food.position.x && snake.body[0].y == food.position.y)
    {
        food.position = food.GenerateRandomPos(&snake);
        snake.bodyCount++;
        score++;
        PlaySound(eatSound);
    }
}

void Game::CheckCollisionWithEdges()
{
    if (snake.body[0].x == cellCount || snake.body[0].x == -1)
    {
        GameOver();
    }
    if (snake.body[0].y == cellCount || snake.body[0].y == -1)
    {
        GameOver();
    }
}

void Game::GameOver()
{
    snake.Reset();
    food.position = food.GenerateRandomPos(&snake);
    state = InGameStopped;
    score = 0;
    PlaySound(wallSound);
}

void Game::CheckCollisionWithTail()
{
    MovementDirection* headlessBody = snake.body + 1;
    if (snake.SnakeIncludes(snake.body[0], headlessBody, snake.bodyCount - 1))
    {
        GameOver();
    }
}