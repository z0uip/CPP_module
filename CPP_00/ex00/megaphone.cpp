#include <iostream>

int main(int ac, char **av)
{
	int i = 1;
	int j;
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (av[i])
	{
		j = 0;
		std::string s = av[i];
		while (s[j])
		{
			if (s[j] >= 'a' && s[j] <= 'z')
				s[j] -= 32;
			std::cout << s[j];
			j++;
		}
		if (s[j] != ' ' && av[i + 1])
			std::cout << " ";
		else if (!av[i + 1])
			std::cout << "\n";
		i++;
	}
	return (0);
}

