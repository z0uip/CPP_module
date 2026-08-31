#include "phonebook.hpp"

int handle_add(Contact contact[8], int n_contact)
{
	int n = 0;
	std::string tmp;
    if (n_contact >= 8)
		n_contact = 0;
	std::cout << "Please enter the contact's first name.\n";
	getline(std::cin.ignore(), tmp);
	while (tmp[0] == '\0')
	{
		std::cout << "Please enter the contact's first name.\n";
		getline(std::cin, tmp);
	}
	contact[n_contact].set_first_name(tmp);
	tmp[0] = '\0';
	while (tmp[0] == '\0')
	{
		std::cout << "Please enter the contact's last name.\n";
		getline(std::cin, tmp);
	}
	contact[n_contact].set_last_name(tmp);
	tmp[0] = '\0';
	while (tmp[0] == '\0')
	{
		std::cout << "Please enter the contact's nickname.\n";
		getline(std::cin, tmp);
	}
	contact[n_contact].set_nickname(tmp);
	tmp[0] = '\0';
	while (!n || tmp[0] == '\0')
	{
		std::cout << "Please enter the contact's phone number.\n";
		getline(std::cin, tmp);
		n = contact[n_contact].set_phone_n(tmp);
	}
	tmp[0] = '\0';
	while (tmp[0] == '\0')
	{
		std::cout << "Please enter the contact's darkest secret.\n";
		getline(std::cin, tmp);
	}
	contact[n_contact].set_darkest_secret(tmp);
	tmp[0] = '\0';
	return (++n_contact);
}

void handle_search(Contact contact[8], int n_contact)
{
	int i = 0;
	std::string tmp;
	int n = -1;
	if (n_contact == 0)
	{
		std::cout << "No contact register, please add contacts.\n";
		return ;
	}
	std::cout << "Please enter a valid ID.\n";
	getline(std::cin.ignore(), tmp);
	if (is_digit_or_spaces(tmp))
		n = atoi(tmp.c_str());
	while ((n < 0) || (n >= n_contact))
	{
		std::cout << "Please enter a valid ID.\n";
		getline(std::cin, tmp);
		if (is_digit_or_spaces(tmp))
			n = atoi(tmp.c_str());
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  NickName|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < n)
		i++;
	std::cout << "|" << i << "         |";
	print_in_columns(contact[i].get_f_name());
	print_in_columns(contact[i].get_l_name());
	print_in_columns(contact[i].get_n_name());
	std::cout << std::endl << "|----------|----------|----------|----------|" << std::endl;
}

int main(void)
{
	int n_contact = 0;
	std::string input;
	Contact contact[8];
	while (std::cin.good())
	{
		std::cout << "Please enter a command\n";
		std::cin >> input;
		if (input == "ADD")
			n_contact = handle_add(contact, n_contact);
		if (input == "SEARCH")
			handle_search(contact, n_contact);
		if (input == "EXIT")
			break ;
	}
	return (0);
}