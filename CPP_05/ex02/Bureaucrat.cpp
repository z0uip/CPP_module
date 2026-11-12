#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade <= 0)
		throw GradeTooHighException();
	std::cout << "Default constructor has been called !" << std::endl;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	if (other.grade > 150)
		throw GradeTooLowException();
	else if (other.grade <= 0)
		throw GradeTooHighException();
	std::cout << "Copy constructor has been called !" << std::endl;
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Default destructor has been called !" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

void Bureaucrat::increaseGrade()
{
	if (grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	std::cout << this->name << " has been promoted to #" << this->grade << " !" << std::endl;
}

void Bureaucrat::decreaseGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	std::cout << this->name << " has been demoted to #" << this->grade << " !" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Unvalid grade, is Top 1 not enough ?");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("I'm sorry you're already the last one, but you can still rise !");
}

void Bureaucrat::signForm(AForm& Aform)
{
	try
	{
		Aform.beSigned(*this);
		std::cout << this->name << " signed " << Aform.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << Aform.getName()
			<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}