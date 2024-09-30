# include "../Span.hpp"

Span::Span(): _size(0), _maxSize(0)
{
	this->_container.resize(_size);
}

Span::Span(unsigned int N): _size(0), _maxSize(N)
{
	this->_container.resize(_size);
}

Span::Span(const Span &other): _size(other.getSize()), _maxSize(other.getMaxSize())
{
	if (this != &other)
	{
		_container.resize(_size);
		for (unsigned int i = 0; i < _size; i++)
		{
			_container[i] = other.getIdx(i);
		}
	}	
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other.getSize();
		_maxSize = other.getMaxSize();
		_container.resize(_size);
		for (unsigned int i = 0; i < _size; i++)
		{
			_container[i] = other.getIdx(i);
		}
	}	
	return (*this);
}

Span::~Span()
{
}

unsigned int	Span::getSize(void) const
{
	return(_size);
}

unsigned int Span::getMaxSize(void) const
{
	return (_maxSize);
}

int	Span::getIdx(unsigned int idx) const
{
	try
	{
		if (idx >= _size)
			throw InvalidIdxException();
		
		return (_container[idx]);
	}
	catch(const InvalidIdxException& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (-1);
}

void	Span::addNumber(int num)
{
	try
	{
		if (_size + 1 > _maxSize)
			throw FullException();
		
		_size++;
		_container.push_back(num);
	}
	catch(const FullException& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

int	Span::shortestSpan(void)
{
	try
	{
		int shortest = 2147483647;

		if (_size < 2)
			throw FewElementsException();

		std::sort(_container.begin(), _container.end());
		std::vector<int>::iterator it = _container.begin();
		it++;

		while (it != _container.end())
		{
			if (*it - *(it - 1) < shortest)
				shortest = *it - *(it - 1);
			it++;
		}
		
		return (shortest);	
	}
	catch(const FewElementsException &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (-1);
	}
}

int	Span::longestSpan(void)
{
	try
	{
		if (_size < 2)
			throw FewElementsException();

		return (*max_element(_container.begin(), _container.end()) \
			- *min_element(_container.begin(), _container.end()));
	}
	catch(const FewElementsException &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (-1);
	}
}

void			Span::fillDefault(void)
{
	_size = _maxSize;
	_container.resize(_maxSize);
	std::fill(_container.begin(), _container.end(), 1);
}