#include "Zombie.hpp"


Zombie::~Zombie(void)
{
	std::cout << "The zombie named " << name << " has been deleted." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}