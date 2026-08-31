#include "sed_is_for_loosers.hpp"

std::string open_and_return_file(char *filename, std::string s1, std::string s2)
{
	std::string		res;
	std::string		line;
	std::ifstream	file;
	std::string		content;
	std::size_t		end = 0;
	std::size_t		start = 0;

	file.open(filename);
	if (!file.is_open())
	{
		std::cerr << "Unvalid file name" << std::endl;
		return (content);
	}
	while (std::getline(file, line))
		content += line + "\n";
	content[content.size() - 1] = '\0';
	while ((end = content.find(s1, start)) != std::string::npos)
	{
		res += content.substr(start, end - start) + s2;
		start = end + s1.size();
	}
	res += "\n";
	file.close();
	return (res);
}