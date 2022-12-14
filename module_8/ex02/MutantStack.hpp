#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
private:

public:
	MutantStack(void);
	MutantStack(MutantStack<T> const &other);
	MutantStack &operator=(MutantStack<T> const &other);
	~MutantStack(void);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator				begin();
	iterator				end();
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_iterator			cbegin() const;
	const_iterator			cend() const;
	const_reverse_iterator	crbegin() const;
	const_reverse_iterator	crend() const;
};

#include "MutantStack.tpp"

#endif