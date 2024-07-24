//TODO source header

#include <iostream>
#include <string>

using namespace std;
using namespace string_literals;

int main()
{
    int    i = -1;
    string love_is{"Coconuts"};
    double PI = 3.14;

    // part 0 - Rewrite lambda as a function object
    auto lambda0 = [&, count = 0]() mutable {
        ++count;
        cout << "[" << count << "] "
             << "{ i : " << i << ", love_is : " << love_is
             << ", PI : " << PI << " }\n";
    };

    // part 1 - Rewrite lambda as a function object
    const auto lambda1 = [=](string name) {
        cout << name << " loves " << love_is << " maybe too much?!?\n";
        cout << "some number: " << i * PI << "\n";
    };

    lambda0();
    lambda1("Rudy");
    lambda0();

    // part 2 - Rewrite function object as a lambda
    struct part2
    {
        int&         i;
        const string love_is;
        double&      PI;
        part2(int& one, string two, double& three)
            : i{one}, love_is{std::move(two)}, PI{three}
        {
        }

        string operator()(double scale) const
        {
            i *= static_cast<int>(scale);
            PI /= scale;
            return love_is + " "s + to_string(i) + " "s + to_string(PI);
        }
    };

    const auto lambda2 = part2{i, love_is, PI};

    lambda0();
    cout << lambda2(2.0) << "\n";
    lambda0();

    return 0;
}