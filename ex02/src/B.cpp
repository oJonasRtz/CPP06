#include "B.hpp"

B::B(void)
{
	std::cout << BRIGHT_GREEN "B: constructor called\n" RESET;
}

B::~B(void)
{
	std::cout << BRIGHT_RED "B: destructor called\n" RESET;
}

