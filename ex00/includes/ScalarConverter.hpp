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
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();
		
		static std::string	makeChar(std::string &str);
		static std::string	makeInt(std::string &str);
		static std::string	makeFloat(std::string &str);
		static std::string	makeDouble(std::string &str);
		template<typename T>
		static void	printMessage(const std::string &type, const T &message)
		{
			std::cout << BLUE <<
					type <<
					":\t\t" <<
					ORANGE <<
					message <<
					"\n" << RESET;
		}
	public:
		static void	convert(std::string &str);
};

std::ostream	&operator<<(std::ostream &out, const ScalarConverter &other);

#endif