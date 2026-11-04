#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <stdint.h>
#include <exception>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <sstream>
#include <limits.h>

class PmergeMe
{
	private:
		std::vector<int> vect;
		std::deque<int> deq;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void parse(int ac, char **av);//verif des chiffres positifs remplit deq et vect avec
		void printSequence(const std::string& msg) const;//afficher le msg Before: et After:
		void mergeSort(std::vector< std::pair<int, int> >& tab);//prend le vecteur de pairs et met les gagnants ds lordre
		void mergeSort(std::deque< std::pair<int, int> >& tab);
		void sortVector();//logique de tri pr vector
		void sortDeque();//logique de tri pr deque
		size_t jacobSthal(size_t n);
};