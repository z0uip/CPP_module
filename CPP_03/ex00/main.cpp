#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap nasus("Nasus");
	nasus.beRepaired(1);
	nasus.attack("azir");
	nasus.attack("azir");
	nasus.attack("azir");
	nasus.attack("azir");
	nasus.attack("azir");
	nasus.attack("azir");
	nasus.attack("azir");
	nasus.takeDamage(5);
	nasus.takeDamage(5);
	nasus.takeDamage(5);
	nasus.beRepaired(10);
	return (0);
}
