# include "../Base.hpp"

Base::~Base()
{
}

Base	*generate(void)
{
	srand(time(NULL));

	int ranNum = rand() % 3;
	std::cout << ranNum << '\n';
	switch (ranNum)
	{
		case 0:
			return (new A);
			break;
		case 1:
			return (new B);
			break;
		case 2:
			return (new C);
			break;
	}
	return (NULL);
}

void	identify(Base *p)
{
	std::string	typeClass;
	A	*pA = dynamic_cast<A*>(p);
	B	*pB = dynamic_cast<B*>(p);
	C	*pC = dynamic_cast<C*>(p);

	if (pA)
		typeClass = "A";
	else if (pB)
		typeClass = "B";
	else if (pC)
		typeClass = "C";

	std::cout << "Pointer p is class type: " << typeClass << '\n';
}

void	identify(Base &p)
{
	std::string	typeClass;
	int	i = 0;

	while (i < 3)
	{
		try
		{
			if (i == 0)
			{
				A	testA = dynamic_cast<A&>(p);
				typeClass = "A";
			}
			else if (i == 1)
			{
				B	testB = dynamic_cast<B&>(p);
				typeClass = "B";
			}
			else if (i == 2)
			{
				C	testC = dynamic_cast<C&>(p);
				typeClass = "C";
			}
			else if (i == 2)
				typeClass = "Neither";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			i++;
			continue;
		}
		break;
	}
	
	std::cout << "Reference p is class type: " << typeClass << '\n';
}