#include "C.hpp"

C::C()
{
	std::cout << BRIGHT_GREEN "C: constructor called\n" RESET;
}
C::C(const C &other)
{
	std::cout << BRIGHT_GREEN "C: copy constructor called\n" RESET;
	*this = other;
}
C&	C::operator=(const C &other)
{
	std::cout << BRIGHT_GREEN "C: assignment operator\n" RESET;
	if (this != &other)
		/*	copy	*/
	return (*this);
}
C::~C()
{
	std::cout << BRIGHT_RED "C: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const C &other)
{
	(void)other;
	out << "temp";
	return (out);
}
