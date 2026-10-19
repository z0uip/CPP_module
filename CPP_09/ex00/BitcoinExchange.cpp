#include "BitcoinExchange.hpp"

bool is_parsed(std::string line)
{
	std::string value;
	size_t i = 0;

	if (line.empty())
		return (false);
	while (isdigit(line[i]))
		i++;
	if (i != 4 || line[i] != '-')
		return (false);
	while (isdigit(line[i]))
		i++;
	if (i != 7 || line[i] != '-')
		return (false);
	while (isdigit(line[i]))
		i++;
	if (i != 10 || line[i] != ' ' || line[i + 1] != '|' || line[i + 2] == ' ')
		return (false);
	for (int n = 4; (line[i] && n > 0); n--)
	{
		if (!isdigit(line[i]))
			return false ;
		value += line[i];
		i++;
	}
	/*check avec atoi si ca depasse pas 1000, appel de fonction avec la class info, return true*/
}

void Info::setDate(std::string date)
{
	_date = date;
}

void Info::setValue(size_t value)
{
	_value = value;
}

std::string Info::getDate()
{
	return (_date);
}

size_t Info::getValue()
{
	return (_value);
}