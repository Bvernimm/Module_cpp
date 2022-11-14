#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(100, 50, 30)
{
	std::cout << "DiamondTrap " << _name << " has been released into the world !\n";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name", 100, 50, 30)
{
	_name = name;
	std::cout << "DiamondTrap " << _name << " has been released into the world !\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other._name + "_clap_name", other._HitPoints, other._EnergyPoints, other._AttackDamage)
{
	_name = other._name;
	std::cout << "DiamondTrap " << _name << " has been released into the world !\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	_name = other._name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
	std::cout << "DiamondTrap was copied !\n";
	return *this;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap " << _name << " is gone... for now\n";
}

/*---------------------------------------------*/

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << _name << ", ClapTrap name : " << ClapTrap::_name << std::endl;
}