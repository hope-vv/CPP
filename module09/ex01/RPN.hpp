#ifndef RNP_HPP
#define RNP_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> st;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN &operator=(const RPN& other);

        int handleRpn(const std::string &str);
};

#endif