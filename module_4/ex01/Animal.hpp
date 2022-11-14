#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal(void);

	virtual void	makeSound(void);
	std::string		getType(void);
	virtual void		addIdea(std::string idea, int i);
	virtual std::string	mindReading(int i);
};

#endif