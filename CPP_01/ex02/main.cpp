#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = *stringPTR;

	std::cout << "The address of the string ->" << &str << std::endl;
	printf("The addres hold by stringPTR -> %p\n", &stringPTR);
	printf("The adress hold by stringREF -> %p\n", &stringREF);

	std::cout << "The value of the string ->" << str << std::endl;
	std::cout << "The value of stringPTR ->" << (*stringPTR) << std::endl;
	std::cout << "the value of stringREF ->" << stringREF << std::endl;
}