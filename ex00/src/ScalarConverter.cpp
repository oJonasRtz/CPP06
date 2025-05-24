#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << BRIGHT_GREEN "ScalarConverter: constructor called\n" RESET;
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << BRIGHT_GREEN "ScalarConverter: copy constructor called\n" RESET;
	*this = other;
}
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << BRIGHT_GREEN "ScalarConverter: assignment operator\n" RESET;
	if (this != &other)
		/*	copy	*/
	return (*this);
}
ScalarConverter::~ScalarConverter()
{
	std::cout << BRIGHT_RED "ScalarConverter: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const ScalarConverter &other)
{
	(void)other;
	out << "temp";
	return (out);
}
