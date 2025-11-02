#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) 
{
    srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
        target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::cout << "Bzzzz... drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
    out << "Form: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", Grade to sign: " << form.getSignedGrade()
        << ", Grade to execute: " << form.getExecuteGrade()
        << ", Target: " << form.getTarget();
    return out;
}

std::string RobotomyRequestForm::getTarget() const { return target; }
