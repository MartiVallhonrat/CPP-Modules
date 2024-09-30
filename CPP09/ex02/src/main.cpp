# include "../PmergeMe.hpp"

int main(int argc, char *argv[])
{
	//containers are vector and deque
	if (argc < 2)
	{
		std::cerr << "Error: Too few arguments!" << '\n';
		return (1);
	}
	try
	{
		PmergeMe< std::vector<int> > test(argc, argv);
		PmergeMe< std::deque<int> > test2(argc, argv);

		std::cout << "Before:";
		test.printNumbers();
		std::cout << '\n';

		test.mergeInsert();
		test2.mergeInsert();

		std::cout << "After:";
		test.printNumbers();
		std::cout << '\n';

		test.printInfo();
		test2.printInfo();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}