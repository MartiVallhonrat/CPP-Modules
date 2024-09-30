#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class InvalidIdxException: public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Invalid index!");
	}
};

class FullException: public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Unable to store, container is full!");
	}
};

class FewElementsException: public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Unable to compare, too few elements!");
	}
};

class Span
{
private:
	std::vector<int>	_container;
	unsigned int		_size;
	unsigned int		_maxSize;
public:
	Span();
	Span(unsigned int maxSize);
	Span(const Span &other);
	~Span();

	Span	&operator=(const Span &other);

	unsigned int	getSize(void) const;
	unsigned int	getMaxSize(void) const;
	int				getIdx(unsigned int idx) const;

	void			addNumber(int num);
	int				shortestSpan(void);
	int				longestSpan(void);
	void			fillDefault(void);
};

#endif