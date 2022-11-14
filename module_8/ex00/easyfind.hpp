#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &array, int nb)
{
	return (std::find(array.begin(), array.end(), nb));
}

#endif