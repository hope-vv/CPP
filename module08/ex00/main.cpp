#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);

    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------------------" << std::endl;
    std::list<int> l;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);
    try {
        std::list<int>::iterator it = easyfind(l, 25);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
