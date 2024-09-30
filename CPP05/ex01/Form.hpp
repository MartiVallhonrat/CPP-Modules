#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_requiredGradeSign;
	const int			_requiredGradeExec;
public:
	Form();
	Form(std::string name, bool isSigned, int requiredGradeSign, int requiredGradeExec);
	Form(const Form	&other);
	~Form();

	Form	&operator=(const Form &other);

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

	void	beSigned(const Bureaucrat &signer);
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getRequiredGradeSign() const;
	int			getRequiredGradeExec() const;

};

std::ostream	&operator<<(std::ostream &o, const Form &other);

#endif