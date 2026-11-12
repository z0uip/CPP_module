#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string name;
		bool issigned;
		const int gsign;
		const int gexe;
	public :
		virtual ~AForm();
		bool getIsSigned() const;
		AForm(const AForm& other);
		const std::string getName() const;
		AForm& operator=(const AForm& other);
		void beSigned(Bureaucrat const & bureaucrat);
		AForm(int gsign, int gexe, std::string name);
		virtual void execute(Bureaucrat const & executor) const = 0;
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