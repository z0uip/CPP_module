#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	std::string filename (av[1]);
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		/*fontion de parsing si retourne false break;*/
	}
}