#include "sed_is_for_loosers.hpp"

int main(int ac, char **av)
{
	std::string outfile(av[1]);
	std::string paste;
	if (ac == 4)
	{
		paste = open_and_return_file(av[1], av[2], av[3]);
		if (paste.empty())
			return (1);
		outfile += ".replace";
		paste_in_file(outfile, paste);
		std::cout << "Content has been paste." << std::endl;
		return (0);
	}
	else
	{
		std::cout << "Please gave as agrument a file and two strings" << std::endl;
		return (1);
	}
}