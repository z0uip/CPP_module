#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private :
		const std::string name;
		int grade;
	public :
		void signForm(Form& form);
		~Bureaucrat(void);
		int getGrade() const;
		void increaseGrade();
		void decreaseGrade();
		std::string getName() const;
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(std::string name, int grade);
		Bureaucrat& operator=(const Bureaucrat& other);
		class GradeTooHighException : public std::exception
		{
			public :
			const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public :
			const char* what() const throw();
		};
};
	
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif