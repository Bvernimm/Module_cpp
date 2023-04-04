#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

class PmergeMe
{
private:
	std::vector<int>	_vector;
	std::list<int>		_list;
public:
	PmergeMe(void);
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);
	~PmergeMe(void);

	void	makeVectorAndList(char **argv);
	int		size(void);
	void	print(void);
	void	sortVector(int begin, int end);
	void	sortList(int begin, int end);
private:
	void	_vectorAlgo(int begin, int mid, int end);
	void	_listAlgo(int begin, int mid, int end);
	void	_listAdd(int pos, int value);
	int		_listAccess(int pos);
};

#endif