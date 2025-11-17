#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "--------------------------------------\n";

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "List contents:" << std::endl;
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
        std::cout << *lit << std::endl;


    std::cout << "---------testing all iterators----------\n";
    std::cout << "forward\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "forward const\n";
    const MutantStack<int> cstack = mstack;
    for (MutantStack<int>::const_iterator it = cstack.begin(); it != cstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "reverse\n";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "reverse const\n";
    for (MutantStack<int>::const_reverse_iterator it = cstack.rbegin(); it != cstack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
