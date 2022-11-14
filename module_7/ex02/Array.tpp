#include "Array.hpp"

template <typename T> 
Array<T>::Array(void) : _array(NULL), _size (0) {
}

template <typename T> 
Array<T>::Array(unsigned int n) : _size (n) {
	if (_size)
		_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		T	*a = new T();
		_array[i] = *a;
		delete a;
	}
}

template <typename T> 
Array<T>::Array(Array<T> const &other) : _size (other._size) {
	if (_size)
		_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T> 
Array<T>::~Array(void) {
	if (_array)
		delete [] _array;
}

template <typename T> 
Array<T> &Array<T>::operator=(Array<T> const &other) {
	_size = other._size;
	if (_array)
		delete [] _array;
	if (_size)
		_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
	return *this;
}

/*---------------------------------------------*/

template <typename T> 
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
        throw indexOutOfBound();
    return _array[i];
}

/*---------------------------------------------*/

template <typename T> 
unsigned int Array<T>::size(void) const {
	return (_size);
}

/*---------------------------------------------*/

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &array)
{
    for (unsigned int i = 0; i < array.size(); i++ )
        os << array[i] << " ";
    return os;
}

/*---------------------------------------------*/

template <typename T> 
const char *Array<T>::indexOutOfBound::what () const throw ()
{
	return "indexOutOfBound";
}