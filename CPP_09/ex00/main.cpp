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
	Info info;
	std::ifstream datafile("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open the data base." << std::endl;
		return (1);
	}
	std::map<std::string, double> db = getMap(datafile);
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (is_parsed(line, info))
			getResult(info, db);
	}
	return (1);
}