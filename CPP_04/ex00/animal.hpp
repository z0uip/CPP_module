#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual void makeSound(void) const;
		std::string const & getType(void) const;
};

#endif