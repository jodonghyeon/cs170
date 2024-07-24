#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


int main()
{
    Person  Fun("Fun", "Fanny", 456);
    Person& rFun = Fun;
    Person* pFun = &Fun;

    Tweeter  FunBird("Fun", "Fanny", 567, "@fannybord");
    Person*  pFunBird  = &FunBird;
    Person&  rpFunBird = FunBird;
    Tweeter& rtFunBird = FunBird;


    cout << rFun.GetName() << '\n';
    cout << pFun->GetName() << '\n';
    cout << FunBird.GetName() << '\n';
    cout << rpFunBird.GetName() << '\n';
    cout << rtFunBird.GetName() << '\n';
    cout << pFunBird->GetName() << '\n';

    return 0;
}