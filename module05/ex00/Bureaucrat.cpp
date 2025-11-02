#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout << "Bureaucrat Default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    std::cout << "Bureaucrat constructor customized" << std::endl;
    if (grade < 1)
        throw GradeTooHighExsception();
    else if (grade > 150)
        throw GradeTooLowExsception();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()) {
    std::cout << "Bureaucrat copy constructor" << std::endl;
    *this = other;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Default destructor" << std::endl;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other)
        this->grade = other.getGrade();
    std::cout << "Bureaucrat Copy assignment operator" << std::endl;
    return (*this);
}

const std::string &Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::setGrade(int grade){
    if (grade < 1)
        throw GradeTooHighExsception();
    else if (grade > 150)
        throw GradeTooLowExsception();
    this->grade = grade;
}

void Bureaucrat::incrementGrade(){
    if (this->grade <= 1)
        throw GradeTooHighExsception();
    --this->grade;
}

void Bureaucrat::decrementGrade(){
    if (this->grade >= 150)
        throw GradeTooLowExsception();
    ++this->grade;
}

const char *Bureaucrat::GradeTooHighExsception::what() const throw() {
    return "Grade too hight !!";
}

const char *Bureaucrat::GradeTooLowExsception::what() const throw() {
    return "Grade too low !!";
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &b){
    os << b.getName() << ">, bureaucrat grade " << b.getGrade();
    return os;
}