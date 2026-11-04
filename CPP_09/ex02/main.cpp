#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: not enough arguments.\n";
		return 1;
	}
	try
	{
		PmergeMe sorter;
		sorter.parse(ac, av);
		sorter.printSequence("Before: ");
		std::clock_t start_vec = std::clock();
		sorter.sortVector();
		std::clock_t end_vec = std::clock();
		std::clock_t start_deq = std::clock();
		sorter.sortDeque();
		std::clock_t end_deq = std::clock();
		sorter.printSequence("After:  ");
		double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;
		double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000.0;
		std::cout << "Time to process a range of " << (ac - 1) 
				<< " elements with std::vector : " << time_vec << " us\n";
		std::cout << "Time to process a range of " << (ac - 1) 
				<< " elements with std::deque  : " << time_deq << " us\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}