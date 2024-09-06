#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap(std::string name);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &other);

	void	highFivesGuys(void);
};

#endif