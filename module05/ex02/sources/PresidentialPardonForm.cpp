#include "../headers/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm::AForm ("PresidentialPardon", 25, 5), target(target)
{
	// std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm::AForm(other), target(other.target)
{
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
        target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const { return target; }

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const &form) {
	o << "Form: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", Grade to sign: " << form.getSignedGrade()
        << ", Grade to execute: " << form.getExecuteGrade()
        << ", Target: " << form.getTarget();
	return o;
}
