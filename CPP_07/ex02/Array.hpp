#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>

template <typename T> 
class Array
{
	private :
		unsigned int _size;
		T *_array;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array & other);
		Array &operator=(const Array& other);
		const T& operator[](const int index) const;
		T& operator[](const int index);
		~Array();
		class out_of_bounds : public std::exception
		{
			public :
				const char* what() const throw()
                {
                    return ("Index out of bounds");
                }
		};
		unsigned int size() const;
};

#include "Array.tpp"

#endif