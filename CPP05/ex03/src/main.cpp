# include "../Bureaucrat.hpp"
# include "../ShrubberyCreationForm.hpp"
# include "../RobotomyRequestForm.hpp"
# include "../PresidentialPardonForm.hpp"
# include "../Intern.hpp"

int	main(void)
{
	AForm *form1;
	AForm *form2;
	AForm *form3;

	try
	{
		std::cout << "_______TEST 1_______" << std::endl;
		Bureaucrat	test1("test1", 150);
		Bureaucrat	test2("test2", 1);

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;

		Intern	someRandomIntern;

		form1 = someRandomIntern.makeForm("presidential pardin", "exampleForm1");
		std::cout << *form1 << std::endl;

		test2.signForm(*form1);

		std::cout << *form1 << std::endl;

		test2.executeForm(*form1);
		test1.executeForm(*form1);

		delete form1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "_______TEST 2_______" << std::endl;
		Bureaucrat	test1("test1", 150);
		Bureaucrat	test2("test2", 1);

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;

		Intern	someRandomIntern;

		form2 = someRandomIntern.makeForm("robotomy request", "exampleForm2");
		std::cout << *form2 << std::endl;

		test2.signForm(*form2);

		std::cout << *form2 << std::endl;

		test2.executeForm(*form2);
		test1.executeForm(*form2);
	
		delete form2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "_______TEST 3_______" << std::endl;
		Bureaucrat	test1("test1", 150);
		Bureaucrat	test2("test2", 1);

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;

		Intern	someRandomIntern;

		form3 = someRandomIntern.makeForm("shrubbery creation", "exampleForm3");
		std::cout << *form3 << std::endl;

		test2.signForm(*form3);

		std::cout << *form3 << std::endl;

		test2.executeForm(*form3);
		test1.executeForm(*form3);

		delete form3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}