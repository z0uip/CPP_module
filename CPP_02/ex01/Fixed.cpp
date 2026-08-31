#include "Fixed.hpp"

int Fixed::toInt(void) const
{
	return (this->value) >> nbits;
}

float Fixed::toFloat(void) const
{
	return float(this->value) / float(1 << nbits);
}

int Fixed::getRawBits( void )
{
	std::cout << "getRawBits member called." << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member called." << std::endl;
	this->value = raw;
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->value = 0;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called." << std::endl;
	this->value = roundf(value * (1 << nbits));
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called." << std::endl;
	this->value = value * (1 << nbits);
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

Fixed &Fixed::operator=(const Fixed &otherFixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &otherFixed)
	{
		this->value = otherFixed.value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}