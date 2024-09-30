# include "../Base.hpp"

int	main(void)
{
	Base *unknowType = generate();

	identify(unknowType);
	identify(*unknowType);

	delete unknowType;

	return (0);
}