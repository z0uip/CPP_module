#include "phonebook.hpp"


void print_in_columns(std::string str)
{
	size_t spaces = 0;
	if (str.length() <= 10)
	{
		spaces = 10 - str.length();
		std::cout << str;
		while (spaces > 0)
		{
			std::cout << ' ';
			spaces--;
		}
		std::cout << "|";
	}
	else
		std::cout << str.substr(0, 9) + ".|";
}

int is_digit_or_spaces(std::string str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((!isdigit(str[i])) && (str[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}