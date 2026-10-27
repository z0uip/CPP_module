#include "RPN.hpp"

void execOpe(std::string line)
{
	size_t i = 0;
	while (line[i])
	{

	}
}

bool parsing(const std::string &line)
{
	size_t	i = 0;
	int		count = 0;

	while (i < line.size())
	{
		while (i < line.size() && std::isspace(static_cast<unsigned char>(line[i])))
			i++;
		if (i == line.size())
			break ;
		char c = line[i];
		// un token fait 1 caractère : il doit être suivi d'un espace ou de la fin
		if (i + 1 < line.size() && !std::isspace(static_cast<unsigned char>(line[i + 1])))
			return false;
		if (std::isdigit(static_cast<unsigned char>(c)))
			count++;
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (count < 2)
				return false;
			count--;
		}
		else
			return false;
		i++;
	}
	return (count == 1);
}

void Ope::addDigit(int newd)
{
	_digit.push(newd);
}

int Ope::getDigit()
{
	int top = _digit.top();
	_digit.pop();
	return top;
}

size_t Ope::size() const
{
	return _digit.size();
}