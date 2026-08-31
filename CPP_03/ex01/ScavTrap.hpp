#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private :
		bool gatemode;
	public :
		void guardGate(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
};