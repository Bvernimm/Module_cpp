#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _vector(), _list()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	_vector = other._vector;
	_list = other._list;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	_vector = other._vector;
	_list = other._list;
	return *this;
}

PmergeMe::~PmergeMe(void)
{
}

void PmergeMe::makeVectorAndList(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		_vector.push_back(atoi(argv[i]));
		_list.push_back(atoi(argv[i]));
		i++;
	}
}

int PmergeMe::size(void)
{
	return (_vector.size());
}

void PmergeMe::print(void)
{
	for(std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//////////////////// VECTOR ////////////////////

void PmergeMe::sortVector(int begin, int end)
{
	int	mid;

	if (begin >= end)
        return;
    mid = begin + (end - begin) / 2;
    sortVector(begin, mid);
    sortVector(mid + 1, end);
    _vectorAlgo(begin, mid, end);
}

void PmergeMe::_vectorAlgo(int begin, int mid, int end)
{
	int arrayOneSize;
    int arrayTwoSize;
    int	*leftArray;
    int	*rightArray;
	int arrayOneIndex;
    int	arrayTwoIndex;
    int vectorIndex;

	arrayOneSize = mid - begin + 1;
	arrayTwoSize = end - mid;
	leftArray = new int[arrayOneSize];
	rightArray = new int[arrayTwoSize];
    arrayOneIndex = 0;
    arrayTwoIndex = 0;
    vectorIndex = begin;

	for (int i = 0; i < arrayOneSize; i++)
        leftArray[i] = _vector[begin + i];
    for (int j = 0; j < arrayTwoSize; j++)
        rightArray[j] = _vector[mid + 1 + j];
	
    while (arrayOneIndex < arrayOneSize && arrayTwoIndex < arrayTwoSize) 
	{
        if (leftArray[arrayOneIndex] <= rightArray[arrayTwoIndex]) 
		{
            _vector[vectorIndex] = leftArray[arrayOneIndex];
            arrayOneIndex++;
        }
        else 
		{
            _vector[vectorIndex] = rightArray[arrayTwoIndex];
            arrayTwoIndex++;
        }
        vectorIndex++;
    }
    while (arrayOneIndex < arrayOneSize) 
	{ 
		_vector[vectorIndex] = leftArray[arrayOneIndex];
        arrayOneIndex++;
        vectorIndex++;
    }
    while (arrayTwoIndex < arrayTwoSize) 
	{
		_vector[vectorIndex] = rightArray[arrayTwoIndex];
        arrayTwoIndex++;
        vectorIndex++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

//////////////////// LIST ////////////////////

void PmergeMe::sortList(int begin, int end)
{
	int	mid;

	if (begin >= end)
        return;
    mid = begin + (end - begin) / 2;
    sortList(begin, mid);
    sortList(mid + 1, end);
    _listAlgo(begin, mid, end);
}

void PmergeMe::_listAlgo(int begin, int mid, int end)
{
	int arrayOneSize;
    int arrayTwoSize;
    int	*leftArray;
    int	*rightArray;
	int arrayOneIndex;
    int	arrayTwoIndex;
    int listIndex;

	arrayOneSize = mid - begin + 1;
	arrayTwoSize = end - mid;
	leftArray = new int[arrayOneSize];
	rightArray = new int[arrayTwoSize];
    arrayOneIndex = 0;
    arrayTwoIndex = 0;
    listIndex = begin;

	for (int i = 0; i < arrayOneSize; i++)
        leftArray[i] = _listAccess(begin + i);
    for (int j = 0; j < arrayTwoSize; j++)
        rightArray[j] = _listAccess(mid + 1 + j);
	
    while (arrayOneIndex < arrayOneSize && arrayTwoIndex < arrayTwoSize) 
	{
        if (leftArray[arrayOneIndex] <= rightArray[arrayTwoIndex]) 
		{
			_listAdd(listIndex, leftArray[arrayOneIndex]);
            arrayOneIndex++;
        }
        else 
		{
			_listAdd(listIndex, rightArray[arrayTwoIndex]);
            arrayTwoIndex++;
        }
        listIndex++;
    }
    while (arrayOneIndex < arrayOneSize) 
	{ 
		_listAdd(listIndex, leftArray[arrayOneIndex]);
        arrayOneIndex++;
        listIndex++;
    }
    while (arrayTwoIndex < arrayTwoSize) 
	{
		_listAdd(listIndex, rightArray[arrayTwoIndex]);
        arrayTwoIndex++;
        listIndex++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void PmergeMe::_listAdd(int pos, int value)
{
	std::list<int>::iterator	it;

	it = _list.begin();
	for (int index = 0; index < pos; index++)
		it++;
	*it = value;
}

int PmergeMe::_listAccess(int pos)
{
	std::list<int>::iterator	it;

	it = _list.begin();
	for (int index = 0; index < pos; index++)
		it++;
	return (*it);
}