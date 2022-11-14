#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, int size, void (*fct)(T &)) {
	for (int i = 0; i < size; i++)
		fct(array[i]);
}

#endif