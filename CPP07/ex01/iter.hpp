#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename A, typename L, typename F>
void	iter(A *arr, L len, F f)
{
	if (!arr || !f)
	{
		std::cout << "Invalid input!" << '\n';
		return;
	}
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	print_value(T &t)
{
	std::cout << "print: " << t << '\n';
}

#endif