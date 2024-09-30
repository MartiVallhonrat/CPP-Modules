# include "../Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called!" << std::endl;
	std::fill_n(this->ideas, 100, "I want to eat...");
}

Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

std::string	Brain::getBrainIdea(size_t index)
{
	std::string	result;
	if (index < 0 || index > 99)
		result = "Invalid index!";
	else
		result = this->ideas[index];
	return (result);
}

void	Brain::setBrainIdea(size_t index, std::string idea)
{
	this->ideas[index] = idea;
}