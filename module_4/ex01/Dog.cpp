#include "Dog.hpp"

Dog::Dog(void) : Animal("dog")
{
	_Brain = new Brain();
	std::cout << "Dog default constructor called\n";
	return ;
}

Dog::Dog(const Dog &other): Animal(other._type)
{
	_Brain = new Brain( *other._Brain );
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other){
	_type = other._type;
	if (_Brain)
		delete _Brain;
	_Brain = new Brain( *other._Brain );
	std::cout << "Dog copy assignement called\n";
	return *this;
}

Dog::~Dog(void) {
	delete _Brain;
	std::cout << "Dog destructor called\n";
	return ;
}

/*---------------------------------------------*/

void Dog::makeSound(void)
{
	std::cout << "Wouf wouf !\n";
}

void Dog::addIdea(std::string idea, int i)
{
	_Brain->addThought(idea, i);
}

std::string Dog::mindReading(int i)
{
	return (_Brain->getThought(i));
}