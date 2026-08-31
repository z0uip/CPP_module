#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string name;
		bool issigned;
		const int gsign;
		const int gexe;
	public :
		~Form();
		Form(const Form& other);
		const std::string getName();
		Form(int gsign, int gexe, std::string name);
		Form& operator=(const Form& other);
		void beSigned(Bureaucrat const & bureaucrat);
		class GradeTooLowException : public std::exception
		{
			public :
			const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public :
			const char* what() const throw();
		};
};

#endif