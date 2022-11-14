#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	_type = "";
	std::cout << "WrongAnimal default constructor called\n";
	return ;
}

WrongAnimal::WrongAnimal(std::string type) {
	_type = type;
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) :
	_type (other._type) {
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	_type = other._type;
	std::cout << "WrongAnimal copy assignement called\n";
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called\n";
	return ;
}

/*---------------------------------------------*/

void WrongAnimal::makeSound(void)
{
	std::cout << "*Wrong Random Animal noise*\n";
}

std::string	WrongAnimal::getType(void)
{
	return (_type);
}