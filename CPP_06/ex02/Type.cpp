#include "Type.hpp"

Base::~Base(void)
{
	std::cout << "Destructor called !" << std::endl;
}

Base *generate(void)
{
	int rdm = std::rand() % 3; 
	if (rdm == 0)
		return new A();
	else if (rdm -= 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Unvalid Type !" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch (...) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch (...) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch (...) {}
}