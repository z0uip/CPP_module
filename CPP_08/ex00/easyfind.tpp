#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();

	while (it != ite)
	{
		if (*it == n)
			return it;
		it++;
	}
	throw runtime_error();
}
