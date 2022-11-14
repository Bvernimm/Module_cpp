#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
	std::string	*_ideas;
public:
	Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain(void);

	void		addThought(std::string idea, int i);
	std::string	getThought(int i);
};

#endif