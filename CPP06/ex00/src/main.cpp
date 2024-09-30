# include "../ScalarConverter.hpp"

static bool	isAlphaStr(std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (std::isprint(input[i]) && (input[i] >= '0' && input[i] <= '9'))
			return (false);
	}
	return (true);
}

static bool	isAlphaAndNum(std::string &input)
{
	bool trigA = false;
	bool trigN = false;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (std::isdigit(input[i]))
			trigN = true;
		if (std::isprint(input[i]) && input[i] != 'f' && input[i] != '.' && input[i] != '-' && !(input[i] >= '0' && input[i] <= '9'))
			trigA = true;
		if (trigA && trigN)
			return (true);
	}
	return (false);
}

int	handleExceptions(std::string &input, t_values &values)
{
	if (input.empty())
	{
		values.cType = "impossible";
		values.intType = "impossible";
		values.floatType = "impossible";
		values.doubleType = "impossible";
		return (1);	
	}
	else if (input == "nan" || input == "nanf")
	{
		values.cType = "impossible";
		values.intType = "impossible";
		values.floatType = "nanf";
		values.doubleType = "nan";
		return (1);
	}
	else if (input == "-inf")
	{
		values.cType = "impossible";
		values.intType = "-inf";
		values.floatType = "-inff";
		values.doubleType = "-inf";
		return (1);
	}
	else if (input == "+inf")
	{
		values.cType = "impossible";
		values.intType = "+inf";
		values.floatType = "+inff";
		values.doubleType = "+inf";
		return (1);
	}
	else if (input == "-inff")
	{
		values.cType = "impossible";
		values.intType = "-inf";
		values.floatType = "-inff";
		values.doubleType = "-inf";
		return (1);
	}
	else if (input == "+inff")
	{
		values.cType = "impossible";
		values.intType = "+inf";
		values.floatType = "+inff";
		values.doubleType = "+inf";
		return (1);
	}
	if (isAlphaStr(input) || isAlphaAndNum(input))
	{
		if (input.size() > 1)
		{
			values.cType = "impossible";
			values.intType = "impossible";
			values.floatType = "impossible";
			values.doubleType = "impossible";
			return (1);
		}
		std::ostringstream	ostreamChar;
		ostreamChar << static_cast<int>(input[0]);
		input = ostreamChar.str();
	}
	return (0);
}

void printValues(t_values &values)
{
	std::cout << "char: " << values.cType << '\n' \
	<< "int: " << values.intType << '\n' \
	<< "float: " << values.floatType << '\n' \
	<< "double: " << values.doubleType << '\n';
}

void	parseFloat(std::string &input)
{
	if (input[input.size() - 1] == 'f')
		input = input.substr(0, input.size() - 1);
}

static void setInt(int vInt, t_values &values)
{
	std::ostringstream	ostrInt;

	ostrInt << vInt;
	values.intType = ostrInt.str();
	values.vInt = vInt;
}

static void setFloat(float vFloat, t_values &values)
{
	std::ostringstream	ostrFloat;

	ostrFloat << vFloat;
	values.floatType = ostrFloat.str();
	if (values.floatType.find('.') != std::string::npos)
		values.floatType += "f";
	else
		values.floatType += ".0f";
}

static void setDouble(double vDouble, t_values &values)
{
	std::ostringstream	ostrDouble;

	ostrDouble << vDouble;
	values.doubleType = ostrDouble.str();
	if (values.doubleType.find('.') == std::string::npos)
		values.doubleType += ".0";
}

void	convertNumbers(std::string &input, t_values &values)
{
	int		vInt;
	float	vFloat;
	double	vDouble;

	vDouble = std::strtod(input.c_str(), NULL);
	vFloat = static_cast<float>(vDouble);
	vInt = static_cast<int>(vDouble);
	
	setInt(vInt, values);
	setFloat(vFloat, values);
	setDouble(vDouble, values);
}

void	convertChar(t_values &values)
{
	if (values.vInt < 32 || values.vInt > 126)
	{
		values.cType = "Non displayable";
		return;
	}
	values.cType = "'";
	values.cType += static_cast<char>(values.vInt);
	values.cType += "'";
}

int	main(int argc, char *argv[])
{
	t_values	values;

	if (argc != 2)
	{
		std::cerr << "Invalid num of params!" << '\n';
		return (1);
	}

	std::string input = argv[1];
	ScalarConverter::convert(input);

	return (0);
}