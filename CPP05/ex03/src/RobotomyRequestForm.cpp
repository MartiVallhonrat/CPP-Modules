# include "../RobotomyRequestForm.hpp"
# include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()\
: AForm("default", false, 145, 137)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string name)\
: AForm(name, false, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &target) const
{
	std::srand(time(NULL));
	int	randomNum = std::rand();
	
	std::cout << "* Some drilling noises *" << std::endl;
	
	if (randomNum % 2 == 0)
	{
		std::cout << target.getName() \
		<< " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed at " \
		<< target.getName() << std::endl;
	}
}