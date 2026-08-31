#include "dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "A dog is born !" << std::endl;
	this->type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "A dog has died..." << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "The dog barked" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called !" << std::endl;
	this->type = other.type;
}