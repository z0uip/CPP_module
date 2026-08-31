#include "dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "A dog is born !" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "A dog has died..." << std::endl;
	delete this->brain;
}

void Dog::makeSound(void) const
{
	std::cout << "The dog barked" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called !" << std::endl;
	this->brain = new Brain(*other.brain);
}

std::string Dog::getIdea(int index) const
{
	return this->brain->ideas[index];
}

void Dog::setIdea(int index, std::string const & idea)
{
	this->brain->ideas[index] = idea;
}