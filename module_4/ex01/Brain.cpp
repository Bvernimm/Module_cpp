#include "Brain.hpp"

Brain::Brain(void) {
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = "No thoughts, head empty\n";
	std::cout << "Brain default constructor called\n";
	return ;
}

Brain::Brain(const Brain &other) {
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i] + " copied";
	std::cout << "Brain copy constructor called\n";
}

Brain &Brain::operator=(const Brain &other) {
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i] + " copied";
	std::cout << "Brain copy assignement called\n";
	return *this;
}

Brain::~Brain(void) {
	delete [] _ideas;
	std::cout << "Brain destructor called\n";
	return ;
}

/*---------------------------------------------*/

void	Brain::addThought(std::string idea, int i)
{
	_ideas[i] = idea;
}

std::string	Brain::getThought(int i)
{
	return (_ideas[i]);
}