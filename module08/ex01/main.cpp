// #include <iostream>
// #include <vector>
// #include "Span.hpp"

// int main()
// {
//     Span sp(5);

//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);

//     std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//     std::cout << "Longest span: " << sp.longestSpan() << std::endl;

//     int arr[] = {20, 25};
//     std::vector<int> nums(arr, arr + 2);
//     // Span sp2(7);
//     sp.addNumbers(nums.begin(), nums.end());

//     return 0;
// }




#include "Span.hpp"
#include <cstdlib>

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;


        std::vector<int> v;
        for (int i = 0; i < 10000; i++)
            v.push_back(i);
        Span big(10000);
        big.addRange(v.begin(), v.end());
        std::cout << "Big shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "longest span: " << big.longestSpan() << std::endl;

    
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
