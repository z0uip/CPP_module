#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->vect = other.vect;
		this->deq = other.deq;
	}
	return *this;
}

void PmergeMe::parse(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::string args = av[i];
		if (args.empty())
			throw std::invalid_argument("Error: empty argument.");
		for (size_t j = 0; j < args.length(); ++j)
		{
			if (!isdigit(args[j]))
				throw std::invalid_argument("Error: not a positive integer.");
		}
		long value = std::atol(args.c_str());//verif overflow
		if (value > INT_MAX)
			throw std::invalid_argument("Error: number too large.");
		vect.push_back(static_cast<int>(value));
		deq.push_back(static_cast<int>(value));
	}
}

void PmergeMe::printSequence(const std::string& msg) const
{
	std::cout << msg;
	for (size_t i = 0; i < vect.size(); ++i)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << "\n";
}

void PmergeMe::mergeSort(std::vector< std::pair<int, int> >& tab)//compare les plus gros chiffres(psk une std::pair prend les chiffres a gauche en prio les "first") entre eux et les classes ds lordre
{
	if (tab.size() <= 1)
		return;
	int	mid = tab.size() / 2;//on coupe le tab en 2
	std::vector< std::pair<int, int> > left(tab.begin(), tab.begin() + mid);
	std::vector< std::pair<int, int> > right(tab.begin() + mid, tab.end());
	mergeSort(left);
	mergeSort(right);
	tab.clear();
	size_t i = 0;
	size_t j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
		{
			tab.push_back(left[i]);
			i++;
		}
		else
		{
			tab.push_back(right[j]);
			j++;
		}
	}
	while (i < left.size())//vider ce qui reste
	{
		tab.push_back(left[i]);
		i++;
	}
	while (j < right.size())
	{
		tab.push_back(right[j]);
		j++;
	}
}

void PmergeMe::mergeSort(std::deque< std::pair<int, int> >& tab)
{
	if (tab.size() <= 1)
		return;
	int mid = tab.size() / 2;
	std::deque< std::pair<int, int> > left(tab.begin(), tab.begin() + mid);
	std::deque< std::pair<int, int> > right(tab.begin() + mid, tab.end());
	
	mergeSort(left);
	mergeSort(right);
	
	tab.clear();
	size_t i = 0;
	size_t j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
		{
			tab.push_back(left[i]);
			i++;
		}
		else
		{
			tab.push_back(right[j]);
			j++;
		}
	}
	while (i < left.size())
	{
		tab.push_back(left[i]);
		i++;
	}
	while (j < right.size())
	{
		tab.push_back(right[j]);
		j++;
	}
}

void PmergeMe::sortVector()
{
	if (vect.size() <= 1)
		return;
	std::vector<std::pair<int, int> > pairs;//std::pair sert a comparer 2 elements du mm type
	int last = -1;
	bool haslast = false;
	if (vect.size() % 2 != 0)//si vect a une taille impaire on save le dernier chiffre car on n'a prsn pr le comparer
	{
		last = vect[vect.size() - 1];//on recup la derniere case de vect
		haslast = true;
	}
	for (size_t i = 0; i < vect.size() - 1; i += 2)//on avance de 2 en 2 a chaque comparaison
	{
		if (vect[i] > vect[i + 1])
		{
			pairs.push_back(std::make_pair(vect[i], vect[i + 1]));//plus grand a gauche plus petit a droite
		}
		else
			pairs.push_back(std::make_pair(vect[i + 1], vect[i]));
	}
	mergeSort(pairs);
	std::vector<int> main_chain;//les plus gros chiffres deja trier
	std::vector<int> pending;//les plus petits pas trier
	main_chain.push_back(pairs[0].second);//on insere le perdant qui a perdu contre le plus petits nbr
	main_chain.push_back(pairs[0].first);//on insere le plus petit gagnant
	for (size_t j = 1; j < pairs.size(); ++j)
	{
		main_chain.push_back(pairs[j].first);//tt les gros chiffres
		pending.push_back(pairs[j].second);//tt les petits
	}
	size_t last_pos = 1;
	size_t jacob_idx = 3;
	while (last_pos < pending.size() + 1)
	{
		size_t curr_pos = jacobSthal(jacob_idx);
		if (curr_pos > pending.size() + 1)
			curr_pos = pending.size() + 1;
		for (size_t i = curr_pos; i > last_pos; --i)
		{
			int loser = pending[i - 2];
			std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), loser);
			main_chain.insert(it, loser);
		}
		last_pos = curr_pos;
		jacob_idx++;
	}
	if (haslast)
	{
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), last);//inserer le dernier chiffre
		main_chain.insert(it, last);
	}
	vect = main_chain;
}

void PmergeMe::sortDeque()
{
	if (deq.size() <= 1)
		return;
	std::deque<std::pair<int, int> > pairs;
	int last = -1;
	bool haslast = false;
	if (deq.size() % 2 != 0)
	{
		last = deq[deq.size() - 1];
		haslast = true;
	}
	for (size_t i = 0; i < deq.size() - 1; i += 2)
	{
		if (deq[i] > deq[i + 1])
		{
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		}
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}
	mergeSort(pairs);
	std::deque<int> main_chain;
	std::deque<int> pending;
	main_chain.push_back(pairs[0].second);
	main_chain.push_back(pairs[0].first);
	for (size_t j = 1; j < pairs.size(); ++j)
	{
		main_chain.push_back(pairs[j].first);
		pending.push_back(pairs[j].second);
	}
	size_t last_pos = 1;
	size_t jacob_idx = 3;
	while (last_pos < pending.size() + 1)
	{
		size_t curr_pos = jacobSthal(jacob_idx);
		if (curr_pos > pending.size() + 1)
			curr_pos = pending.size() + 1;
		for (size_t i = curr_pos; i > last_pos; --i)
		{
			int loser = pending[i - 2];
			std::deque<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), loser);
			main_chain.insert(it, loser);
		}
		last_pos = curr_pos;
		jacob_idx++;
	}
	if (haslast)
	{
		std::deque<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), last);
		main_chain.insert(it, last);
	}
	deq = main_chain;
}

size_t PmergeMe::jacobSthal(size_t n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	return jacobSthal(n - 1) + 2 * jacobSthal(n - 2);
}