#include "Fixed.hpp"


Fixed::Fixed(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called." << std::endl;
	this->value = value * (1 << nbits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called." << std::endl;
	this->value = roundf(value * (1 << nbits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	std::cout << "Copy constructor called." << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
}


int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member called." << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member called." << std::endl;
	this->value = raw;
}


int Fixed::toInt(void) const
{
	return (this->value) >> nbits;
}

float Fixed::toFloat(void) const
{
	return float(this->value) / float(1 << nbits);
}


Fixed &Fixed::operator=(const Fixed &otherFixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &otherFixed)
		this->value = otherFixed.value;
	return *this;
}


bool Fixed::operator>(Fixed const &src) const
{
	return (this->value > src.value);
}

bool Fixed::operator<(Fixed const &src) const
{
	return (this->value < src.value);
}

bool Fixed::operator>=(Fixed const &src) const
{
	return (this->value >= src.value);
}

bool Fixed::operator<=(Fixed const &src) const
{
	return (this->value <= src.value);
}

bool Fixed::operator==(Fixed const &src) const
{
	return (this->value == src.value);
}

bool Fixed::operator!=(Fixed const &src) const
{
	return (this->value != src.value);
}


Fixed Fixed::operator+(Fixed const &src) const
{
	Fixed res;
	res.setRawBits(this->value + src.value);
	return res;
}

Fixed Fixed::operator-(Fixed const &src) const
{
	Fixed res;
	res.setRawBits(this->value - src.value);
	return res;
}

Fixed Fixed::operator*(Fixed const &src) const
{
	Fixed res;
	long long product = static_cast<long long>(this->value) * static_cast<long long>(src.value);
	res.setRawBits(static_cast<int>(product >> nbits));
	return res;
}

Fixed Fixed::operator/(Fixed const &src) const
{
	Fixed res;
	if (src.value == 0)
	{
		std::cout << "Division can't be done with 0" << std::endl;
		res.setRawBits(0);
		return res;
	}
	long long numerator = static_cast<long long>(this->value) << nbits;
	res.setRawBits(static_cast<int>(numerator / src.value));
	return res;
}


Fixed &Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->value++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->value--;
	return (tmp);
}


Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.value >= b.value ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.value >= b.value ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.value <= b.value ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.value <= b.value ? a : b);
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}