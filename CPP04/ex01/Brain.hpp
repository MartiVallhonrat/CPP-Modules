# ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain	&operator=(const Brain &other);
	~Brain();


	std::string	getBrainIdea(size_t index);
	void	setBrainIdea(size_t index, std::string idea);

};

#endif