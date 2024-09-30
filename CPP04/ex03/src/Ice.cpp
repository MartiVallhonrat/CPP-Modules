# include "../Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice Materia constructor called!" << std::endl;
}

Ice::Ice(const Ice &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Ice Materia constructor called!" << std::endl;
}

Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Ice Materia constructor called!" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Materia destructor called!" << std::endl;
}

Ice	*Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " \
	<< target.getName()  << " *"<< std::endl;
}