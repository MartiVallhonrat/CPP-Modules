#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{

private:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDmg;

public:
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &other);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beReaired(unsigned int amount);
};

#endif