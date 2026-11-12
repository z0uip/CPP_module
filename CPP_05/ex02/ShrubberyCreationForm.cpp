#include "ShrubberyCreationForm.hpp"


#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > 137)
		throw AForm::GradeTooLowException();
	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cout << "Error: could not create file " << filename << std::endl;
		return;
	}

	file << "            .        +          .      .          .\n";
	file << "     .            _        .                    .\n";
	file << "  ,              /;-._,-.____        ,-----.__\n";
	file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n";
	file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n";
	file << "                      ,    `./  \\:. `.   )==-'  .\n";
	file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n";
	file << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n";
	file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n";
	file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n";
	file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n";
	file << "              \\:  `  X` _| _,\\/'   .-'\n";
	file << ".               \":._:`\\____  /:'  /      .           .\n";
	file << "                    \\::.  :\\/:'  /              +\n";
	file << "   .                 `.:.  /:'  }      .\n";
	file << "           .           ):_(:;   \\           .\n";
	file << "                      /:. _/ ,  |\n";
	file << "                   . (|::.     ,`                  .\n";
	file << "     .                |::.    {\\\n";
	file << "                      |::.\\  \\ `.\n";
	file << "                      |:::(\\    |\n";
	file << "              O       |:::/{ }  |                  (o\n";
	file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n";
	file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n";
	file << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~\n";

	file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm(145, 137, "ShrubberyCreationForm"), target(target)
{
	std::cout << "Default constructor called !" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Default destructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(145, 137, "ShrubberyCreationForm"), target(other.target)
{
	std::cout << "Copy constructor called !" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return *this;
}