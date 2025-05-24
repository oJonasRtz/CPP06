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
	// if (this != &other)
	// 	/*	copy	*/
	(void)other;
	return (*this);
}
ScalarConverter::~ScalarConverter()
{
	std::cout << BRIGHT_RED "ScalarConverter: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const ScalarConverter &other)
{
	(void)other;
	out << "Scalar";
	return (out);
}

void	ScalarConverter::makeChar(std::string &str)
{
	int	i = std::atoi(str.c_str());
	if (i <= 32 || i >= 126)
		std::cout << BLUE "char:\t\t" ORANGE << "Non displayable" << "\n" RESET;
	else
		std::cout << BLUE "char:\t\t" ORANGE << (char)i << "\n" RESET;
	
	if (str.size() == 1)
		std::cout << BLUE "char:\t\t" ORANGE << str << "\n" RESET;
	else
		std::cout << BLUE "char:\t\t" ORANGE << "\'*\'" << "\n" RESET;
}
void	ScalarConverter::makeInt(std::string &str)
{
	int	i = std::atoi(str.c_str());

	std::cout << BLUE "int:\t\t"
		ORANGE << i << "\n" RESET;
}
void	ScalarConverter::makeFloat(std::string &str)
{
	float	f = std::atof(str.c_str());

	std::cout << BLUE "float:\t\t" <<
		ORANGE <<
		std::fixed << std::setprecision(1) <<
		f << "f\n" RESET;
	return;
}
void	ScalarConverter::makeDouble(std::string &str)
{
	double	d = std::atof(str.c_str());

	std::cout << BLUE "double:\t\t" << 
		ORANGE <<
		std::fixed << std::setprecision(1) <<
		d << "\n" RESET;
	return;
}

void	ScalarConverter::convert(std::string &str)
{
	makeChar(str);
	makeInt(str);
	makeFloat(str);
	makeDouble(str);
}
