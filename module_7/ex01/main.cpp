#include "iter.hpp"

void	increment(int &a)
{
	a++;
}

int	main(void)
{
	int	array[] = {1,2,3,4,5};

	iter(array, 5, *increment);

	for (int i = 0; i < 5; i++)
		std::cout << array[i] << ", ";
	std::cout << std::endl;

	return 0;
}