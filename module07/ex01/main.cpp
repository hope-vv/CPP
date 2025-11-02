#include <iostream>
#include "Iter.hpp"

template <typename T>
void print(T &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    iter(arr, 4, print);

    std::string strs[] = {"hello", "world"};
    iter(strs, 2, print);

    return 0;
}
