#include "SnakeGame.h"
#include "SnakeSegment.h"

SnakeGame::SnakeGame() { reset_game(); }

SnakeGame::~SnakeGame() { DeleteSnakeSegmentList(snakeHead); }

void SnakeGame::reset_game()
{
    framesCounter = 0;
    gameOver      = false;
    pause         = false;

    snakeLength = 4;
    allowMove   = false;

    DeleteSnakeSegmentList(snakeHead);
    snakeHead = nullptr;
    PushBackSnakeSegment(&snakeHead);
    snakeHead->color = DARKBLUE;

    SnakeSegment* tail = snakeHead;
    for (int i = 1; i < snakeLength; i++)
    {
        tail = PushBackSnakeSegment(&tail);
    }

    fruit.size   = Vector2{ GAME::SQUARE_SIZE, GAME::SQUARE_SIZE };
    fruit.color  = RED;
    fruit.active = false;
}

bool SnakeGame::got_input()
{
    if (IsKeyPressed(KEY_RIGHT) && snakeHead->speed.x == 0)
    {
        snakeHead->speed = Vector2{ GAME::SQUARE_SIZE, 0 };
        return true;
    }
    else if (IsKeyPressed(KEY_LEFT) && snakeHead->speed.x == 0)
    {
        snakeHead->speed = Vector2{ -GAME::SQUARE_SIZE, 0 };
        return true;
    }
    else if (IsKeyPressed(KEY_UP) && snakeHead->speed.y == 0)
    {
        snakeHead->speed = Vector2{ 0, -GAME::SQUARE_SIZE };
        return true;
    }
    else if (IsKeyPressed(KEY_DOWN) && snakeHead->speed.y == 0)
    {
        snakeHead->speed = Vector2{ 0, GAME::SQUARE_SIZE };
        return true;
    }
    return false;
}

void SnakeGame::update_speeds_to_move_to_head()
{
    SnakeSegment* segment = snakeHead;

    while (segment->next != nullptr)
    {
        const Vector2 new_position = segment->position;
        const Vector2 position     = segment->next->position;
        segment->next->speed       = Vector2{ new_position.x - position.x, new_position.y - position.y };
        segment                    = segment->next;
    }
}

void SnakeGame::move_head()
{
    snakeHead->position.x += snakeHead->speed.x;
    snakeHead->position.y += snakeHead->speed.y;
}

void SnakeGame::move_body_to_head()
{
    SnakeSegment* segment = snakeHead->next;
    while (segment)
    {
        segment->position.x += segment->speed.x;
        segment->position.y += segment->speed.y;
        segment = segment->next;
    }
}

void SnakeGame::check_collision_with_walls()
{
    if (snakeHead->position.x < 0 || snakeHead->position.x > GAME::SCREENWIDTH - GAME::SQUARE_SIZE ||
        snakeHead->position.y < 0 || snakeHead->position.y > GAME::SCREENHEIGHT - GAME::SQUARE_SIZE)
    {
        gameOver = true;
    }
}

void SnakeGame::check_collision_with_self()
{
    SnakeSegment* segment            = snakeHead->next;
    const Vector2 snakehead_position = snakeHead->position;
    while (segment != nullptr)
    {
        const Vector2 segment_position = segment->position;
        if (snakehead_position.x == segment_position.x && snakehead_position.y == segment_position.y)
        {
            gameOver = true;
            break;
        }
        segment = segment->next;
    }
}

void SnakeGame::move_snake()
{
    update_speeds_to_move_to_head();
    move_head();
    move_body_to_head();
}

void SnakeGame::respawn_fruit()
{
    fruit.position.x =
        GetRandomValue(0, (GAME::SCREENWIDTH - GAME::SQUARE_SIZE) / GAME::SQUARE_SIZE) * GAME::SQUARE_SIZE +
        OFFSET.x / 2;
    fruit.position.y =
        GetRandomValue(0, (GAME::SCREENHEIGHT - GAME::SQUARE_SIZE) / GAME::SQUARE_SIZE) * GAME::SQUARE_SIZE +
        OFFSET.y / 2;
    fruit.active = true;
}

void SnakeGame::check_collition_with_fruit()
{
    const Rectangle snake_head_area{ snakeHead->position.x, snakeHead->position.y, snakeHead->size.x,
                                     snakeHead->size.y };
    const Rectangle fruit_area{ fruit.position.x, fruit.position.y, fruit.size.x, fruit.size.y };
    if (CheckCollisionRecs(snake_head_area, fruit_area))
    {
        PushBackSnakeSegment(&snakeHead);
        fruit.active = false;
    }
}

void SnakeGame::update_fruit()
{
    if (!fruit.active)
    {
        respawn_fruit();
    }
    else
    {
        check_collition_with_fruit();
    }
}

void SnakeGame::Update()
{
    if (!gameOver)
    {
        if (IsKeyPressed('P'))
        {
            pause = !pause;
        }
        if (!pause)
        {
            framesCounter++;
            allowMove = got_input() || ((framesCounter % FRAMES_PER_MOVE) == 0);
            if (allowMove)
            {
                move_snake();
                check_collision_with_walls();
                check_collision_with_self();
                allowMove = false;
            }
            update_fruit();
        }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            reset_game();
        }
    }
}

void SnakeGame::draw_gridlines() const
{
    for (int i = 0; i < GAME::SCREENWIDTH / GAME::SQUARE_SIZE + 1; i++)
    {
        DrawLineV(
            Vector2{ GAME::SQUARE_SIZE * i + OFFSET.x / 2, OFFSET.y / 2 },
            Vector2{ GAME::SQUARE_SIZE * i + OFFSET.x / 2, GAME::SCREENHEIGHT - OFFSET.y / 2 }, LIGHTGRAY);
    }

    for (int i = 0; i < GAME::SCREENHEIGHT / GAME::SQUARE_SIZE + 1; i++)
    {
        DrawLineV(
            Vector2{ OFFSET.x / 2, GAME::SQUARE_SIZE * i + OFFSET.y / 2 },
            Vector2{ GAME::SCREENWIDTH - OFFSET.x / 2, GAME::SQUARE_SIZE * i + OFFSET.y / 2 }, LIGHTGRAY);
    }
}

void SnakeGame::draw_snake() const
{
    SnakeSegment* segment = snakeHead;
    while (segment)
    {
        DrawRectangleV(segment->position, segment->size, segment->color);
        segment = segment->next;
    }
}

void SnakeGame::draw_fruit() const { DrawRectangleV(fruit.position, fruit.size, fruit.color); }

void SnakeGame::Draw() const
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    if (!gameOver)
    {
        draw_gridlines();
        draw_snake();
        draw_fruit();
        if (pause)
        {
            DrawText(
                "GAME PAUSED", GAME::SCREENWIDTH / 2 - MeasureText("GAME PAUSED", 40) / 2, GAME::SCREENHEIGHT / 2 - 40,
                40, GRAY);
        }
    }
    else
    {
        DrawText(
            "PRESS [ENTER] TO PLAY AGAIN", GAME::SCREENWIDTH / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2,
            GAME::SCREENHEIGHT / 2 - 50, 20, GRAY);
    }

    EndDrawing();
}
