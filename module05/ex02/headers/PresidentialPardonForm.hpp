#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
		// Bureaucrat &target;
	public:
		PresidentialPardonForm(const std::string & target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

        virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

std::ostream &operator<<(std::ostream & o, PresidentialPardonForm const &form);


#endif
