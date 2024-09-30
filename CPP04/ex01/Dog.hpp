#ifndef	DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	Dog(const Dog &other);
	~Dog();

	Dog	&operator=(const Dog &other);

	std::string	getType() const;
	std::string	getIdea(size_t index) const;
	void setIdea(size_t index, std::string idea);

	void	makeSound(void) const;
};

#endif