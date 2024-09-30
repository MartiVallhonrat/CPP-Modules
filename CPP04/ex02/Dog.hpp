#ifndef	DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog: AAnimal
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