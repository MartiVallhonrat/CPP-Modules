# include "../easyfind.hpp"

int main(void)
{
	std::vector<int> test;
	
	for (int i = 0; i < 4; i++)
		test.push_back(i);

	std::cout << "Vector test: " << '\n';

	for(std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "\t- " << *it << '\n';

	::easyfind(test, 3);
	::easyfind(test, 4);

	return (0);
}
