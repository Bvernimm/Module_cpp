#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	_name = name;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " returning to the tomb\n";
	return ;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
