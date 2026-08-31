#include "ScavTrap.hpp"

void ScavTrap::guardGate(void)
{
	if (this->gatemode == false)
	{
		std::cout << "ScavTrap " << this->name << " has entered Gate keeper mode !" << std::endl;
		this->gatemode = true;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " has leaved Gate keeper mode !" << std::endl;
		this->gatemode = false;
	}
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " has been destroyed !" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " has been created !" << std::endl;
	this->name = name;
	this->ad = 10;
	this->mana = 5;
	this->hp = 10;
	this->gatemode = false;
}