# include "../Dog.hpp"
# include "../Cat.hpp"
# include "../WrongAnimal.hpp"
# include "../WrongCat.hpp"

int	main(void)
{
	std::cout << "____Correct Animal & Cat test____" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl \
	<< "____Wrong Animal & Cat test____" << std::endl;
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_i = new WrongCat();
	WrongCat newcat;

	std::cout << w_i->getType() << " " << std::endl;
	w_i->makeSound();
	w_meta->makeSound();
	newcat.makeSound();
	
	delete w_meta;
	delete w_i;
}