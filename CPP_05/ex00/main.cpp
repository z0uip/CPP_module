#include "Bureaucrat.hpp"

int main()
{
	std::cout << "----- Test 1: valid bureaucrat -----" << std::endl;
	try
	{
		Bureaucrat b1("Jean", 50);
		std::cout << b1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 2: grade too high (0) -----" << std::endl;
	try
	{
		Bureaucrat b2("Paul", 0);
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 3: grade too low (151) -----" << std::endl;
	try
	{
		Bureaucrat b3("Marie", 151);
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 4: boundaries (1 and 150) -----" << std::endl;
	try
	{
		Bureaucrat b4("Alice", 1);
		Bureaucrat b5("Bob", 150);
		std::cout << b4 << std::endl;
		std::cout << b5 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 5: increaseGrade beyond limit -----" << std::endl;
	try
	{
		Bureaucrat b6("Charlie", 1);
		std::cout << b6 << std::endl;
		b6.increaseGrade(); // should throw, grade already 1 (highest)
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 6: decreaseGrade beyond limit -----" << std::endl;
	try
	{
		Bureaucrat b7("David", 150);
		std::cout << b7 << std::endl;
		b7.decreaseGrade(); // should throw, grade already 150 (lowest)
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 7: normal increase/decrease -----" << std::endl;
	try
	{
		Bureaucrat b8("Eve", 50);
		std::cout << b8 << std::endl;
		b8.increaseGrade();
		std::cout << b8 << std::endl;
		b8.decreaseGrade();
		std::cout << b8 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n----- Test 8: copy constructor & operator= -----" << std::endl;
	try
	{
		Bureaucrat b9("Frank", 30);
		Bureaucrat b10(b9); // copy constructor
		std::cout << b10 << std::endl;

		Bureaucrat b11("Grace", 60);
		b11 = b9; // operator=, name of b11 should stay "Grace", grade becomes 30
		std::cout << b11 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}