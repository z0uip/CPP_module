#include <iostream>

class Fixed
{
	private :

		int value;
		static const int nbits = 8;

	public :

		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &otherFixed);
		~Fixed();
		int getRawBits( void );
		void setRawBits(int const raw);
};
