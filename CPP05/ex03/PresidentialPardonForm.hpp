#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm: public AForm 
{
private:
	/* data */
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name);
	~PresidentialPardonForm();

	void	execute(Bureaucrat const &executor) const;
};

#endif