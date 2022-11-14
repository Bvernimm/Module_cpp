#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("cat")
{
	std::cout << "WrongCat default constructor called\n";
	return ;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other._type)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	_type = other._type;
	std::cout << "WrongCat copy assignement called\n";
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called\n";
	return ;
}

/*---------------------------------------------*/

void WrongCat::makeSound(void)
{
	std::cout << "Miaawwww\n";
}