#include "../ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), \
_energyPoints(10), _attackDmg(0)
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(): _name("DeaultName"), _hitPoints(10), \
_energyPoints(10), _attackDmg(0) { }

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDmg = other._attackDmg;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDmg = other._attackDmg;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name \
		<< " has not enough enery points!" << std::endl;
		return ;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name \
		<< " has 0 hit points! (he is dead)" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " \
	<< target << ", causing " << _attackDmg \
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name \
		<< " has not enough enery points!" << std::endl;
		return ;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name \
		<< " has 0 hit points! (he is dead)" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name \
	<< " takes damage by " << amount \
	<< " points!" << std::endl;
}

void	ClapTrap::beReaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name \
		<< " has not enough enery points!" << std::endl;
		return ;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name \
		<< " has 0 hit points! (he is dead)" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name \
	<< " repairs himself by " << amount \
	<< " points!" << std::endl;
}