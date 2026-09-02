#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int n);

class runtime_error : public std::exception
{
	const char* what() const throw()
	{
		return ("not found");
	}
};

#include "easyfind.tpp"

#endif