# include "../Span.hpp"

int	main(void)
{
	std::cout << "____TEST 1____" << '\n';
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << '\n' << '\n';

	std::cout << "____TEST 2____" << '\n';
	Span sp2 = Span(10);
	sp2.fillDefault();
	unsigned int sp2_size = sp2.getSize();
	for (unsigned int i = 0; i < sp2_size; i++)
	{
		std::cout << "Span position " \
		<< i << ": " << sp2.getIdx(i) << '\n'; 
	}

	std::cout << '\n' << '\n';

	std::cout << "____TEST 3____" << '\n';
	Span sp3 = Span(10000);
	for (size_t i = 0; i < 10000; i++)
		sp3.addNumber(i);
	
	for (size_t i = 0; i < sp3.getSize(); i++)
		std::cout << sp3.getIdx(i) << '\n';
	
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return (0);
}