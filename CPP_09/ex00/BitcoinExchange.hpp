#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

bool is_parsed(std::string line, Info &info);
std::map<std::string, double> getMap(std::ifstream &datafile);
void getResult(Info &info, std::map<std::string, double> &db);

class Info
{
	private :
		std::string _date;
		double _value;
	public :
		std::string getDate();
		double getValue();
		void setDate(std::string date);
		void setValue(double value);
};

#endif