#include "Scalar.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called !" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Default destructor called !" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	std::cout << "Default construcor called !" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	std::cout << "Copy constructor called !" << std::endl;
	return (*this);
}

void ScalarConverter::convert(const std::string input)
{
	if (input.length() == 0)
	{
		std::cout << "Unvalid input !" << std::endl;
		return ;
	}
	else if (input.length() == 1)
	{
		if (isprint(input[0]) && !isdigit(input[0]))
			std::cout << "Char : " << input << std::endl;
		else if (isdigit(input[0]))
			std::cout << "Int : " << input << std::endl;
		else
		{
			std::cout << "Invalid input !" << std::endl;
			return ;
		}
	}
	else if (is_char(input))
		return  ;
	else if (isFloat(input))
	{
		std::cout << "Float : " << atof(input.c_str()) << std::endl;
		return ;
	}
	else if (isDouble(input))
	{
		std::cout << "Double : " << strtod(input.c_str(), NULL) << std::endl;
		return ;
	}
	else if (is_int(input))
		return ;
	else
		std::cout << "Invlid input !" << std::endl;
}

bool is_char(std::string input)
{
	int i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
		{
			if (input[i + 2] == '\'')
			{
				std::cout << "Char : " << input[i + 1] << std::endl;
				return (true);
			}
			else
				return (false);
		}
		i++;
	}
	return (false);
}

bool isFloat(const std::string& input)
{
    return !input.empty() && input[input.size() - 1] == 'f' 
           && (input.find('.') != std::string::npos 
               || input.find("inff") != std::string::npos 
               || input.find("nanf") != std::string::npos);
}

bool is_int(std::string input)
{
	int i = 0;
	while (input[i])
	{
		if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != ' ')
			return (false);
		i++;
	}
	long long test = atoll(input.c_str());
	if (test > 2147483647 || test < -2147483648)
		return (false);
	int res = atoi(input.c_str());
	if (res == 0)
	{
		int i = 0;
		while (input[i] == '+' || input[i] == '-' || input[i] == ' ')
			i++;
		if (input[i] != '0')
			return (false);
		else
		{
			std::cout << "Int : 0" << std::endl;
			return (true);
		}
	}
	std::cout << "Int : " << res << std::endl;
	return (true);
}

bool isDouble(const std::string& input)
{
    return input.find("inf") != std::string::npos || ((!input.empty() && (input[input.size() - 1] != 'f' && (input.find('.') != std::string::npos))) || input.find("nan") != std::string::npos);
}