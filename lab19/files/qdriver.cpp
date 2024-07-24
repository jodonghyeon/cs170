#include<array>
#include<vector>
#include<iostream>
#include <iomanip>
#include"q.h"
void prn(std::vector<unsigned>const& a_vec)
{
    for (unsigned const l_nVal : a_vec)
    {
        std::cout << l_nVal << ' ';
    }
    std::cout << std::endl;
}
void Test1()
{
    std::cout << "Test 1\n";
    std::array<unsigned, 10>const ar{ 0, 0, 1, 1, 4, 6, 1, 4, 8, 9 };
    prn(hlp2::prime(ar.begin(), ar.end()));
    std::cout << std::endl;
}
void Test2()
{
    std::cout << "Test 2\n";
    std::array<unsigned, 10>const ar{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    prn(hlp2::prime(ar.begin(), ar.end()));
    std::cout << std::endl;
}
void Test3()
{
    std::cout << "Test 3\n";
    std::array<unsigned, 10>const ar{ 5, 3, 0, 1, 5, 4, 9, 8, 7, 6 };
    prn(hlp2::prime(ar.begin(), ar.end()));
    std::cout << std::endl;
}
template<typename T>
void prn(std::map<T, T>const& ip)
{
    std::cout << std::setprecision(3);
    for(std::pair<T,T>const& pr:ip)
    {
        std::cout<<pr.first<<" "<<pr.second<<"\n";
    }
}
void Test4()
{
    std::cout << "Test 4\n";
    std::array<int,11>const ar{ 1,2,2,3,4,5,6,7,8,9,1 };
    std::cout << "Pow 0\n";
    prn(hlp2::pow(ar, 0));
    std::cout << "Pow 1\n";
    prn(hlp2::pow(ar, 1));
    std::cout << "Pow 2\n";
    prn(hlp2::pow(ar, 2));
    std::cout << std::endl;
}
void Test5()
{
    std::cout << "Test 5\n";
    std::array<double, 10>const ar{ 0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };
    std::cout << "Pow 3\n";
    prn(hlp2::pow(ar, 3));
    std::cout << "Pow 4\n";
    prn(hlp2::pow(ar, 4));
    std::cout << std::endl;
}
int main(void) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
}