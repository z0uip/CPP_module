#include "Form.hpp"

int main()
{
	std::cout << "----- Test 1: valid Bureaucrat and Form -----" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 10);
		std::cout << boss << std::endl;

		Form f1(20, 20, "Vacation Request");
		std::cout << f1.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 2: Bureaucrat grade too high (0) -----" << std::endl;
	try
	{
		Bureaucrat b2("Paul", 0);
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 3: Bureaucrat grade too low (151) -----" << std::endl;
	try
	{
		Bureaucrat b3("Marie", 151);
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 4: beSigned() called directly, grade high enough -----" << std::endl;
	try
	{
		Bureaucrat director("Director", 5);
		Form f4(20, 20, "Budget Approval");
		f4.beSigned(director);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 5: beSigned() called directly, grade too low -----" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form f5(5, 5, "Confidential Report");
		f5.beSigned(intern);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 6: Bureaucrat::signForm() success -----" << std::endl;
	try
	{
		Bureaucrat manager("Manager", 15);
		Form f6(30, 30, "Expense Report");
		manager.signForm(f6);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 7: Bureaucrat::signForm() failure -----" << std::endl;
	try
	{
		Bureaucrat junior("Junior", 120);
		Form f7(10, 10, "Top Secret");
		junior.signForm(f7);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 8: Form copy constructor -----" << std::endl;
	try
	{
		Form original(40, 40, "Original");
		Form copy(original);
		std::cout << copy.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 9: Form operator= -----" << std::endl;
	try
	{
		Form a(40, 40, "FormA");
		Form b(60, 60, "FormB");
		b = a;
		std::cout << b.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}