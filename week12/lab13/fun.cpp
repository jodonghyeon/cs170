#include <iostream>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set> // multi versions included
#include <unordered_map>
#include <vector>

using namespace std;

template <typename InputIterator>
void PrintElements(InputIterator begin, InputIterator end)
{
    for (InputIterator current = begin; current != end; ++current)
    {
        cout << *current << ", ";
    }
    cout << '\n';
}

template <typename ForwardIterator>
void PrintAndIncrement(ForwardIterator begin, ForwardIterator end)
{
    for (ForwardIterator current = begin; current != end; ++current)
    {
        *current = *current + typename ForwardIterator::value_type(10);
        cout << *current << ", ";
    }
    cout << '\n';
}

int main(void)
{
    vector vector_ints  = { 5, 2, 3, 4, 1 };
    list   list_doubles = { 10.0, 20.0, 30.0, 40.5 };
    deque  deque_chars  = { 'a', 'b', 'c' };
    set    set_ints     = { 1, 20, 4, 30, 0, 20, 2, 4, 5 };

    // PrintElements(vector_ints.begin(), vector_ints.end());
    // PrintElements(list_doubles.begin(), list_doubles.end());
    // PrintElements(deque_chars.begin(), deque_chars.end());
    // PrintElements(set_ints.begin(), set_ints.end());

    PrintAndIncrement(vector_ints.begin(), vector_ints.end());
    PrintAndIncrement(list_doubles.begin(), list_doubles.end());
    PrintAndIncrement(deque_chars.begin(), deque_chars.end());
    // set only creates input iterators, so read only
    //PrintAndIncrement(set_ints.begin(), set_ints.end());


    return 0;
}