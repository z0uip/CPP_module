#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "----- Test 1: Intern creates a RobotomyRequestForm -----" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");

		if (rrf)
		{
			Bureaucrat surgeon("Surgeon", 40);
			surgeon.signForm(*rrf);
			surgeon.executeForm(*rrf);
			delete rrf;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 2: Intern creates a ShrubberyCreationForm -----" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* shrub = someRandomIntern.makeForm("ShrubberyCreationForm", "home");

		if (shrub)
		{
			Bureaucrat gardener("Gardener", 100);
			gardener.signForm(*shrub);
			gardener.executeForm(*shrub);
			delete shrub;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 3: Intern creates a PresidentialPardonForm -----" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* pardon = someRandomIntern.makeForm("PresidentialPardonForm", "Fry");

		if (pardon)
		{
			Bureaucrat president("President", 3);
			president.signForm(*pardon);
			president.executeForm(*pardon);
			delete pardon;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 4: Intern tries to create an invalid form name -----" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* invalid = someRandomIntern.makeForm("BaguetteForm", "France");

		if (invalid)
			delete invalid;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 5: Intern copy constructor & operator= -----" << std::endl;
	try
	{
		Intern original;
		Intern copy(original);
		Intern assigned;
		assigned = original;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}