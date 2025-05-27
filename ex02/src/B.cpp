#include "B.hpp"

B::B()
{
	std::cout << BRIGHT_GREEN "B: constructor called\n" RESET;
}
B::B(const B &other)
{
	std::cout << BRIGHT_GREEN "B: copy constructor called\n" RESET;
	*this = other;
}
B&	B::operator=(const B &other)
{
	std::cout << BRIGHT_GREEN "B: assignment operator\n" RESET;
	if (this != &other)
		/*	copy	*/
	return (*this);
}
B::~B()
{
	std::cout << BRIGHT_RED "B: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const B &other)
{
	(void)other;
	out << "temp";
	return (out);
}
