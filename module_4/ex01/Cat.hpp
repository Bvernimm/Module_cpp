#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*_Brain;
public:
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat(void);

	void		makeSound(void);
	void		addIdea(std::string idea, int i);
	std::string	mindReading(int i);
};

#endif