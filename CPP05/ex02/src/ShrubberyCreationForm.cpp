# include "../ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()\
: AForm("default", false, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)\
: AForm(name, false, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &target) const
{
	std::string		output = target.getName();
	std::ofstream	outputFile(output.append("_shrubbery").c_str());

	if (!outputFile.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return;
	}
	outputFile \
	<< "     *     " << std::endl \
	<< "    ***    " << std::endl \
	<< "   *****   " << std::endl \
	<< "  *******  " << std::endl \
	<< " ********* " << std::endl \
	<< "***********" << std::endl \
	<< "    |||    " << std::endl \
	<< "    |||    " << std::endl;

	outputFile.close();
}