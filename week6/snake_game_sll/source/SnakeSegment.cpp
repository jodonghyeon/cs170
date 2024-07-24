#include "SnakeSegment.h"

namespace
{
    SnakeSegment* find_tail(SnakeSegment* start)
    {
        while(start->next)
        {
            start=start->next;
        }
        return start;
    }
}

SnakeSegment* PushBackSnakeSegment(SnakeSegment** head)
{
    if (*head == nullptr)
    {
        *head = new SnakeSegment();
        return *head;
    }
    SnakeSegment* const tail        = find_tail(*head);
    SnakeSegment* const new_segment = new SnakeSegment();
    new_segment->position           = tail->position;
    tail->next                      = new_segment;
    return new_segment;
}

void DeleteSnakeSegmentList(SnakeSegment* head)
{
    while(head){
        SnakeSegment* temp = head;
        head = head->next;
        delete temp;
    }
}