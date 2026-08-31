#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>

class Zombie
{
	private :
	
	std::string name;
	
	public :
	
	~Zombie();
	Zombie(std::string name);
	
	void announce(void)
	{
		std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
	}
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);