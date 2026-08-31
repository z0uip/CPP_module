#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap nasus("Nasus");
	ScavTrap mundo("Mundo");
	FragTrap Jhin("Jhin");
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
	mundo.beRepaired(1);
	mundo.guardGate();
	mundo.attack("azir");
	mundo.attack("azir");
	mundo.attack("azir");
	mundo.attack("azir");
	mundo.attack("azir");
	mundo.attack("azir");
	mundo.attack("azir");
	mundo.takeDamage(5);
	mundo.takeDamage(5);
	mundo.takeDamage(5);
	mundo.beRepaired(10);
	mundo.guardGate();
	Jhin.highFivesGuys();
	return (0);
}
