#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(100, 50, 20)
{
	std::cout << "ScavTrap " << _name << ", prepared for battle\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << _name << ", prepared for battle\n";
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other._name, other._HitPoints, other._EnergyPoints, other._AttackDamage)
{
	std::cout << "ScavTrap " << _name << ", prepared for battle\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	_name = other._name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
	std::cout << "ScavTrap was copied !\n";
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << ", my job here is done\n";
}

/*---------------------------------------------*/

void ScavTrap::attack(const std::string& target)
{
	if (_EnergyPoints <= 0 || _HitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << "... is tired... too tired..\n";
		return ;
	}
	_EnergyPoints = _EnergyPoints - 1;
	std::cout << "ScavTrap " << _name << " shoots " << target << ", dealing " << _AttackDamage << " points of damages!\n";
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " entered gate keeper mode\n";
}