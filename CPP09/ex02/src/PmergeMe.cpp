# include "../PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(): _time(0)
{
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe &other): _time(0)
{
	if (this != &other)
		_numbers = other.getNumbers();
}

template <typename T>
PmergeMe<T>::PmergeMe(int argc, char *argv[]): _time(0)
{
	long	n;
	for (int i = 1; i < argc; i++)
	{
		if (!argv[i][0])
			throw BadInputException();
		for (int j = 0; argv[i][j]; j++)
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9')
				&& !(argv[i][j] == '-') && !(argv[i][j] == '+')
				&& !std::isspace(argv[i][j]))
				throw BadInputException();
		}
		
		n = std::atol(argv[i]);
		if (n > INT_MAX || n < 0)
			throw BadInputException();
		_numbers.push_back(static_cast<int>(n));
	}
}

template <typename T>
PmergeMe<T> 	&PmergeMe<T>::operator=(PmergeMe &other)
{
	if (this != &other)
		_numbers = other.getNumbers();

	return (*this);
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

template <typename T>
T	&PmergeMe<T>::getNumbers(void)
{
	return (_numbers);
}

template <typename T>
void	PmergeMe<T>::printNumbers(void)
{
	for (typename T::iterator it = _numbers.begin(); it != _numbers.end(); it++)
		std::cout << " " << *it;
}

template <typename T>
void	PmergeMe<T>::printInfo(void)
{
	std::string	name = typeid(_numbers).name();
	name = name.substr(3, name.size() - 11);
	
	std::cout << "Time to process a range of " << _numbers.size() \
	<< " elements with std::" << name <<  "<int> : " << _time / 1000 << " us" << '\n';
}

template <typename T>
void	PmergeMe<T>::merge(int left, int mid, int right)
{
	int	len1 = mid - left + 1;
	int	len2 = right - mid;

	int	arr1[len1];
	int	arr2[len2];

	for (int i = 0; i < len1; i++)
		arr1[i] = _numbers[left + i];
	for (int i = 0; i < len2; i++)
		arr2[i] = _numbers[mid + 1 + i];

	int	idx1 = 0;
	int	idx2 = 0;
	int	idxNum = left;
	
	while (idx1 < len1 && idx2 < len2)
	{
		if (arr1[idx1] <= arr2[idx2])
			_numbers[idxNum] = arr1[idx1++];
		else
			_numbers[idxNum] = arr2[idx2++];
		
		idxNum++;
	}
	
	while (idx1 < len1)
		_numbers[idxNum++] = arr1[idx1++];

	while (idx2 < len2)
		_numbers[idxNum++] = arr2[idx2++];
}

template <typename T>
void	PmergeMe<T>::mergeSort(int begin, int end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	this->mergeSort(begin, mid);
	this->mergeSort(mid + 1, end);
	this->merge(begin, mid, end);
}

template <typename T>
void	PmergeMe<T>::mergeInsert(void)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	this->mergeSort(0, _numbers.size() - 1);
	
	gettimeofday(&end, NULL);
	_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec / 1000);
}

template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;