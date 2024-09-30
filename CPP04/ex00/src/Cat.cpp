# include "../Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout <<  this->_type \
	<< " constructor called!" << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->_type	= other._type;
}

Cat::~Cat()
{
	std::cout <<  this->_type \
	<< " destructor called!" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	Cat::getType() const
{
	return (this->_type);
}

void	Cat::makeSound(void) const
{
	std::cout <<  this->_type \
	<< ": Meeaaaaaaw!" << std::endl;	
}