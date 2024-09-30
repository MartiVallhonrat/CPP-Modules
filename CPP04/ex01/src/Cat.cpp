# include "../Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout <<  this->_type \
	<< " constructor called!" << std::endl;
}

Cat::Cat(const Cat &other)
{
	_brain = new Brain();
	this->_type	= other._type;
	*this->_brain = *other._brain;
	std::cout <<  this->_type \
	<< " constructor copy called!" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout <<  this->_type \
	<< " destructor called!" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		this->_brain = other._brain;
	}
	return (*this);
}

std::string	Cat::getType() const
{
	return (this->_type);
}

std::string	Cat::getIdea(size_t index) const
{
	return(_brain->getBrainIdea(index));
}

void	Cat::makeSound(void) const
{
	std::cout <<  this->_type \
	<< ": Meeaaaaaaw!" << std::endl;	
}