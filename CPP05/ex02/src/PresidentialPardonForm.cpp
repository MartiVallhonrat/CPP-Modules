# include "../PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()\
: AForm("default", false, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name)\
: AForm(name, false, 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(Bureaucrat const &target) const
{
	std::cout << target.getName() \
	<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}