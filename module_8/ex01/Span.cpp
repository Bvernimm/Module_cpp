#include "Span.hpp"

Span::Span(void) : _N(0) {
}

Span::Span(unsigned int N) : _N(N) {
}

Span::Span(Span const &other) : _N(other._N), _Vector(other._Vector) {
}

Span &Span::operator=(Span const &other) {
	_N = other._N;
	_Vector = other._Vector;
	return *this;
}

Span::~Span(void) {
}

/*---------------------------------------------*/

void Span::addNumber(int nb)
{
	if (_Vector.size() < _N)
		_Vector.push_back(nb);
	else
		throw NotEnoughSpaceInSpan();
}

void Span::addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>	tmp;

	tmp.insert (tmp.end(), begin, end);
	if (tmp.size() > (_N - _Vector.size()))
		throw NotEnoughSpaceInSpan();
	_Vector.insert (_Vector.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_Vector.size() < 2)
		throw NotEnoughNumbersInSpan();
	std::vector<int>	sortedVector = _Vector;
	int					minSpan;

	std::sort(sortedVector.begin(), sortedVector.end());
	minSpan = (sortedVector[1] - sortedVector[0]);
	for (unsigned int i = 0; i + 1 < sortedVector.size(); i++)
	{
		if ((sortedVector[i + 1] - sortedVector[i]) < minSpan)
			minSpan = (sortedVector[i + 1] - sortedVector[i]);
	}
	return (minSpan);
}

int Span::longestSpan()
{
	if (_Vector.size() < 2)
		throw NotEnoughNumbersInSpan();
	int	min = *std::min_element(_Vector.begin(), _Vector.end());
	int	max = *std::max_element(_Vector.begin(), _Vector.end());

	return (max - min);
}

/*---------------------------------------------*/

const char *Span::NotEnoughSpaceInSpan::what () const throw ()
{
	return "NotEnoughSpaceInSpan";
}

const char *Span::NotEnoughNumbersInSpan::what () const throw ()
{
	return "NotEnoughNumbersInSpan";
}