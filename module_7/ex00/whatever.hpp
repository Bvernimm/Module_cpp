#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b) {
    T	c;

	c = a;
	a = b;
	b = c;
}

template <typename T>
T	min(T a, T b) {
    if (a < b)
		return (a);
	return (b);
	//return (a < b ? a : b);
	//and more
}

template <typename T>
T	max(T a, T b) {
    if (a > b)
		return (a);
	return (b);
}

#endif