#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class NotFoundException: public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Number not found!");
	}
};

template <typename T>
void	easyfind(T &container, int toFind)
{
	try
	{
		if (std::find(container.begin(), container.end(), toFind) \
			== container.end())
		{
			throw NotFoundException();
		}
		std::cout << "easyfind found an ocurrence of " \
		<< toFind << "!\n";
	}
	catch (const NotFoundException &e)
	{
		std::cerr << "Error on finding " << toFind \
		<< ": " << e.what() << '\n';
	}	
}

#endif