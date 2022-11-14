#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	John("John", 37);
		std::cout << John << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		Bureaucrat	Max("Max", 0);
		std::cout << Max << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		Bureaucrat	Bob("Bob", 156);
		std::cout << Bob << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return (0);
}