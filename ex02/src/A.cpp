#include "A.hpp"

A::A(void)
{
	std::cout << BRIGHT_GREEN "A: constructor called\n" RESET;
}

A::~A(void)
{
	std::cout << BRIGHT_RED "A: destructor called\n" RESET;
}
