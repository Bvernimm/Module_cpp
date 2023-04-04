#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	dataBase;

	if (argc != 2)
		std::cout << "Error: invalid number of argumant.\n";
	else
		dataBase.printMultipleValue(argv[1]);
	return 0;
}