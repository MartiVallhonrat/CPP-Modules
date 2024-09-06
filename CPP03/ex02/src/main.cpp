# include "../ClapTrap.hpp"
# include "../ScavTrap.hpp"
# include "../FragTrap.hpp"

int	main(void)
{
	ClapTrap	Clap("Alpha");
	FragTrap	Frag("Betha");

	Clap.attack("Betha");
	Clap.takeDamage(3);
	Clap.beReaired(3);

	Frag.highFivesGuys();

	return (0);
}