#include "converter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Wrong argument input" << std::endl;
	else
	{
		Converter	conv(argv[1]);
		std::cout << conv;
	}
	return (0);
}