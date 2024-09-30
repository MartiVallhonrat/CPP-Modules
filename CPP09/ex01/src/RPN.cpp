# include "../RPN.hpp"
# include <stack>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	if (this != &other)
	{
		std::list<char> oFormula = other.getFormula();
		for (iter it = oFormula.begin(); it != oFormula.end(); it++)
			_formula.push_back(*it);
	}
}

void	RPN::isBadInput(std::string &input)
{
	int	opCount = 0;
	int nCount = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (isOperator(input[i]))
			opCount++;
		if (isNumber(input[i]))
			nCount++;
		if (!isOperator(input[i]) && !isNumber(input[i]) && !std::isspace(input[i]))
			throw BadInputException();
	}
	if (nCount < 2 || opCount < 1)
		throw BadInputException();
}

void	RPN::setList(std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
		_formula.push_back(input[i]);
}

RPN::RPN(std::string input)
{
	isBadInput(input);
	setList(input);
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_formula.clear();
		std::list<char> oFormula = other.getFormula();
		for (iter it = oFormula.begin(); it != oFormula.end(); it++)
			_formula.push_back(*it);
	}
	return (*this);
}

RPN::~RPN()
{
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

bool	RPN::isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

std::list<char>	RPN::getFormula(void) const
{
	return (_formula);
}

void	RPN::calculate(void)
{
	int		isMinus = 1;
	bool	isFirstNum = true;
	char	op = '\0';
	int		n1;
	std::list<int>	n2;

	for (iter it = _formula.begin(); it != _formula.end(); it++)
	{
		if (isNumber(*it))
		{
			if (isFirstNum)
			{
				n1 = *it - '0';
				isFirstNum = false;
			}
			else
				n2.push_back(*it - '0');
		}
		else if (std::isspace(*it))
		{
			if (isMinus == -1)
			{
				if (!op)
					op = '-';
				isMinus = 1;
			}
		}
		else if (isOperator(*it))
		{
			iter temp_iter = it;
			temp_iter++;
			if (!op && (*it != '-' || temp_iter == _formula.end()))
				op = *it;
			else if (*it == '-')
				isMinus = -1;
		}
		if (!n2.empty() && op)
		{
			std::cout << n1 << " " << op << " " << (n2.front() * isMinus) << '\n';
			switch (op)
			{
				case '+':
					n1 = n1 + (n2.front() * isMinus);
					n2.pop_front();
					break;
				case '-':
					n1 = n1 - (n2.front() * isMinus);
					n2.pop_front();
					break;
				case '*':
					n1 = n1 * (n2.front() * isMinus);
					n2.pop_front();
					break;
				case '/':
					if (n2.front() == 0)
					{
						std::cerr << "Error: Can't divide by 0" << '\n';
						exit(1);
					}
					n1 = n1 / (n2.front() * isMinus);
					n2.pop_front();
					break;
			}
			op = '\0';
		}
	}
	std::cout << n1 << '\n';
}