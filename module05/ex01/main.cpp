#include <iostream>
#include "headers/Bureaucrat.hpp"
#include "headers/Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 140);
        Form leaveForm("LeaveForm", 100, 50);
        Form secretForm("SecretForm", 30, 10);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << leaveForm << std::endl;
        std::cout << secretForm << std::endl;

        std::cout << "\n--- Trying to sign forms ---" << std::endl;

        bob.signForm(leaveForm);   // should succeed (50 <= 100)
        alice.signForm(leaveForm); // should fail (140 > 100)
        bob.signForm(secretForm);  // should fail (50 > 30)

        std::cout << "\n--- Final form states ---" << std::endl;
        std::cout << leaveForm << std::endl;
        std::cout << secretForm << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
