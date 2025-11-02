#include "headers/Bureaucrat.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"

int main()
{
    try {
        //bureaucrats
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        //forms
        ShrubberyCreationForm shrub("Home");//145, 137
        RobotomyRequestForm robot("Bender");//72, 45
        PresidentialPardonForm pardon("lina");//25, 5

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        //Bob sign forms
        bob.signForm(shrub);
        bob.signForm(robot);
        bob.signForm(pardon);

        //Alice signs forms
        alice.signForm(robot);
        alice.signForm(pardon);

        std::cout << "\nAfter signing:\n";
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        //Bob executes forms
        bob.executeForm(shrub);
        bob.executeForm(robot);
        bob.executeForm(pardon);

        //Alice executes forms
        alice.executeForm(robot);  
        alice.executeForm(pardon);

    } 
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
