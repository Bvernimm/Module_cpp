#include "Span.hpp"
#include <time.h>

int	main(void)
{
	Span				emptySpan;
	Span				Span1(5);
	Span				Span2(1000);
	std::vector<int>	tmp;

	try
	{
		Span1.shortestSpan();
		Span1.longestSpan();
		emptySpan.addNumber(1);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	Span1.addNumber(1);
	Span1.addNumber(2);
	Span1.addNumber(3);
	Span1.addNumber(4);
	Span1.addNumber(5);

	std::cout << "Min Span : " << Span1.shortestSpan() << std::endl;
	std::cout << "Max Span : " << Span1.longestSpan() << std::endl;

	try
	{
		Span1.addNumber(6);
		Span1.addNumber(7);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	srand (time(NULL));
	for (int i = 0; i < 1000; i++)
		tmp.push_back(std::rand() % 1000);
	Span2.addMultipleNumbers(tmp.begin(), tmp.end());
	std::cout << "Min Span : " << Span2.shortestSpan() << std::endl;
	std::cout << "Max Span : " << Span2.longestSpan() << std::endl;

	try
	{
		Span2.addNumber(6);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}