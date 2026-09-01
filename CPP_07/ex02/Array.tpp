#include "Array.hpp"

template <class T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <class T>
Array<T>::Array(void)
{
	_size = 0;
	_array = new T[0];
}

template <class T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[n];
} 

template <class T>
Array<T>::Array(const Array & other) : _size(other.size())
{
	unsigned int i = 0;
	_array = new T[_size];
	while (i < _size)
	{
		_array[i] = other._array[i];
		i++;
	}
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other.size();
		_array = new T[this->_size];
		unsigned int i = 0;
		while (i < _size)
		{
			_array[i] = other._array[i];
			i++;
		}
	}
    return (*this);
}

template <class T>
const T& Array<T>::operator[](const int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw(Array::out_of_bounds());
	return (_array[index]);
}

template <class T>
T& Array<T>::operator[](const int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw(Array::out_of_bounds());
	return (_array[index]);
}

template <class T>
Array<T>::~Array()
{
	delete[] _array;
}
