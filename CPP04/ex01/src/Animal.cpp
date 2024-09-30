#include "../Animal.hpp"

Animal::Animal(): _type("Default")
{
	std::cout <<  this->_type \
	<< " Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->_type	= other._type;
}

Animal::~Animal()
{
	std::cout <<  this->_type \
	<< " Animal destructor called!" << std::endl;	
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->_type);
}

std::string	Animal::getIdea(size_t index) const
{
	(void)index;
	std::string	result = "Default has no brain...";
	return (result);
}

void	Animal::makeSound(void) const
{
	std::cout <<  this->_type \
	<< ": does not make any sound..." << std::endl;	
}