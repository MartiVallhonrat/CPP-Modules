#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <exception>
# include <vector>
# include <deque>
# include <iterator>
# include <algorithm>
# include <cstdlib>
# include <limits.h>
# include <sys/time.h>
# include <typeinfo>
# include <string>


template <typename T>
class PmergeMe
{
private:
	T		_numbers;
	float	_time;

	void	merge(int left, int mid, int right);
	void	mergeSort(int begin, int end);
public:
	PmergeMe();
	PmergeMe(PmergeMe &other);
	PmergeMe(int argc, char *argv[]);
	~PmergeMe();

	PmergeMe<T>	&operator=(PmergeMe &other);

	class BadInputException: public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Bad Input");
		}
	};

	T		&getNumbers(void);
	void	printNumbers(void);
	void	printInfo(void);
	void	mergeInsert(void);
};

#endif