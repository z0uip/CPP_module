#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename F>
void iter(T array[], const int length, F func)
{
	int i = 0;
	while (i < length)
	{
		func(array[i]);
		i++;
	}
}

#endif