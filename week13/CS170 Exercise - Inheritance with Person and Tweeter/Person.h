// Name       : Donghyeon Jo
// Course     : CS170
// Term & Year: Spring 2024
#pragma once
#include <string>
class Person
{
private:
    std::string firstname;
    std::string lastname;
    int         arbitraryNumber;

public:
    Person(std::string first, std::string last, int arbitrary)
        : firstname(first), lastname(last),
          arbitraryNumber(arbitrary)
    {
    }
    ~Person() = default;

    virtual std::string GetName() const { return firstname + " " + lastname; }
    int         GetNumber() const { return arbitraryNumber; }
    void        SetNumber(int number) { arbitraryNumber = number; }
};

