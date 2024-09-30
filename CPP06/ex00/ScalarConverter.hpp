#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <cctype>

typedef struct s_values
{
	std::string	cType;
	std::string	intType;
	std::string	floatType;
	std::string	doubleType;
	int			vInt;
}				t_values;

void	printValues(t_values &values);
int		handleExceptions(std::string &input, t_values &values);
void	parseFloat(std::string &input);
void	convertNumbers(std::string &input, t_values &values);
void	convertChar(t_values &values);

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();

    ScalarConverter &operator=(const ScalarConverter &other);

public:
    static void convert(std::string &input);
};

#endif