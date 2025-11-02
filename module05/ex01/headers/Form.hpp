#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	public:
		Form();
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string &getName() const;
		int getSignedGrade() const;
		int getExecuteGrade() const;
		bool getIsSigned() const;

		class GradeTooHighException : public std::exception{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream& os, const Form &b);

#endif


// const std::string name → the form’s name (can’t be changed).
// bool isSigned → whether the form is signed, defaults to false.
// const int gradeToSign → minimum grade required to sign.
// const int gradeToExecute → minimum grade required to execute.

// Executing a form means actually performing the action that the form represents.
// Example: if it’s a “ShrubberyCreationForm,” executing it might create a file with ASCII trees