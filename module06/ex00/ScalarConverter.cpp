#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {};

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
};

static bool isChar(std::string const &str)
{
    if (str.size() != 1)
        return false;
    if (!std::isprint(str[0]))
        return false;
    if (std::isdigit(str[0]))
        return false;
    return true;
}

static bool isFloat(std::string const &str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    if (str[str.size() - 1] != 'f')
        return false;
    
    std::string s = str.substr(0, str.size() - 1);
    bool hasDecimal = false;
    size_t i = 0;

    if (s[0] == '+' || s[0] == '-')
        i++;
    while (i < s.size())
    {
        if (s[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
        i++;
    }
    return hasDecimal;
}

static bool isDouble(std::string const &str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    
    bool hasDecimal = false;
    size_t i = 0;

    if (str[0] == '+' || str[0] == '-')
        i++;
    while (i < str.size())
    {
        if (str[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return hasDecimal;
}

static bool isInt(std::string const &str)
{
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++;
    if (i >= str.size())
        return false;
    while (i < str.size())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

void printConversion(double value, const std::string &literal)
{

    if (value != value || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayed" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (value != value || value < -2147483648  || value > 2147483647)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    if (literal == "nan" || literal == "nanf")
        std::cout << "float: nanf" << std::endl;
    else if (literal == "+inf" || literal == "+inff")
        std::cout << "folat: +inff" << std::endl;
    else if (literal == "-inf" || literal == "-inff")
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

    if (literal == "nan" || literal == "nanf")
        std::cout << "double: nanf" << std::endl;
    else if (literal == "+inf" || literal == "+inff")
        std::cout << "double: +inf" << std::endl;
    else if (literal == "-inf" || literal == "-inff")
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: " << value << std::endl;

}

void ScalarConverter::convert(std::string const &literal)
{
    double value = 0.0;

    if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isFloat(literal) || isDouble(literal))
        value = std::atof(literal.c_str());
    else if (isInt(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else
    {
        std::cout << "Error: unknown literal format" << std::endl;
        return;
    }
    printConversion(value, literal);
}

