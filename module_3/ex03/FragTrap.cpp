#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap(100, 100, 30)
{
	std::cout << "FragTrap " << _name << " has come\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << _name << " has come\n";
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other._name, other._HitPoints, other._EnergyPoints, other._AttackDamage)
{
	std::cout << "FragTrap " << _name << " has come\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	_name = other._name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
	std::cout << "FragTrap was copied !\n";
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " has left\n";
}

/*---------------------------------------------*/

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " wants to high fives\n";
}