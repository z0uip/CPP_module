#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "The zombie named " << name << " has been deleted." << std::endl;
}

Zombie::Zombie(void)
{
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}