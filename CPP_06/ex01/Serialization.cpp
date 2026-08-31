#include "Serialization.hpp"
#include <iostream>
#include <stdint.h>

Serializer::Serializer(void)
{
	std::cout << "Default constructor called !" << std::endl;
}

Serializer::~Serializer(void)
{
	std::cout << "Default destructor called !" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
	std::cout << "Default construcor called !" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	std::cout << "Copy constructor called !" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}