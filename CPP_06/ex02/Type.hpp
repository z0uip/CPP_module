#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <stdint.h>

class Base
{
	public :
		virtual ~Base(void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif