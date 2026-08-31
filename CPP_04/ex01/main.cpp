#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{	
	Dog a;
	a.setIdea(0, "I love bones");

	Dog b(a);

	std::cout << "a: " << a.getIdea(0) << std::endl;
	std::cout << "b: " << b.getIdea(0) << std::endl;

	a.setIdea(0, "I hate cats");

	std::cout << "--- apres modif de a ---" << std::endl;
	std::cout << "a: " << a.getIdea(0) << std::endl;
	std::cout << "b: " << b.getIdea(0) << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	return 0;
}
