#include "headers/Bureaucrat.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"
#include "headers/Intern.hpp"

int main()
{
    try {
        Intern someRandomIntern;
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 50);

        //Create forms via the intern
        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");

        //Invalid form
        AForm* formInvalid = someRandomIntern.makeForm("invalid form", "Nobody");

        std::cout << std::endl;

        if (form1) std::cout << *form1 << std::endl;
        if (form2) std::cout << *form2 << std::endl;
        if (form3) std::cout << *form3 << std::endl;

        std::cout << std::endl;

        //signing forms
        if (form1) bob.signForm(*form1);
        if (form2) bob.signForm(*form2);
        if (form3) alice.signForm(*form3);

        std::cout << std::endl;

        //Execute forms
        if (form1) alice.excdecuteForm(*form1);
        if (form2) alice.executeForm(*form2);
        if (form3) alice.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
        delete formInvalid;

    } 
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
