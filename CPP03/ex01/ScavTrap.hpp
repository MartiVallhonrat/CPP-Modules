#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
	/* data */
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap();
	~ScavTrap();

	ScavTrap	&operator=(const ScavTrap &other);

	void	guardGate(void);
	void	attack(std::string &target);
};

#endif