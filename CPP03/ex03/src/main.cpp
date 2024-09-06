# include "../ClapTrap.hpp"
# include "../ScavTrap.hpp"
# include "../FragTrap.hpp"
# include "../DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Diamond("Gamma");
	std::string test = "Delta";

	Diamond.attack(test);
	Diamond.whoAmI();

	return (0);
}