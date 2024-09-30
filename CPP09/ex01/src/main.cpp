# include "../RPN.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Too few or too many arguments!" << '\n';
		return (1);
	}
	std::string input = argv[1];
	if (input.empty())
		return (0);

	try
	{
		RPN	formula(input);
		formula.calculate();
	}
	catch (const RPN::BadInputException &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return (0);
}
