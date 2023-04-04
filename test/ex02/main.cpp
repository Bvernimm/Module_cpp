#include "PmergeMe.hpp"
#include <cstdlib>
#include <string>
#include <chrono>

int	checkIntMax(char *nb)
{
	int			i;
	int			len;
	long int	value;

	i = 0;
	len = 0;
	while (nb[i] == '0')
		i++;
	while (nb[i])
	{
		i++;
		len++;
	}
	if (len > 10)
		return (1);
	value = atol(nb);
	if (value > 2147483647)
		return (1);
	return (0);
}

std::string	checkArgument(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (i > 3000)
			return ("Error : too many argument");
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]))
				return ("Error : invalid symbol in argument");
			if (j == 9 && checkIntMax(argv[i]) != 0)
				return ("Error : integer limit exceeded");
			j++;
		}
		i++;
		j = 0;
	}
	return ("ok");
}

int	main(int argc, char **argv)
{
	std::string	error;
	PmergeMe	tri;
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point stop;
	std::chrono::duration<double> time_span;

	if (argc <= 2)
	{
		std::cout << "Error : need more argument to sort" << std::endl;
		return (1);
	}
	error = checkArgument(argv);
	if (error != "ok")
	{
		std::cout << error << std::endl;
		return (1);
	}

	tri.makeVectorAndList(argv);

	std::cout << "Before: ";
	tri.print();

	start = std::chrono::high_resolution_clock::now();
	tri.sortList(0, tri.size() - 1);
	stop = std::chrono::high_resolution_clock::now();

	std::cout << "After: ";
	tri.print();

	time_span = std::chrono::duration_cast<std::chrono::duration<double> >(stop - start);
	std::cout << "Time to process a range of " << tri.size() << " elements with std::list : " << time_span.count() << " seconds" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	tri.sortVector(0, tri.size() - 1);
	stop = std::chrono::high_resolution_clock::now();

	time_span = std::chrono::duration_cast<std::chrono::duration<double> >(stop - start);
	std::cout << "Time to process a range of " << tri.size() << " elements with std::vector : " << time_span.count() << " seconds" << std::endl;
	return (0);
}