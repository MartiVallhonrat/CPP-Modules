# include "../Array.hpp"

int	main(void)
{
	Array<int> test(3);

	std::cout << "test size: " << test.size() << '\n';

	try
	{
		for (int i = 0; i < 3; i++)
			test[i] = i;
		
		std::cout << "test[0]: " << test[0] << '\n' \
		<< "test[1]: " << test[1] <<  '\n' \
		<< "test[2]: " << test[2] <<  '\n';

		Array<int> test2 = test;
		test2[0] = -1;

		std::cout << "test2[0]: " << test2[0] << '\n' \
		<< "test2[1]: " << test2[1] <<  '\n' \
		<< "test2[2]: " << test2[2] <<  '\n';

		//test[3];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}