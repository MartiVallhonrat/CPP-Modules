# include "../Dog.hpp"
# include "../Brain.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout <<  this->_type \
	<< " constructor called!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	_brain = new Brain();
	this->_type	= other._type;
	*this->_brain = *other._brain;
	std::cout <<  this->_type \
	<< " constructor copy called!" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout <<  this->_type \
	<< " destructor called!" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		*this->_brain = *other._brain;
	}
	return (*this);
}

std::string	Dog::getType() const
{
	return (this->_type);
}

std::string	Dog::getIdea(size_t index) const
{
	return(_brain->getBrainIdea(index));
}

void	Dog::setIdea(size_t index, std::string idea)
{
	_brain->setBrainIdea(index, idea);
}

void	Dog::makeSound(void) const
{
	std::cout <<  this->_type \
	<< ": Woof, Woof!" << std::endl;	
}
