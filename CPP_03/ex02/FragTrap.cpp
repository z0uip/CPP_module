#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " has accpeted a High Five request !" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	std::cout << "FragTrap " << this->name << " has been created !" << std::endl;
	this->ad = 30;
	this->hp = 100;
	this->mana = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " has been destroyed !" << std::endl;
}