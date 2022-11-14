#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called\n";
	return ;
}

Animal::Animal(std::string type) :
	_type (type) {
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal &other) :
	_type (other._type) {
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other) {
	_type = other._type;
	std::cout << "Animal copy assignement called\n";
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called\n";
	return ;
}

/*---------------------------------------------*/

void Animal::makeSound(void)
{
	std::cout << "*Random animal noise*\n";
}

std::string	Animal::getType(void)
{
	if (_type == "")
		return ("Unknown animal");
	return (_type);
}