#include <iostream>
#include <cmath>

class Fixed
{
	private :

		int value;
		static const int nbits = 8;

	public :

		Fixed();
		Fixed(const int value);
		Fixed(const Fixed &copy);
		Fixed(const float value);
		int toInt(void) const;
		float toFloat(void) const;
		Fixed &operator=(const Fixed &otherFixed);
		~Fixed();
		int getRawBits( void );
		void setRawBits(int const raw);
};
	
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);