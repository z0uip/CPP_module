#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "----- Test 1: ShrubberyCreationForm, sign + execute success -----" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 140);
		ShrubberyCreationForm shrub("home");

		gardener.signForm(shrub);
		gardener.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 2: execute without signing (should fail) -----" << std::endl;
	try
	{
		Bureaucrat gardener2("Gardener2", 140);
		ShrubberyCreationForm shrub2("garden");

		gardener2.executeForm(shrub2); // not signed yet
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 3: RobotomyRequestForm, sign + execute -----" << std::endl;
	try
	{
		Bureaucrat surgeon("Surgeon", 40);
		RobotomyRequestForm robo("Bender");

		surgeon.signForm(robo);
		surgeon.executeForm(robo);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 4: PresidentialPardonForm, sign + execute -----" << std::endl;
	try
	{
		Bureaucrat president("President", 3);
		PresidentialPardonForm pardon("Fry");

		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 5: sign fails, grade too low -----" << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 150);
		RobotomyRequestForm robo2("Zoidberg");

		lowGrade.signForm(robo2); // grade 150 > required 72, should fail
		lowGrade.executeForm(robo2); // should also fail, not signed
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 6: signed but grade too low to execute -----" << std::endl;
	try
	{
		Bureaucrat justEnoughToSign("JustEnough", 25);
		PresidentialPardonForm pardon2("Leela");

		justEnoughToSign.signForm(pardon2); // sign requires 25, ok
		justEnoughToSign.executeForm(pardon2); // execute requires 5, 25 is too low
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}