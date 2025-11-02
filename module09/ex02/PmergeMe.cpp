#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

void checIsInt(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            throw std::invalid_argument("Error");
    }
    
}

void checkLimit(long num)
{
    if (num < 0 || num > INT_MAX)
        throw std::invalid_argument("Error");
}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; i++){
        std::string str(argv[i]);
        checIsInt(str);
        long num = std::atol(str.c_str());
        checkLimit(num);
        vec.push_back(num);
        deq.push_back(num);
        if (vec.empty())
            throw std::invalid_argument("Error");
    }
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
// ------------------------------ vector --------------------------------------

void PmergeMe::insertSortedVec(std::vector<int> &sorted, int value)
{
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);

    sorted.insert(pos, value);
}

void PmergeMe::getPairVec(std::vector<int> &v, std::vector<int> &smaller, std::vector<int> &larger)
{
    size_t i = 0;
    for (; i + 1 < v.size(); i += 2)
    {
        if (v[i] < v[i + 1]){
            smaller.push_back(v[i]);
            larger.push_back(v[i + 1]);
        }
        else
        {                
            smaller.push_back(v[i + 1]);
            larger.push_back(v[i]);
        }
    }
    if (v.size() % 2 != 0)
        smaller.push_back(v.back());
}
void printDebug(std::vector<int> &vec)
{
    std::cout << "Debug: ";
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
void printDebug2(std::vector<int> &smaller, std::vector<int> &larger)
{
    std::cout << "smaller: ";
    for (size_t i = 0; i < smaller.size(); i++){
        std::cout << smaller[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "larger: ";
    for (size_t i = 0; i < larger.size(); i++){
        std::cout << larger[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortVec(std::vector<int> &v)
{
    if (v.size() <= 1)
        return;
    
    std::vector<int> larger;
    std::vector<int> smaller;
    std::vector<int> sorted;

    // pair elements:
    getPairVec(v, smaller, larger);
    // recursion
    // printDebug2(smaller, larger);
    // std::cout << "------------------------------------------\n";
    // mergeInsertSortVec(larger);
    // build sorted list
    sorted = larger;
    // printDebug(sorted);
    // insert smaller elements
    for (size_t i = 0; i < smaller.size(); i ++)
        insertSortedVec(sorted, smaller[i]);
    v = sorted;
}

// ------------------------------ deque --------------------------------------

void PmergeMe::getPairDeq(std::deque<int> &v, std::deque<int> &smaller, std::deque<int> &larger)
{
    size_t i = 0;
    for (; i + 1 < v.size(); i += 2)
    {
        if (v[i] < v[i + 1]){
            smaller.push_back(v[i]);
            larger.push_back(v[i + 1]);
        }
        else
        {                
            smaller.push_back(v[i + 1]);
            larger.push_back(v[i]);
        }
    }
    if (v.size() % 2 != 0)
        smaller.push_back(v.back());
}
void PmergeMe::insertSortedDeq(std::deque<int> &sorted, int value)
{
    std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}
void PmergeMe::mergeInsertSortDeq(std::deque<int> &d)
{
    if (d.size() <= 1)
        return;
    
    std::deque<int> larger;
    std::deque<int> smaller;
    std::deque<int> sorted;

    // pair elements:
    getPairDeq(d, smaller, larger);
    // recursion
    // printDebug2(smaller, larger);
    // std::cout << "------------------------------------------\n";
    // mergeInsertSortVec(larger);
    // build sorted list
    sorted = larger;
    // printDebug(sorted);
    // insert smaller elements
    for (size_t i = 0; i < smaller.size(); i ++)
        insertSortedDeq(sorted, smaller[i]);
    d = sorted;
}

// --------------------------------------------------------------------
void PmergeMe::sortDesplay()
{
    clock_t startVec = clock();
    mergeInsertSortVec(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    mergeInsertSortDeq(deq);
    clock_t endDeq = clock();

    printAfter();

    double vecTime = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double DeqTime = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " (micro s)" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << DeqTime << " (micro s)" << std::endl;

}
