#pragma once

#include "Constants.h"

#include <raylib.h>

struct SnakeSegment;

class SnakeGame
{
private:
    static constexpr int     FRAMES_PER_MOVE = 10;
    static constexpr Vector2 OFFSET{ GAME::SCREENWIDTH % GAME::SQUARE_SIZE, GAME::SCREENHEIGHT % GAME::SQUARE_SIZE };

private:
    struct Food
    {
        Vector2 position{ 0, 0 };
        Vector2 size{ GAME::SQUARE_SIZE, GAME::SQUARE_SIZE };
        bool    active{ false };
        Color   color{ RED };
    };

private:
    int           framesCounter = 0;
    bool          gameOver      = false;
    bool          pause         = false;
    Food          fruit{};
    SnakeSegment* snakeHead{ nullptr };
    bool          allowMove   = false;
    int           snakeLength = 0;

private:
    void reset_game();
    bool got_input();
    void update_speeds_to_move_to_head();
    void move_head();
    void move_body_to_head();
    void check_collision_with_walls();
    void check_collision_with_self();
    void move_snake();
    void respawn_fruit();
    void check_collition_with_fruit();
    void update_fruit();
    void draw_gridlines() const;
    void draw_snake() const;
    void draw_fruit() const;

public:
    SnakeGame();
    ~SnakeGame();

    void Update();
    void Draw() const;

    SnakeGame(const SnakeGame&)            = delete;
    SnakeGame& operator=(const SnakeGame&) = delete;
    SnakeGame(SnakeGame&&)                 = delete;
    SnakeGame& operator=(SnakeGame&&)      = delete;
};
