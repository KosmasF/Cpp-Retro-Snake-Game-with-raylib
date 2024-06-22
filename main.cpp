#include <iostream>
#include <raylib.h>

#include "food.h"
#include "game.h"

using namespace std;

//static bool allowMove = false;
const Color green = {173, 204, 96, 255};
const Color darkGreen = {43, 51, 24, 255};

const int cellSize = 30;
const int cellCount = 25;
const int offset = 75;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    cout << "Starting the game..." << endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (EventTriggered(0.2))
        {
            allowMove = true;
            game.Update();
        }

        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1 && allowMove)
        {
            game.MoveSnake({0, -1});
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1 && allowMove)
        {
            game.MoveSnake({0, 1});
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1 && allowMove)
        {
            game.MoveSnake({-1, 0});
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1 && allowMove)
        {
            game.MoveSnake({1, 0});
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            if(game.state == InGameRunning)
                game.state = InGameStopped;
            else if (game.state == InGameStopped)
                game.state = InGameRunning;
        }

        // Drawing
        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, darkGreen);
        DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);
        game.Draw();

        EndDrawing();

    }
    CloseWindow();

    UnloadTexture(Food::texture);
    UnloadImage(Food::image);
    return 0;
}