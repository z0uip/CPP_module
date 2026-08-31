#include "Zombie.hpp"

int main(void)
{
	int i = -1;
	Zombie *horde = zombieHorde(10, "Le Chef");
	while (++i < 10)
		horde[i].announce();
	delete[] horde;
	return 0;
}