#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();

	Animal	&operator=(const Animal &other);

	std::string	getType() const;
	virtual	std::string	getIdea(size_t index) const;

	virtual void	makeSound(void) const;
};

#endif