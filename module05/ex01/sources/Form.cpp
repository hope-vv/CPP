#include "../headers/Form.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}


Form::Form(const std::string &name, int sign, int execute)
	: name(name), isSigned(false), signGrade(sign), executeGrade(execute)
{
	std::cout << "Form constructor customized" << std::endl;
    if (sign < 1 || execute < 1)
        throw GradeTooHighException();
    else if (sign > 150 || execute > 150)
        throw GradeTooLowException();
}

const std::string &Form::getName() const { return this->name; }
int Form::getSignedGrade() const { return signGrade; }
int Form::getExecuteGrade() const { return executeGrade; }
bool Form::getIsSigned() const { return isSigned; }

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low!";
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}
std::ostream& operator<<(std::ostream &out, const Form &f) {
    out << "Form: " << f.getName()
        << ", signed: " << (f.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << f.getSignedGrade()
        << ", grade required to execute: " << f.getExecuteGrade();
    return out;
}
