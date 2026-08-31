#include "cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "A cat is born !" << std::endl;
	this->type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "A cat has passed away..." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called !" << std::endl;
	this->type = other.type;
}