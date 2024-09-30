#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	/* data */
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern	&operator=(const Intern &other);

	class NonExistentException: public std::exception
	{
	public:
		const char* what() const throw();
	};

	AForm	*makeForm(const std::string &name, const std::string &target);
};

#endif