#ifndef	CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
private:
	/* data */
public:
	Cat();
	Cat(const Cat &other);
	~Cat();

	Cat	&operator=(const Cat &other);

	std::string	getType() const;

	void	makeSound(void) const;
};

#endif