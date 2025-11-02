#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	public:
		AForm();
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

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

		class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream& os, const AForm &b);

#endif
