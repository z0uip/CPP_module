#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Span
{
	private :
		unsigned int _n;
		std::list<int> _span;
	public :
		Span(int n);
		void addNumber(int num);
		void addRange(std::list<int>::iterator begin, std::list<int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		class error : public std::exception
		{
			const char* what() const throw()
			{
				return ("An erroc occured");
			};
		};
};

#endif