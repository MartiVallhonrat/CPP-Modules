# include "../Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
	if (this != &other)
		_grade = other._grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;

	return (*this);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (const GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return;
	}
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return;
	}
	_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " \
		<< form.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << this->_name << " couldn't sign " \
		<< form.getName() << " because " \
		<< e.what() << std::endl;
	}	
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.checkExecutor(*this);
		form.execute(*this);
		std::cout << this->_name \
		<< " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " \
		<< form.getName() << " because " \
		<< e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &other)
{
	o << other.getName() << ", bureaucrat grade "\
	<< other.getGrade();
	return (o);
}