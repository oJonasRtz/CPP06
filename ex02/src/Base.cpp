#include "Base.hpp"

Base::Base()
{
	std::cout << BRIGHT_GREEN "Base: constructor called\n" RESET;
}
Base::Base(const Base &other)
{
	std::cout << BRIGHT_GREEN "Base: copy constructor called\n" RESET;
	*this = other;
}
Base&	Base::operator=(const Base &other)
{
	std::cout << BRIGHT_GREEN "Base: assignment operator\n" RESET;
	if (this != &other)
		/*	copy	*/
	return (*this);
}
Base::~Base()
{
	std::cout << BRIGHT_RED "Base: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const Base &other)
{
	(void)other;
	out << "temp";
	return (out);
}
