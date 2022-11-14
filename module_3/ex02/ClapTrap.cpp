#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : 
	_HitPoints (10),
	_EnergyPoints (10),
	_AttackDamage (0) {
	std::cout << "ClapTrap " << _name << " is ready for combat\n";
}

ClapTrap::ClapTrap(std::string name) :
	_name (name),
	_HitPoints (10),
	_EnergyPoints (10),
	_AttackDamage (0) {
	std::cout << "ClapTrap " << _name << " is ready for combat\n";
}

ClapTrap::ClapTrap(int hp, int ep, int dmg) :
	_HitPoints (hp),
	_EnergyPoints (ep),
	_AttackDamage (dmg) {
	std::cout << "ClapTrap is ready for combat\n";
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int dmg) :
	_name (name),
	_HitPoints (hp),
	_EnergyPoints (ep),
	_AttackDamage (dmg) {
	std::cout << "ClapTrap " << _name << " is ready for combat\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	_name (other._name),
	_HitPoints (other._HitPoints),
	_EnergyPoints (other._EnergyPoints),
	_AttackDamage (other._AttackDamage) {
	std::cout << "ClapTrap " << _name << " is ready for combat\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	_name = other._name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
	std::cout << "ClapTrap was copied !\n";
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " returning to scraps\n";
}

/*---------------------------------------------*/

void ClapTrap::attack(const std::string& target)
{
	if (_EnergyPoints <= 0 || _HitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << "... is tired... too tired..\n";
		return ;
	}
	_EnergyPoints = _EnergyPoints - 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints <= amount)
	{
		_HitPoints = 0;
		std::cout << "ClapTrap " << _name << " is KO!\n";
		return ;
	}
	_HitPoints = _HitPoints - amount;
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints <= 0 || _HitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << "... is tired... too tired..\n";
		return ;
	}
	_EnergyPoints = _EnergyPoints - 1;
	_HitPoints = _HitPoints + amount;
	std::cout << "ClapTrap " << _name << " has been healed to " << _HitPoints << " HP\n";
}