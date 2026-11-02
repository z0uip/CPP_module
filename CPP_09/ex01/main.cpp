#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	Ope ope;
	if (!ope.execute(av[1]))
		return (1);
	return (0);
}