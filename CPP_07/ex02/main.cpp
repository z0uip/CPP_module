#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "=== Test 1 : constructeur par defaut ===" << std::endl;
	Array<int> empty;
	std::cout << "size = " << empty.size() << std::endl;

	std::cout << "\n=== Test 2 : constructeur avec n elements ===" << std::endl;
	Array<int> a(5);
	std::cout << "size = " << a.size() << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	std::cout << "\n=== Test 3 : constructeur par copie ===" << std::endl;
	Array<int> b(a);
	b[0] = 999;
	std::cout << "a[0] = " << a[0] << " (ne doit PAS changer)" << std::endl;
	std::cout << "b[0] = " << b[0] << " (doit valoir 999)" << std::endl;

	std::cout << "\n=== Test 4 : operator= ===" << std::endl;
	Array<int> c;
	c = a;
	c[1] = 777;
	std::cout << "a[1] = " << a[1] << " (ne doit PAS changer)" << std::endl;
	std::cout << "c[1] = " << c[1] << " (doit valoir 777)" << std::endl;

	std::cout << "\n=== Test 5 : version const de operator[] ===" << std::endl;
	const Array<int> constArr(a);
	std::cout << "constArr[2] = " << constArr[2] << std::endl;
	// constArr[2] = 42; // <- decommenter : doit provoquer une erreur de compilation

	std::cout << "\n=== Test 6 : exception hors limites ===" << std::endl;
	try
	{
		std::cout << a[100] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	try
	{
		const Array<int> & ref = constArr;
		std::cout << ref[42] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << "Exception attrapee (const) : " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7 : fonctionne avec un autre type (string) ===" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "hello";
	strArr[1] = "world";
	strArr[2] = "42";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;

	std::cout << "\n=== Test 8 : Array vide, verifier acces hors limites ===" << std::endl;
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n=== Fin des tests ===" << std::endl;
	return 0;
}