#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class	Span
{
private:
	unsigned int		_N;
	std::vector<int>	_Vector;
public:
	Span(void);
	Span(unsigned int N);
	Span(Span const &other);
	Span &operator=(Span const &other);
	~Span(void);


	void	addNumber(int nb);
	void	addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int		shortestSpan();
	int		longestSpan();

	class NotEnoughSpaceInSpan : public std::exception
	{
		const char * what () const throw ();
	};
	class NotEnoughNumbersInSpan : public std::exception
	{
		const char * what () const throw ();
	};
};

#endif