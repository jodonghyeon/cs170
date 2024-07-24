#pragma once

#include "Constants.h"

#include <raylib.h>

struct SnakeSegment
{
    Vector2       position{ (GAME::SCREENWIDTH % GAME::SQUARE_SIZE) / 2, (GAME::SCREENHEIGHT % GAME::SQUARE_SIZE) / 2 };
    Vector2       size{ GAME::SQUARE_SIZE, GAME::SQUARE_SIZE };
    Vector2       speed{ GAME::SQUARE_SIZE, 0 };
    Color         color{ BLUE };
    SnakeSegment* next{ nullptr };
};

SnakeSegment* PushBackSnakeSegment(SnakeSegment** head);

void DeleteSnakeSegmentList(SnakeSegment* head);
