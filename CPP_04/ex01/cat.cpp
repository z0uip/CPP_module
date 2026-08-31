#include "cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "A cat is born !" << std::endl;
	this->type = "Cat";
	this->brain	= new Brain();
}

Cat::~Cat(void)
{
	std::cout << "A cat has passed away..." << std::endl;
	delete this->brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called !" << std::endl;
	this->brain = new Brain(*other.brain);
}

std::string Cat::getIdea(int index) const
{
	return this->brain->ideas[index];
}

void Cat::setIdea(int index, std::string const & idea)
{
	this->brain->ideas[index] = idea;
}