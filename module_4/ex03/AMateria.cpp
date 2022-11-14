#include "AMateria.hpp"

AMateria::AMateria (void) {
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria (std::string const &type) : _type (type); {
	std::cout << "AMateria constructor called\n";
}

AMateria::AMateria (const AMateria &other) : _type(other.getType()) {
	std::cout << "AMateria copy constructor called\n";
}

AMateria::AMateria &operator=(const AMateria &other) {
	_type = other.getType();
	std::cout << "AMateria copy assignement called\n";
}

AMateria::~AMateria (void) {
	std::cout << "AMateria default destructor called\n";
}

/*---------------------------------------------*/

std::string const AMateria::&getType() const 
{
	return (_type);
}

virtual AMateria* clone() const = 0 
{
	return (*this);
}

virtual void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria use fonction called\n";
}