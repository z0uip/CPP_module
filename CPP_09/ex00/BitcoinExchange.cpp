#include "BitcoinExchange.hpp"

bool is_parsed(std::string line, Info &info)
{
	std::string date;
	std::string value;
	size_t i = 0;

	if (line.empty())
	{
		std::cout << "Error: Empty line" << std::endl;
		return (false);
	}
	while (isdigit(line[i]))
		i++;
	if (i != 4 || line[i] != '-')
		return (std::cout << "Error: Invalid date" << std::endl, false);
	while (isdigit(line[i]))
		i++;
	if (i != 7 || line[i] != '-')
		return (std::cout << "Error: Invalid date" << std::endl, false);
	while (isdigit(line[i]))
		i++;
	if (i != 10 || line[i] != ' ' || line[i + 1] != '|' || line[i + 2] == ' ')
		return (std::cout << "Error: Invalid date" << std::endl, false);
	info.setDate(line.substr(0, i));
	for (int n = 4; (line[i] && n > 0); n--)
	{
		if (!isdigit(line[i]))
		{
			if (line[i] == '-')
				std::cout << "Error: Not a positive number." << std::endl;
			else
				std::cout << "Error: Invalid value." << std::endl;
			return false ;
		}
		value += line[i];
		i++;
	}
	std::istringstream iss(value);
	double vl = 0;
	if (!(iss >> vl))
		return (false);
	else if (vl > 1000)
	{
		std::cout << "Error: Value above a 1000." << std::endl;
		return (false);
	}
	info.setValue(vl);
	return (true);
}

void Info::setDate(std::string date)
{
	_date = date;
}

void Info::setValue(double value)
{
	_value = value;
}

std::string Info::getDate()
{
	return (_date);
}

double Info::getValue()
{
	return (_value);
}

void getResult(Info &info, std::map<std::string, double> &db)
{
	std::string date = info.getDate();
	std::map<std::string, double>::iterator it = db.find(date);
	if (it == db.end() || it->first != date)
	{
		if (it == db.begin())
		{
			std::cout << "Date is out of bound" << std::endl;
			return ;
		}
		else
			--it;
	}
	std::cout << date << " => " << info.getValue() << " = " << it->second << std::endl;
}

std::map<std::string, double> getMap(std::ifstream &datafile)
{
	std::map<std::string, double> db;
	std::string line;
	std::getline(datafile, line);
	while (std::getline(datafile, line))
	{
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos)
			continue ;
		std::string date = line.substr(0, pos);
		double rate;
		std::istringstream iss(line.substr(pos + 1));
		iss >> rate;
	
		db[date] = rate;
	}
	return (db);
}