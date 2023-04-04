#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class rpn
{
private:
	std::stack<int>	_pile;
public:
	rpn(void);
	rpn(rpn const &other);
	rpn &operator=(rpn const &other);
	~rpn(void );

	int		check(char *rpn);
	int		getResult(char *rpn);
private:
	void	_addNumber(char nb);
	void	_doOp(char op);
};

#endif