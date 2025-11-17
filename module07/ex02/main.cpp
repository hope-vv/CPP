#include "Array.hpp"
#include <iostream>

int main()
{
    try {
        Array<int> arr1(5); // Create an array of 5 integers
        for (unsigned int i = 0; i < arr1.size(); i++)
        {
            arr1[i] = i * 10;  // Assign some values
        }

        // Test accessing elements
        for (unsigned int i = 0; i < arr1.size(); i++)
        {
            std::cout << arr1[i] << " ";  // Output values
        }
        std::cout << std::endl;

        // Test copy constructor
        Array<int> arr2 = arr1;
        arr2[0] = 100; // Modify a copied element
        std::cout << "After modifying arr2[0]:" << std::endl;
        std::cout << "arr1[0]: " << arr1[0] << std::endl;  // Should not affect arr1
        std::cout << "arr2[0]: " << arr2[0] << std::endl;

        // Test out-of-bounds exception
        try {
            arr1[10] = 50; 
        } catch (const std::out_of_range &e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
