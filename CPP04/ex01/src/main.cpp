# include "../Animal.hpp"
# include "../Dog.hpp"
# include "../Cat.hpp"

int	main(void)
{
	const Animal* animals[4];
	const Animal* wrongAnimal = new Animal;
	size_t	arr_len = sizeof(animals) / sizeof(const Animal*);

	for(size_t i = 0; i < arr_len; i++)
	{
		if (i % 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}

	std::cout << animals[0]->getIdea(99) << std::endl;
	std::cout << animals[0]->getIdea(100) << std::endl;

	std::cout << wrongAnimal->getIdea(0) << std::endl;

	for(size_t i = 0; i < arr_len; i++)
	{
		delete animals[i];
	}
	delete wrongAnimal;

	return (0);
}