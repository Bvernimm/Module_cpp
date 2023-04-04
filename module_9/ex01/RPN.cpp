#include "RPN.hpp"

rpn::rpn(void) : _pile()
{
}

rpn::rpn(rpn const &other)
{
	_pile = other._pile;
}

rpn &rpn::operator=(rpn const &other)
{
	_pile = other._pile;
	return *this;
}

rpn::~rpn(void) {
}

int rpn::check(char *rpn)
{
	int	ratio;
	int	i;
	int	element;

	i = 0;
	ratio = -1;
	element = 0;
	while (rpn[i] == ' ')
		i++;
	while (rpn[i])
	{
		element++;
		if (!isdigit(rpn[i]) && rpn[i] != '+' && rpn[i] != '-' && rpn[i] != '*' && rpn[i] != '/')
			return (1);
		if (isdigit(rpn[i]))
			ratio++;
		else if (rpn[i] != '+' || rpn[i] != '-' || rpn[i] != '*' || rpn[i] != '/')
			ratio--;
		if (ratio < 0)
			return (1);
		i++;
		if (rpn[i] && rpn[i] != ' ')
			return (1);
		while (rpn[i] && rpn[i] == ' ')
			i++;
	}
	if (ratio != 0)
		return (1);
	if (element < 3)
		return (1);
	return (0);
}

int rpn::getResult(char *rpn)
{
	int	i;

	i = 0;
	while (rpn[i] == ' ')
		i++;
	while (rpn[i])
	{
		if (isdigit(rpn[i]))
			_addNumber(rpn[i]);
		else
			_doOp(rpn[i]);
		i++;
		while (rpn[i] && rpn[i] == ' ')
			i++;
	}
	return (_pile.top());
}

////private

void	rpn::_addNumber(char nb)
{
	_pile.push(nb - '0');
}

void	rpn::_doOp(char op)
{
	int	nb1;
	int	nb2;

	nb2 = _pile.top();
	_pile.pop();
	nb1 = _pile.top();
	_pile.pop();
	if (op == '+')
		_pile.push(nb1 + nb2);
	else if (op == '-')
		_pile.push(nb1 - nb2);
	else if (op == '*')
		_pile.push(nb1 * nb2);
	else if (op == '/')
	{
		if (nb2 == 0)
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
		_pile.push(nb1 / nb2);
	}
}
