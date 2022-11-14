#include "Cat.hpp"

Cat::Cat(void) : Animal("cat")
{
	_Brain = new Brain();
	std::cout << "Cat default constructor called\n";
	return ;
}

Cat::Cat(const Cat &other): Animal(other._type)
{
	_Brain = new Brain( *other._Brain );
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other){
	_type = other._type;
	if (_Brain)
		delete _Brain;
	_Brain = new Brain( *other._Brain );
	std::cout << "Cat copy assignement called\n";
	return *this;
}

Cat::~Cat(void) {
	delete _Brain;
	std::cout << "Cat destructor called\n";
	return ;
}

/*---------------------------------------------*/

void Cat::makeSound(void)
{
	std::cout << "Miaawwww\n";
}

void Cat::addIdea(std::string idea, int i)
{
	_Brain->addThought(idea, i);
}

std::string Cat::mindReading(int i)
{
	return (_Brain->getThought(i));
}