#include "identify.hpp"

Base	*generate(void)
{
	int	r = std::rand() % 3;

	switch (r)
	{
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
	}
	return (NULL);
}
void	identify(Base *p)
{
	if (!p)
	{
		std::cout << BRIGHT_RED "Error: invalid input\n" RESET;
		return;
	}

	if (dynamic_cast<A*>(p))
		std::cout << ORANGE "Pointer == A()\n" RESET;
	else if (dynamic_cast<B*>(p))
		std::cout << ORANGE "Pointer == B()\n" RESET;
	else if (dynamic_cast<C*>(p))
		std::cout << ORANGE "Pointer == C()\n" RESET;
	else
		std::cout << ORANGE "Pointer == Base\n" RESET;
	return;
}
void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << ORANGE "Pointer == A()\n" RESET;
		return;
	}catch (const std::exception&){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << ORANGE "Pointer == B()\n" RESET;
		return;
	}catch (const std::exception&){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << ORANGE "Pointer == C()\n" RESET;
		return;
	}catch (const std::exception&){}

	std::cout << ORANGE "Pointer == Base\n" RESET;
}
