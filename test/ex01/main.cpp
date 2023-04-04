#include "RPN.hpp"

int	main(int argc, char **argv)
{
	rpn		math;
	int		result;

	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	if (math.check(argv[1]) != 0)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	result = math.getResult(argv[1]);
	std::cout << "Result : " << result << std::endl;
	
	return (0);
}