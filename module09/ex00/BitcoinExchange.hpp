#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <map>
#include <algorithm>


class BitcoinExchange
{
    private:
        std::map<std::string, float> exchangeRate;


        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &value) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadDb(const std::string &filename);
        void processInputFile(const std::string &inputfilename) const;

    };





#endif