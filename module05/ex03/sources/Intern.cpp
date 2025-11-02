#include "../headers/Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other) { *this = other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

AForm* Intern::createShrubbery(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }

    std::cerr << "Error: Form \"" << formName << "\" does not exist!" << std::endl;
    return NULL;
}
