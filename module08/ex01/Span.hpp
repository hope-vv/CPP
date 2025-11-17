#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits>

class Span
{
    private:
        unsigned int maxSize;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int num);

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end){
            if (std::distance(begin, end) + numbers.size() > maxSize)
                throw std::out_of_range("span full: cannot add range");
            numbers.insert(numbers.end(), begin, end);
        }

        int shortestSpan() const;
        int longestSpan() const;
};

#endif
