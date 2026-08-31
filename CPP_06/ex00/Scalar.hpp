#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

class ScalarConverter
{
	public :
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter& other);
		void convert(std::string input);
};

bool	is_char(std::string input);
bool	isFloat(const std::string& input);
bool	is_int(std::string input);
bool	isDouble(const std::string& input);

#endif