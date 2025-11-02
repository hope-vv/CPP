#include "RPN.hpp"


RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN& other)
{
    if (this != &other)
        st = other.st;
    return *this;
}

int callError()
{
    std::cerr << "Error" << std::endl;
    return -1;
}

int RPN::handleRpn(const std::string &str)
{
    std::istringstream iss(str);
    std::string token;
    int a, b;

    while (iss >> token)//Reads each element from the input string.
    {
        if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            if (st.size() < 2)
                return (callError());
            b = st.top(); st.pop();
            a = st.top(); st.pop();
            if (token[0] == '+') st.push(a + b);
            else if (token[0] == '-') st.push(a - b);
            else if (token[0] == '*') st.push(a * b);
            else if (token[0] == '/')
            {
                if (b == 0)
                    return callError();
                st.push(a / b);
            }
            int c = st.top();
        }
        else if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
            st.push(token[0] - '0');
        else
            return callError();
    }
    if (st.size() != 1)
        return callError();
    return st.top();
}