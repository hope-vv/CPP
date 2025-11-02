#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"
class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		const std::string &getName() const;
		int getGrade() const;

		// void setName(std:: string const &name);
		void setGrade(int grade);
		
		void incrementGrade();
		void decrementGrade();

		void signForm(Form &other);

		class GradeTooHighExsception : public std::exception{
			virtual const char *what() const throw();
		};
		class GradeTooLowExsception : public std::exception{
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &b);

#endif

// the throw: an exception specification, it tells the compiler this funciton will not throw any exceptions (it will not do anything unless you call it)