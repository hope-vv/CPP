#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Errorrrr" << std::endl;
        return 1;
    }

    RPN rpn;
    int result = rpn.handleRpn(argv[1]);
    if (result != -1)
        std::cout << result << std::endl;

    return 0;
}
