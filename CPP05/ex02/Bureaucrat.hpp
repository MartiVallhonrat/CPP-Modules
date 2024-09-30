#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &other);

	class GradeTooHighException: public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		const char* what() const throw();
	};

	std::string	getName() const;
	int			getGrade() const;
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm &form);
	void	executeForm(AForm const &target);
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &other);

#endif