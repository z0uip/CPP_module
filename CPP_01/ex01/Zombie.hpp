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
	Zombie();
	Zombie(std::string name);
	void set_name(std::string name);
	void announce(void);
};


Zombie *zombieHorde( int N, std::string name );