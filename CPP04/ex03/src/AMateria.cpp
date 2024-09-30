#include "../AMateria.hpp"

AMateria::AMateria(): _type("ice")
{
	std::cout << "Materia default(" << _type \
	<< ") constructed!" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Materia type: " \
	<< _type << " constructed!" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "Materia type: " \
	<< _type << " constructed!" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Materia type: " \
	<< _type << " destroyed!" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Materia type: " \
	<< _type << " constructed!" << std::endl;
	return (*this);
}

std::string	const &AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " \
	<< target.getName()  << " *"<< std::endl;
}