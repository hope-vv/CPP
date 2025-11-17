#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span &other) {*this = other;}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
    if (numbers.size() >= maxSize)
        throw std::out_of_range("span is full");
    numbers.push_back(num);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::logic_error("not enough numbers");

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; ++i)
        minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);

    return minSpan;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::logic_error("not enough numbers");

    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal = *std::max_element(numbers.begin(), numbers.end());
    return maxVal - minVal;
}
