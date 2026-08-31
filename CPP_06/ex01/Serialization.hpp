#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <stdint.h>

typedef struct sData
{
	int a;
}Data;

class Serializer
{
    public:
		Serializer(void);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer(void);

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif