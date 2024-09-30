# include "../Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

const char	*Intern::NonExistentException::what() const throw()
{
	return ("This form doesn't exist!");
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	size_t	i;
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm	*form;

	for (i = 0; i < 3; i++)
	{
		if (name == forms[i])
			break;
	}
		
	switch (i)
	{
	case 0:
		form = new PresidentialPardonForm(target);
		break;
	
	case 1:
		form = new RobotomyRequestForm(target);
		break;
	
	case 2:
		form = new ShrubberyCreationForm(target);
		break;
	
	default:
		throw NonExistentException();
		break;
	}

	std::cout << "Intern creates " << target << std::endl;
	return (form);
}