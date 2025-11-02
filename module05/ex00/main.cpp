#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "---------------------------------------------" << std::endl;
    
    try {
        Bureaucrat jim("Jim", 151);
        std::cout << jim << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "---------------------------------------------" << std::endl;
    
    try {
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;
        alice.decrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

// the object is created one throw is called, then the fisrt block of 
// catch took it, if it match their type.