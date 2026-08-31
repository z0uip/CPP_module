#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "idwtstwof.hpp"

class Cat : public Animal
{
	private :
		Brain *brain;
	public :
		~Cat();
		Cat(void);
		Cat(const Cat& other);
		virtual  void makeSound(void) const;
		Cat& operator=(const Cat& other);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string const & idea);
};

#endif