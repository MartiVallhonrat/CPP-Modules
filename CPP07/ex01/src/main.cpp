# include "../iter.hpp"

int	main(void)
{
	char	char_arr[] = {'a', 'b', 'c'};
	int	char_int[] = {1, 2, 3};

	std::cout << "____TEST 1____" << '\n';
	::iter(char_arr, 3, ::print_value<char>);

	std::cout << '\n' << '\n';

	std::cout << "____TEST 2____" << '\n';
	::iter(char_int, 3, ::print_value<int>);
}