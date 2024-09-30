#include "../WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Default")
{
	std::cout <<  this->_type \
	<< " Animal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->_type	= other._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout <<  this->_type \
	<< " Animal destructor called!" << std::endl;	
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout <<  this->_type \
	<< ": does not make any sound..." << std::endl;	
}