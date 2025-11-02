#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <climits>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;

        void mergeInsertSortVec(std::vector<int> &v);
        void mergeInsertSortDeq(std::deque<int> &d);
        
        void getPairVec(std::vector<int> &v, std::vector<int> &smaller, std::vector<int> &larger);
        void getPairDeq(std::deque<int> &v, std::deque<int> &smaller, std::deque<int> &larger);
        
        void insertSortedVec(std::vector<int> &sorted, int value);
        void insertSortedDeq(std::deque<int> &sorted, int value);
        
        public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        
        void printBefore() const;
        void printAfter() const;
        
        void parseInput(int argc, char** argv);
        void sortDesplay();
};

#endif
