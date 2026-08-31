#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>

class comments
{
	private :
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	public :

	void complain(std::string level);
};

bool str_is_allnum(std::string str);
