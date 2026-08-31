#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > 5)
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardonned by Zaphod Beeblebrox !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  AForm(72, 45, "PresidentialPardonForm"), target(target)
{
	std::cout << "Default constructor called !" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Default destructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(72, 45, "PresidentialPardonForm"), target(other.target)
{
	std::cout << "Copy constructor called !" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return *this;
}