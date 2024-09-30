#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm 
{
private:
	/* data */
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name);
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const &executor) const;
};

#endif