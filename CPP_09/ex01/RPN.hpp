#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class Ope
{
	private :
		std::stack<long> _digit;
	public :
		void addDigit(int newd);
		int getDigit();
		size_t size() const;
		bool execute(const std::string &line);
		bool error() const;
		Ope();
		Ope(const Ope &other);
		Ope &operator=(const Ope &other);
		~Ope();
};

bool parsing(const std::string &line);

#endif