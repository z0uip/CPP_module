#include "Harl.hpp"

bool str_is_allnum(std::string str)
{
	size_t i = 0;

	while (str[i])
	{
		if (isdigit(str[i]))
			i++;
		else
			return (false);
	}
	return (true);
}