#include "RPN.hpp"

bool Ope::execute(const std::string &line)
{
	std::istringstream	iss(line);
	std::string			token;

	while (!_digit.empty())
		_digit.pop();

	while (iss >> token)
	{
		if (token.size() != 1)
			return (error());
		char c = token[0];

		if (std::isdigit(static_cast<unsigned char>(c)))
			_digit.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_digit.size() < 2)
				return (error());
			long b = _digit.top();
			_digit.pop();
			long a = _digit.top();
			_digit.pop();

			if (c == '+')
				_digit.push(a + b);
			else if (c == '-')
				_digit.push(a - b);
			else if (c == '*')
				_digit.push(a * b);
			else
			{
				if (b == 0)
					return (error());
				_digit.push(a / b);
			}
		}
		else
			return (error());
	}
	if (_digit.size() != 1)
		return (error());
	std::cout << _digit.top() << std::endl;
	return (true);
}

bool parsing(const std::string &line)
{
	size_t	i = 0;
	int		count = 0;

	while (i < line.size())
	{
		while (i < line.size() && std::isspace(static_cast<unsigned char>(line[i])))
			i++;
		if (i == line.size())
			break ;
		char c = line[i];
		if (i + 1 < line.size() && !std::isspace(static_cast<unsigned char>(line[i + 1])))
			return false;
		if (std::isdigit(static_cast<unsigned char>(c)))
			count++;
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (count < 2)
				return false;
			count--;
		}
		else
			return false;
		i++;
	}
	return (count == 1);
}

void Ope::addDigit(int newd)
{
	_digit.push(newd);
}

int Ope::getDigit()
{
	int top = _digit.top();
	_digit.pop();
	return top;
}

size_t Ope::size() const
{
	return _digit.size();
}

bool Ope::error() const
{
	std::cerr << "Error" << std::endl;
	return (false);
}

Ope::Ope()
{
}

Ope::Ope(const Ope &other) : _digit(other._digit)
{
}

Ope &Ope::operator=(const Ope &other)
{
	if (this != &other)
		_digit = other._digit;
	return (*this);
}

Ope::~Ope()
{
}