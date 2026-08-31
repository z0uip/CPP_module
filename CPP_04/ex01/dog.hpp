#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "idwtstwof.hpp"

class Dog : public Animal
{
	private :
		Brain *brain;
	public :
		Dog();
		~Dog();
		Dog(const Dog& other);
		virtual void makeSound(void) const;
		std::string getIdea(int index) const;
		void setIdea(int index, std::string const & idea);
		Dog& operator=(const Dog& other);
		virtual void makeSound(void) const;
};

#endif