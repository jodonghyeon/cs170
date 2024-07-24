#include <iostream>

#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set> // multi versions included
#include <unordered_map>
#include <vector>

using namespace std;

/*
 *     function object
 *          operator()
 *          add fields
 *          reference variables from outer scope
 *          template version
 *     lambda equivalents
 *          - mutable
 *          - capture by copy / reference
 *          - auto for template version
 */

template <typename InputIterator, typename UnaryPredicate>
void PrintElements(InputIterator begin, InputIterator end, UnaryPredicate predicate)
{
    for (InputIterator current = begin; current != end; ++current)
    {
        if (predicate(*current))
            cout << *current << ", ";
    }
    cout << '\n';
}

bool IsGreaterThan2(int value)
{
    return value > 2;
}

template <typename T>
struct GreaterThan2WithInfo
{
    T&        sum;
    vector<T> discarded_values{};
    GreaterThan2WithInfo(T& outer_sum) : sum(outer_sum)
    {
    }
    bool operator()(T value)
    {
        if (value > T(2))
        {
            return true;
        }
        else
        {
            discarded_values.push_back(value);
            return false;
        }
    }
    ~GreaterThan2WithInfo()
    {
        for (auto v : discarded_values)
        {
            sum += v;
        }
    }
};

int main(void)
{
    vector vector_ints     = { 5, 2, 3, 4, 1 };
    list   list_doubles    = { 10.0, 20.0, 30.0, 40.5 };
    deque  deque_chars     = { 'a', 'b', 'c' };
    set    set_ints        = { 1, 20, 4, 30, 0, 20, 2, 4, 5 };
    float  carray_floats[] = { 3.14f, 1.5f, 0.0f, -1.5f, 3.5f, 2.0f, 99.3f };

    int    sum         = 0;
    double sum_doubles = 0;
    char   sum_chars   = 0;
    float  sum_floats  = 0;


    PrintElements(vector_ints.begin(), vector_ints.end(),
                  GreaterThan2WithInfo{ sum });
    cout << sum << '\n';
    PrintElements(list_doubles.begin(), list_doubles.end(),
                  GreaterThan2WithInfo{ sum_doubles });
    PrintElements(deque_chars.begin(), deque_chars.end(),
                  GreaterThan2WithInfo{ sum_chars });
    PrintElements(std::begin(carray_floats), std::end(carray_floats),
                  GreaterThan2WithInfo{ sum_floats });

    const auto greater_than_2_info = [&sum](int value) {
        if (value > 2)
        {
            return true;
        }
        else
        {
            sum += value;
            return false;
        }
    };

    PrintElements(std::begin(set_ints), std::end(set_ints), greater_than_2_info);

    std::sort(std::begin(carray_floats), std::end(carray_floats),
              [](float left, float right) { return left > right; });
    PrintElements(std::begin(carray_floats), std::end(carray_floats),
                  [](float) { return true; });

    struct Big2Small
    {
        bool operator()(float left, float right)
        {
            return left > right;
        }
    };

    std::sort(std::begin(carray_floats), std::end(carray_floats), Big2Small{});
    struct AlwaysTrue
    {
        bool operator()(float)
        {
            return true;
        }
    };
    PrintElements(std::begin(carray_floats), std::end(carray_floats), AlwaysTrue{});

    auto templated_greater_compare = [](auto left, auto right) {
        return left > right;
    };

    std::sort(deque_chars.begin(), deque_chars.end(), templated_greater_compare);
    PrintElements(std::begin(deque_chars), std::end(deque_chars),
                  [](float) { return true; });

    return 0;
}