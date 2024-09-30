# include "../ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

void    ScalarConverter::convert(std::string &input)
{
	t_values	values;

	if(!handleExceptions(input, values))
	{
		parseFloat(input);
		convertNumbers(input, values);
		convertChar(values);
	}
	printValues(values);
}