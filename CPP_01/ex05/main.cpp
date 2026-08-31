#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		comments Com;
		if (str_is_allnum(av[1]) == true)
		{
			Com.complain(av[1]);
			return (0);
		}
	}
	std::cerr << "Unvalid input !" <<  std::endl;
	return (1);
}