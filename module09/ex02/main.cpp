#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.parseInput(argc, argv);
        sorter.printBefore();
        sorter.sortDesplay();
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
