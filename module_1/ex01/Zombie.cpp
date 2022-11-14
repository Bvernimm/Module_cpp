#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " returning to the tomb\n";
	return ;
}

Zombie::Zombie( std::string name )
{
	_name = name;
	return ;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name( std::string name )
{
	_name = name;
}
