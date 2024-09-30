# include "../Bureaucrat.hpp"

int	main(void)
{
	std::cout << "_______TEST 1_______" << std::endl;
	try
	{
		Bureaucrat	test1_1("test1_1", 150);
		std::cout << test1_1 << std::endl;
		std::cout << std::endl;

		test1_1.decrementGrade();

		std::cout << std::endl;
		std::cout << test1_1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat	test1_2("test1_2", 1);
		std::cout << test1_2 << std::endl;
		std::cout << std::endl;

		test1_2.incrementGrade();

		std::cout << std::endl;
		std::cout << test1_2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "_______TEST 2_______" << std::endl;
	try
	{
		Bureaucrat	test2_1("test2_1", -23);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	test2_2("test2_2", 300);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}