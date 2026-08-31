#include "Harl.hpp"

void comments::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void comments::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void comments::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void comments::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void comments::complain(std::string level)
{
	comments Com;

	int index = atoi(level.c_str());
	if (index >= 0 && index <= 3)
	{
		void (comments::*tab[4])() = {&comments::debug, &comments::error, &comments::info, &comments::warning};
		(Com.*tab[index])();
	}
	else
		std::cout << "Index must be a nomber between 0 and 3." << std::endl;
	return ;
}