#include "Array.hpp"

int	main(void)
{
	Array<int> *array1 = new Array<int>(5);
	Array<int> *array2 = new Array<int>();
	Array<int> copy(*array1);

	std::cout << "Array 1 size = " << array1->size() << std::endl;
	std::cout << "Array 2 size = " << array2->size() << std::endl;
	std::cout << "Array 1 = " << *array1 << std::endl;
	std::cout << "Copy Array = " << copy << std::endl;
	copy[0] = 5;
	copy[3] = 25;
	std::cout << "Array 1 = " << *array1 << std::endl;
	std::cout << "Copy Array = " << copy << std::endl;
	delete array1;
	std::cout << "Copy Array = " << copy << std::endl;

	try
	{
		copy[8] = 25;
		std::cout << "Copy Array = " << copy << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}