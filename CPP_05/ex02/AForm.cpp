#include "AForm.hpp"


const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Unvalid grade !");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Unvalid grade !");
}

AForm::AForm(int gsign, int gexe, std::string name)
	: name(name), issigned(false), gsign(gsign), gexe(gexe)
{
	std::cout << "Default constructor called !" << std::endl;
}

AForm::AForm(const AForm& other)
	: name(other.name), gsign(other.gsign), gexe(other.gexe) 
{
	if (this != &other)
		issigned = false;
	std::cout << "Copy constucor called !" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Default destructor called !" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->issigned = false;
	return *this;
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->gsign)
		throw AForm::GradeTooLowException();
	this->issigned = true;
}

const std::string AForm::getName() const
{
	return(this->name);
}

bool AForm::getIsSigned() const
{
	return (this->issigned);
}