#ifndef	WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
	/* data */
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	~WrongCat();

	WrongCat	&operator=(const WrongCat &other);

	std::string	getType() const;

	void	makeSound(void) const;
};

#endif