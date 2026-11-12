#include "Form.hpp"


const char* Form::GradeTooLowException::what() const throw()
{
	return ("Unvalid grade !");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Unvalid grade !");
}

Form::Form(int gsign, int gexe, std::string name)
	: name(name), issigned(false), gsign(gsign), gexe(gexe)
{
	std::cout << "Default constructor called !" << std::endl;
}

Form::Form(const Form& other)
	: name(other.name), gsign(other.gsign), gexe(other.gexe) 
{
	if (this != &other)
		issigned = false;
	std::cout << "Copy constucor called !" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Default destructor called !" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->issigned = false;
	return *this;
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->gsign)
		throw Form::GradeTooLowException();
	this->issigned = true;
}

const std::string Form::getName()
{
	return(this->name);
}