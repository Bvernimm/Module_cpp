#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T				*_array;
	unsigned int	_size;
public:
	Array(void);
	Array(unsigned int n);
	Array(Array<T> const &other);
	Array &operator=(Array<T> const &other);
	~Array(void);

	T &operator[](unsigned int i);

	unsigned int	size(void) const;

	class indexOutOfBound : public std::exception
	{
		const char * what () const throw ();
	};
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &arr);

#include "Array.tpp"

#endif