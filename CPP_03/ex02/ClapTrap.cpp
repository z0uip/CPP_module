#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor has been called !" << std::endl;
	this->name = name;
	this->ad = 2;
	this->hp = 10;
	this->mana = 5;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " has been destroyed !" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hp > 0 && this->mana > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->ad << " points of damages !" << std::endl;
		this->mana--;
		if (this->mana <= 0)
			std::cout << "ClapTrap " << this->name << " used all his/her mana !" << std::endl;
	}
	else
	{
		if (this->hp <= 0)
			std::cout << "ClapTrap" << this->name << " is dead !" << std::endl;
		else
			std::cout << "ClapTrap" << this->name << " has no mana, " << this->name << " can't attack !" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp > 0)
	{
		std::cout << this->name << " has taken " << amount << " damages points !" << std::endl;
		this->hp -= amount;
		if (this->hp <= 0)
			std::cout << "ClapTrap " << this->name << " has been slained !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " is already dead !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->mana > 0)
	{
		std::cout << "ClapTrap " << this->name << " has been repaired and gained " << amount << " hp !" << std::endl;
		this->hp += amount;
		this->mana--;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no more mana !" << std::endl;
}