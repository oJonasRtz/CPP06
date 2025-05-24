#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>

class ScalarConverter
{
	private:
		/* data */
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();
};

std::ostream	&operator<<(std::ostream &out, const ScalarConverter &other);

#endif