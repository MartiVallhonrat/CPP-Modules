#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap(std::string name);
	~DiamondTrap();

	DiamondTrap	&operator=(const DiamondTrap &other);

	using	ScavTrap::attack;
	void	whoAmI();
};

#endif