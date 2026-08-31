#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1;
	Zombie *zombie2;
    
    zombie1 = newZombie("nithomas");
    zombie2 = newZombie("ytennah");
	zombie1->announce();
	zombie2->announce();
	randomChump("yderridj");
	randomChump("hoel le goat");

	delete zombie1;
	delete zombie2;
	return (0);
}