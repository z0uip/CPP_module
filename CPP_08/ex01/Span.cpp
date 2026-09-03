#include "Span.hpp"

Span::Span(int n)
{
	_n = n;
}

void Span::addNumber(int num)
{
	if (_span.size() >= _n)
		throw(Span::error());
	_span.push_back(num);
}

void Span::addRange(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	for (;begin != end; begin++)
		addNumber(*begin);
}

unsigned int Span::shortestSpan()
{
	if (_span.size() <= 1)
		throw(Span::error());
	std::size_t v1;
	std::size_t v2;
	std::list<int> temp = _span;
	temp.sort();
	v1 = *temp.begin();
	v2 = *++temp.begin();
	return (v2 - v1);
}

unsigned int Span::longestSpan()
{
	if (_span.size() <= 1)
		throw(Span::error());
	std::size_t v1;
	std::size_t v2;
	std::list<int> temp = _span;
	temp.sort();
	v1 = *temp.begin();
	v2 = temp.back();
	return (v2 - v1);
}