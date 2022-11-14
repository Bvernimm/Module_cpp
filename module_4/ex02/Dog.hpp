#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_Brain;
public:
	Dog(void);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog(void);

	void	makeSound(void);
	void		addIdea(std::string idea, int i);
	std::string	mindReading(int i);
};

#endif