# include "../Form.hpp"

Form::Form(): _name("default"), _isSigned(false),\
_requiredGradeSign(75), _requiredGradeExec(75)
{
}

Form::Form(const Form &other): _name(other._name),\
_isSigned(other._isSigned), _requiredGradeSign(other._requiredGradeSign),\
_requiredGradeExec(other._requiredGradeExec)
{
}

Form::Form(std::string name, bool isSigned,\
int requiredGradeSign, int requiredGradeExec)
: _name(name), _isSigned(isSigned),\
_requiredGradeSign(requiredGradeSign),\
 _requiredGradeExec(requiredGradeExec)
{
}

Form::~Form()
{
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getRequiredGradeSign() const
{
	return (_requiredGradeSign);
}

int	Form::getRequiredGradeExec() const
{
	return (_requiredGradeExec);
}

void	Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->_requiredGradeSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream	&operator<<(std::ostream &o, const Form &other)
{
	o << other.getName() << ", is signed: "\
	<< other.getIsSigned() << ", required grade to sign: "\
	<< other.getRequiredGradeSign()\
	<< ", required grade to execute: "\
	<< other.getRequiredGradeExec();
	return (o);
}