#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *array, const int length, void (*f)(T &))
{
    for (int i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void iter(const T *array, const int length, void (*f)(const T &))
{
    for (int i = 0; i < length; i++)
        f(array[i]);
}

#endif
