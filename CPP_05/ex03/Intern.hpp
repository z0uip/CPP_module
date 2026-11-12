#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class AForm;

class Intern
{
	public :
		Intern(void);
		Intern(const Intern& other);
		~Intern();
		Intern& operator=(const Intern& other);
		AForm* makeForm(const std::string name, const std::string target) const;
		class InvalidForm : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Unvalid target !");
				}
		};
};

#endif