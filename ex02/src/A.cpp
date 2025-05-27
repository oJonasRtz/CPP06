#include "A.hpp"

A::A()
{
	std::cout << BRIGHT_GREEN "A: constructor called\n" RESET;
}
A::A(const A &other)
{
	std::cout << BRIGHT_GREEN "A: copy constructor called\n" RESET;
	*this = other;
}
A&	A::operator=(const A &other)
{
	std::cout << BRIGHT_GREEN "A: assignment operator\n" RESET;
	if (this != &other)
		/*	copy	*/
	return (*this);
}
A::~A()
{
	std::cout << BRIGHT_RED "A: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const A &other)
{
	(void)other;
	out << "temp";
	return (out);
}
