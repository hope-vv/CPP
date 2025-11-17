#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
private:
    T* data;
    unsigned int ssize;

public:
    Array() : data(NULL), ssize(0) {}
    Array(unsigned int n) : ssize(n)
    {
        data = new T[n]();
    }
    Array(const Array &other) : ssize(other.ssize)
    {
        data = new T[ssize];
        for (unsigned int i = 0; i < ssize; i++)
            data[i] = other.data[i];
    }
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] data;
            ssize = other.ssize;
            data = new T[ssize];
            for (unsigned int i = 0; i < ssize; i++)
                data[i] = other.data[i];
        }
        return *this;
    }
    ~Array()
    {
        delete[] data;
    }

    T &operator[](unsigned int index)
    {
        if (index >= ssize)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    unsigned int size() const
    {
        return ssize;
    }
};

#endif
