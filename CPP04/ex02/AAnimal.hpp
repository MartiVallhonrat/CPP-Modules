#ifndef	AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
protected:
	std::string	_type;
public:
	AAnimal();
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();

	AAnimal	&operator=(const AAnimal &other);

	std::string	getType() const;

	virtual void	makeSound(void) const = 0;
};

#endif