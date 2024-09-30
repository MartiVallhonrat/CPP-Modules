#ifndef	DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
private:
	/* data */
public:
	Dog();
	Dog(const Dog &other);
	~Dog();

	Dog	&operator=(const Dog &other);

	std::string	getType() const;

	void	makeSound(void) const;
};

#endif