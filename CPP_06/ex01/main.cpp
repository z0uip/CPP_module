#include "Serialization.hpp"

 
int main(void)
{
	Data original;
 
	original.a = 42;
 
	std::cout << "Original address : " << &original << std::endl;
 
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized value : " << raw << std::endl;
 
	Data *recovered = Serializer::deserialize(raw);
	std::cout << "Deserialized address : " << recovered << std::endl;
 
	if (&original == recovered)
		std::cout << "OK : same address, no data lost !" << std::endl;
	else
		std::cout << "KO : addresses differ !" << std::endl;
	return (0);
}