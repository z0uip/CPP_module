#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{
    std::cout << "Default constructor has been called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Copy constructor has been called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
        std::cout << "Assignment operator has been called" << std::endl;
    return (*this);
}

Intern::~Intern(void)
{
    std::cout << "Destructor has been called" << std::endl;
}

AForm* Intern::makeForm(const std::string name, const std::string target) const
{
	if (name == "PresidentialPardonForm")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	}
	if (name == "RobotomyRequestForm")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	}
	if (name == "ShrubberyCreationForm")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	}
	throw Intern::InvalidForm();
}