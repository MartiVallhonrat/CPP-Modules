# include "../Dog.hpp"

Dog::Dog(): AAnimal()
{
	this->_type = "Dog";
	std::cout <<  this->_type \
	<< " constructor called!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	this->_type	= other._type;
}

Dog::~Dog()
{
	std::cout <<  this->_type \
	<< " destructor called!" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	Dog::getType() const
{
	return (this->_type);
}

void	Dog::makeSound(void) const
{
	std::cout <<  this->_type \
	<< ": Woof, Woof!" << std::endl;	
}
