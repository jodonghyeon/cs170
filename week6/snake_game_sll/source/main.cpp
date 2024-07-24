#include <raylib.h>

#include "SnakeGame.h"
#include "SnakeSegment.h"

int main(void)
{
    InitWindow(GAME::SCREENWIDTH, GAME::SCREENHEIGHT, "Snake with Linked Lists");
    SetTargetFPS(60);
    {
        SnakeGame game;
        while (!WindowShouldClose()) // Detect window close button or ESC key
        {
            game.Update();
            game.Draw();
        }
    }
    CloseWindow();
    return 0;
}
