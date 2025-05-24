#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# define BRIGHT_RED "\033[1;31m"
# define BLUE "\033[38;5;117m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cfloat>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();
		
		static void	makeChar(std::string &str);
		static void	makeInt(std::string &str);
		static void	makeFloat(std::string &str);
		static void	makeDouble(std::string &str);

	public:
		static void	convert(std::string &str);
};

std::ostream	&operator<<(std::ostream &out, const ScalarConverter &other);

#endif