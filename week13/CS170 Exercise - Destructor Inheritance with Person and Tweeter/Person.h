// Name       : Donghyeon Jo
// Course     : CS170
// Term & Year: Spring 2024
#pragma once
#include <iostream>
#include <string>
class Person
{
private:
    std::string firstname;
    std::string lastname;
    int         arbitraryNumber;

public:
    Person(std::string first, std::string last, int arbitrary)
        : firstname(std::move(first)), lastname(std::move(last)),
          arbitraryNumber(arbitrary)
    {
    }
    virtual ~Person()
    {
        std::cout << firstname + " " + lastname + " " << GetNumber() << '\n';
    };

    std::string GetName() const { return firstname + " " + lastname; }
    int                 GetNumber() const { return arbitraryNumber; }
    void                SetNumber(int number) { arbitraryNumber = number; }
};