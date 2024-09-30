#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <vector>
# include <iterator>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	/* data */
public:
	MutantStack(void) { };

	MutantStack(const MutantStack &other): std::stack<T>(other) { };

	~MutantStack(void) { };

	MutantStack	&operator=(const MutantStack &other)
	{
		if (this != &other)
		{
			std::stack<T>::operator=(other);
		}

		return (*this); 
	};

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin(void)
	{
		return (std::stack<T>::c.begin());
	}

	iterator	end(void)
	{
		return (std::stack<T>::c.end());
	};
};

#endif