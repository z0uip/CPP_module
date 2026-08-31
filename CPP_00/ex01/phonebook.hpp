#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>

int		is_digit_or_spaces(std::string str);
void	print_in_columns(std::string str);

class Contact
{
	private :

	std::string first_name;
	std::string last_name;
	std::string phone_n;
	std::string nickname;
	std::string darkestsecret;

	public :

	void set_first_name(std::string str)
	{
		first_name = str;
	}

	void set_last_name(std::string str)
	{
		last_name = str;
	}

	int set_phone_n(std::string number)
	{
		if (is_digit_or_spaces(number))
		{
			phone_n = number;
			return (1);
		}
		std::cout << "Phone number must only contain digits." << std::endl;
		return (0);
	}

	void set_nickname(std::string str)
	{
		nickname = str;
	}
	
	void set_darkest_secret(std::string str)
	{
		darkestsecret = str;
	}
	
	std::string get_f_name(void)
	{
		return (first_name);
	}
	
	std::string get_l_name(void)
	{
		return (last_name);
	}
	
	std::string get_n_name(void)
	{
		return (nickname);
	}
};
