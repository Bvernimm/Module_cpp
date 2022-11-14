#include "Dog.hpp"

Dog::Dog(void) : Animal("dog")
{
	std::cout << "Dog default constructor called\n";
	return ;
}

Dog::Dog(const Dog &other): Animal(other._type)
{
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other){
	_type = other._type;
	std::cout << "Dog copy assignement called\n";
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called\n";
	return ;
}

/*---------------------------------------------*/

void Dog::makeSound(void)
{
	std::cout << "Wouf wouf !\n";
}