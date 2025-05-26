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

static bool	simpleCheck(std::string &str)
{
	return (str == "nan" || str == "nanf"
		|| str == "+inf" || str == "+inff"
		|| str == "-inf" || str == "-inff");
}

std::string	ScalarConverter::makeChar(std::string &str)
{
	if (simpleCheck(str)
		|| (str.size() > 1 && !std::isdigit(str[0]) && str[0] != '-'))
		return ("impossible");

	if (std::isdigit(str[0]) || std::isdigit(str[1]))
	{
		int	i = std::atoi(str.c_str());
		if (!std::isprint(i))
			return ("Non displayable");
		return ("'" + std::string(1, static_cast<char>(i)) + "'");
	}

	//str.size() == 1  && std::isdigit(str[0]);
	return ("'" + str + "'");
}
std::string	ScalarConverter::makeInt(std::string &str)
{
	if (simpleCheck(str))
		return ("impossible");

	std::ostringstream os;
	os << std::atoi(str.c_str());

	return (os.str());
}
float	ScalarConverter::makeFloat(std::string &str)
{
	return (std::atof(str.c_str()));
}
double	ScalarConverter::makeDouble(std::string &str)
{
	return (std::atof(str.c_str()));
}

static void	message(const std::string &message)
{
	std::cout << BRIGHT_RED << message << "\n" RESET;
}

void	ScalarConverter::convert(std::string &str)
{
	if (str[0] == '.' && std::isdigit(str[1]))
		return (message("Error: invalid input."));

	printMessage("char", makeChar(str));
	printMessage("int", makeInt(str));
	printMessage("float", makeFloat(str));
	printMessage("double", makeDouble(str));
}
