#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_requiredGradeSign;
	const int			_requiredGradeExec;
public:
	AForm();
	AForm(std::string name, bool isSigned, int requiredGradeSign, int requiredGradeExec);
	AForm(const AForm	&other);
	virtual ~AForm();

	AForm	&operator=(const AForm &other);

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

	class IsSignedException: public std::exception
	{
	public:
		const char* what() const throw();
	};

	void		beSigned(const Bureaucrat &signer);
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getRequiredGradeSign() const;
	int			getRequiredGradeExec() const;

	void			checkExecutor(Bureaucrat const &executor) const;
	virtual	void	execute(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &o, const AForm &other);

#endif