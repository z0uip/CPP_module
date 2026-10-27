#ifndef RPN_HPP
#define RPN_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <map>

class Ope
{
	private :
		std::stack<int> _digit;
	public :
		void addDigit(int newd);
		int getDigit();
		size_t size() const
};

bool parsing(const std::string &line);

#endif