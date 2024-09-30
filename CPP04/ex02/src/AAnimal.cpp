#include "../AAnimal.hpp"

AAnimal::AAnimal(): _type("Default")
{
	std::cout <<  this->_type \
	<< " Animal constructor called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	this->_type	= other._type;
}

AAnimal::~AAnimal()
{
	std::cout <<  this->_type \
	<< " Animal destructor called!" << std::endl;	
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}