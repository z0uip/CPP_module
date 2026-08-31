#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "idwtstwof.hpp"
#include <iostream>
#include <string>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		virtual ~Animal();
		virtual void makeSound(void) const;
		std::string const & getType(void) const;
};

#endif