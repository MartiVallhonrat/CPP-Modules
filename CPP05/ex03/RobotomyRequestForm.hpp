#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	/* data */
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const &executor) const;
};

#endif