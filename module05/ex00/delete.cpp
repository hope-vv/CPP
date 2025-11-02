#include <iostream>
#include <exception>

void functionA() {
    std::cout << "Inside functionA" << std::endl;
    throw std::runtime_error("Problem in A"); // throw here
    std::cout << "This line never runs" << std::endl;
}

void functionB() {
    std::cout << "Inside functionB" << std::endl;
    functionA(); // call functionA
    std::cout << "Back in functionB" << std::endl; // never runs if exception thrown
}

int main() {
    try {
        functionB();
    } catch (const std::exception &e) {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
}
