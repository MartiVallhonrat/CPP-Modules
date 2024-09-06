# include "../ClapTrap.hpp"
# include "../ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Clap("Alpha");
	ScavTrap	Scav("Betha");

	Clap.attack("Betha");
	Clap.takeDamage(3);
	Clap.beReaired(3);

	Scav.guardGate();

	return (0);
}