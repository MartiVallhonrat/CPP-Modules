# include "../Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure Materia constructor called!" << std::endl;
}

Cure::Cure(const Cure &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Cure Materia constructor called!" << std::endl;
}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Cure Materia constructor called!" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Materia destructor called!" << std::endl;
}

Cure	*Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " \
	<< target.getName()  << "'s wounds *" << std::endl;
}