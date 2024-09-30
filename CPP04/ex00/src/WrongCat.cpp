# include "../WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout <<  this->_type \
	<< " constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->_type	= other._type;
}

WrongCat::~WrongCat()
{
	std::cout <<  this->_type \
	<< " destructor called!" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	WrongCat::getType() const
{
	return (this->_type);
}

void	WrongCat::makeSound(void) const
{
	std::cout <<  this->_type \
	<< ": Meeaaaaaaw!" << std::endl;	
}