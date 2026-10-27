#include "RPN.hpp"

int main (int ac, char **av)
{
	std::string line = av[1];
	if (ac >= 16)
		return (std::cout << "Error: too much number" << std::endl, 1);
	if (parsing(line))
		std::cout << "c'est tout bon" << std::endl;
	else
		std::cout << "pas bon" << std::endl;
}