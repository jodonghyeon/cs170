// Name       : Donghyeon Jo
// Course     : CS170
// Term & Year: Spring 2024
#pragma once

#include "Person.h"

class Tweeter : public Person
{
private:
    std::string address;

public:
    Tweeter(std::string first, std::string last, int arbitrary, std::string at)
        : Person(first, last, arbitrary), address(std::move(at))
    {
    }
    ~Tweeter()
    {
        std::cout << address + "-";
    };
};