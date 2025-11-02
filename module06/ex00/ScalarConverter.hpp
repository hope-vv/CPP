#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();

        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        static void convert(std::string const &literal);

};

#endif