# include "../Bureaucrat.hpp"

int	main(void)
{
	std::cout << "_______TEST 1_______" << std::endl;
	try
	{
		Bureaucrat	test1("test1", 150);
		Bureaucrat	test2("test2", 1);
		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;

		Form	form("exampleForm", false, 75, 75);

		std::cout << form << std::endl;

		test2.signForm(form);
		test1.signForm(form);

		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}