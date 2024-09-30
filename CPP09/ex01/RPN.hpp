#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <list>
# include <cstdlib>
# include <exception>
# include <algorithm>

class RPN
{
typedef std::list<char>::iterator iter;
private:
	std::list<char> _formula;

	bool	isOperator(char c);
	bool	isNumber(char c);
	void	isBadInput(std::string &input);
	void	setList(std::string &input);

public:
	RPN();
	RPN(std::string input);
	RPN(const RPN &other);
	~RPN();

	RPN	&operator=(const RPN &other);

	class BadInputException: public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Bad Input");
		}
	};

	std::list<char>	getFormula(void) const;
	void			calculate(void);
};

#endif