#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>


class ClapTrap
{
	protected :
		std::string name;
		size_t hp;
		size_t mana;
		size_t ad;
	
	public :
		ClapTrap(std::string name);
		~ClapTrap(void);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif