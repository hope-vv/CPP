#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>

BitcoinExchange::BitcoinExchange() {
    std::cout << "default constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->exchangeRate = other.exchangeRate;
    std::cout << "copy constructor" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->exchangeRate = other.exchangeRate;
    std::cout << "operator assignemnt" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "default destructor" << std::endl;
}

void BitcoinExchange::loadDb(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(1);
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;

        if (!getline(ss, date, ',') || !getline(ss, rateStr))
            continue;

        float rate = std::atof(rateStr.c_str());
        exchangeRate[date] = rate;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 ||
        date[4] != '-' || date[7] != '-') return false;

    int y, m, d;
    char dash1, dash2;
    std::stringstream ss(date);
    ss >> y >> dash1 >> m >> dash2 >> d;

    if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;

    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    std::stringstream ss(value);
    float val;
    ss >> val;

    if (ss.fail() || !ss.eof())
        return false;
    if (val < 0)
        std::cout << "Error: not a positive number.\n";
    if (val > 1000)
        std::cout << "Error: too large a number.\n";

    return (val >= 0 && val <= 1000);
}

void BitcoinExchange::processInputFile(const std::string& inputFilename) const {
    std::ifstream inputFile(inputFilename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return;
    }

    std::string line;
    getline(inputFile, line); // skip header

    while (getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (line.find('|') == std::string::npos) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }

        std::replace(line.begin(), line.end(), '|', ' ');
        std::stringstream lineStream(line);
        lineStream >> date >> valueStr;

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << "\n";
            continue;
        }

        if (!isValidValue(valueStr))
            continue;

        float value = std::atof(valueStr.c_str());

        std::map<std::string, float>::const_iterator it = exchangeRate.lower_bound(date);

        if (it == exchangeRate.end() || it->first != date) {
            if (it == exchangeRate.begin()) {
                std::cout << "Error: no data available for date => " << date << "\n";
                continue;
            }
            --it;
        }

        float rate = it->second;
        float result = rate * value;

        std::cout << date << " => " << value << " = " << result << "\n";
    }
}
