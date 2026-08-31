#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"

class Cat : public Animal
{
	public :
		~Cat();
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual  void makeSound(void) const;
};

#endif