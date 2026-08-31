#include "animal.hpp"

void Animal::makeSound(void) const
{
	std::cout << this->type << " is making a sound !" << std::endl;
}

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << type << " is born !" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << this->type << " has died..." << std::endl;
}

std::string const & Animal::getType(void) const
{
	return this->type;
}