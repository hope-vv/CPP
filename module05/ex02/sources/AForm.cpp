#include "../headers/AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm()
{}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}


AForm::AForm(const std::string &name, int sign, int execute)
	: name(name), isSigned(false), signGrade(sign), executeGrade(execute)
{
	std::cout << "AForm constructor customized" << std::endl;
    if (sign < 1 || execute < 1)
        throw GradeTooHighException();
    else if (sign > 150 || execute > 150)
        throw GradeTooLowException();
}

const std::string &AForm::getName() const { return this->name; }
int AForm::getSignedGrade() const { return signGrade; }
int AForm::getExecuteGrade() const { return executeGrade; }
bool AForm::getIsSigned() const { return isSigned; }

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade is too low!";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm: form is not signed!";
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}
std::ostream& operator<<(std::ostream &out, const AForm &f) {
    out << "AForm: " << f.getName()
        << ", signed: " << (f.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << f.getSignedGrade()
        << ", grade required to execute: " << f.getExecuteGrade();
    return out;
}
