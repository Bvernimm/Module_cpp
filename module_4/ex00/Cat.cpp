#include "Cat.hpp"

Cat::Cat(void) : Animal("cat")
{
	std::cout << "Cat default constructor called\n";
	return ;
}

Cat::Cat(const Cat &other): Animal(other._type)
{
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other){
	_type = other._type;
	std::cout << "Cat copy assignement called\n";
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called\n";
	return ;
}

/*---------------------------------------------*/

void Cat::makeSound(void)
{
	std::cout << "Miaawwww\n";
}