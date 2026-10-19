#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>

class Info
{
	private :
		std::string _date;
		size_t _value;
	public :
		std::string getDate();
		size_t getValue();
		void setDate(std::string date);
		void setValue(size_t value);
};

#endif