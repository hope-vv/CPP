#include "../headers/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((target + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
        return;
    }

    ofs << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\\" << std::endl;

    ofs.close();
}

// << operator
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
    out << "Form: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", Grade to sign: " << form.getSignedGrade()
        << ", Grade to execute: " << form.getExecuteGrade()
        << ", Target: " << form.getTarget();
    return out;
}


std::string ShrubberyCreationForm::getTarget() const { return target; }

