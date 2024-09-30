# include "../AAnimal.hpp"
# include "../Dog.hpp"
# include "../Cat.hpp"

int	main(void)
{
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	//const AAnimal* k = new AAnimal();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();

	delete j;
	delete i;
}