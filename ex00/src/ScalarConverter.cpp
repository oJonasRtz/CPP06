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

template<>
void	ScalarConverter::printMessage<float>(const std::string &type, const float &message)
{
	std::cout << BLUE << 
		type <<
		":\t\t" <<
		ORANGE <<
		std::fixed << std::setprecision(1) <<
		message
		<< "f\n" RESET;
}

template<>
void	ScalarConverter::printMessage<double>(const std::string &type, const double &message)
{
	std::cout << BLUE << 
		type <<
		":\t\t" <<
		ORANGE <<
		std::fixed << std::setprecision(1) <<
		message
		<< "\n" RESET;
}

void	ScalarConverter::makeChar(std::string &str)
{
	if (str.size() == 1)
	{
		std::string	out;

		out = (!std::isprint(str[0])) ? "Non displayable" : str;

		printMessage("char", out);
		return;
	}
	if (str == "nan" || str == "NAN")
		return (printMessage("char", "impossible"));
	
	printMessage("char", "\'*\'");
}
void	ScalarConverter::makeInt(std::string &str)
{
	if (str == "nan" || str == "NAN")
		return (printMessage("int",  "impossible"));

	int	i = std::atoi(str.c_str());

	printMessage("int", i);
}
void	ScalarConverter::makeFloat(std::string &str)
{
	float	f = std::atof(str.c_str());

	printMessage("float", f);
	return;
}
void	ScalarConverter::makeDouble(std::string &str)
{
	double	d = std::atof(str.c_str());

	printMessage("double", d);
	return;
}

static void	message(const std::string &message)
{
	std::cout << BRIGHT_RED << message << "\n" RESET;
}

void	ScalarConverter::convert(std::string &str)
{
	if (str[0] == '.')
		return (message("Error: invalid input."));

	makeChar(str);
	makeInt(str);
	makeFloat(str);
	makeDouble(str);
}
