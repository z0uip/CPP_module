#include "Fixed.hpp"

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