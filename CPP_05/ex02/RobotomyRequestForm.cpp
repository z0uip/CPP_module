#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib> 
#include <fstream>

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > 45)
		throw AForm::GradeTooLowException();
	std::cout << "Brrrrrrrrrrrrrrrrrrrrrrr..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been robotomized succesfully !" << std::endl;
	else
		std::cout << "Robotomy failed for " << this->target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :  AForm(72, 45, "RobotomyRequestForm"), target(target)
{
	std::cout << "Default constructor called !" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Default destructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(72, 45, "RobotomyRequestForm"), target(other.target)
{
	std::cout << "Copy constructor called !" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return *this;
}