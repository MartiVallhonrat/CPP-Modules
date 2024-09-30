# include "../AForm.hpp"

AForm::AForm(): _name("default"), _isSigned(false),\
_requiredGradeSign(75), _requiredGradeExec(75)
{
}

AForm::AForm(const AForm &other): _name(other._name),\
_isSigned(other._isSigned), _requiredGradeSign(other._requiredGradeSign),\
_requiredGradeExec(other._requiredGradeExec)
{
}

AForm::AForm(std::string name, bool isSigned,\
int requiredGradeSign, int requiredGradeExec)
: _name(name), _isSigned(isSigned),\
_requiredGradeSign(requiredGradeSign),\
 _requiredGradeExec(requiredGradeExec)
{
}

AForm::~AForm()
{
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char	*AForm::IsSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getRequiredGradeSign() const
{
	return (_requiredGradeSign);
}

int	AForm::getRequiredGradeExec() const
{
	return (_requiredGradeExec);
}

void	AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->_requiredGradeSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::checkExecutor(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw IsSignedException();
	if (executor.getGrade() > this->_requiredGradeExec)
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, const AForm &other)
{
	o << other.getName() << ", is signed: "\
	<< other.getIsSigned() << ", required grade to sign: "\
	<< other.getRequiredGradeSign()\
	<< ", required grade to execute: "\
	<< other.getRequiredGradeExec();
	return (o);
}