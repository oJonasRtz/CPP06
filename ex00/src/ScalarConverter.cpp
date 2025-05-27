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

static bool	simpleCheck(std::string &str)
{
	return (str == "nan" || str == "nanf"
		|| str == "+inf" || str == "+inff"
		|| str == "-inf" || str == "-inff");
}

static bool isNum(const std::string &str)
{
	unsigned long int	start = str[0] == '-';

	for (unsigned long int i = start; i < str.size() - 1; i++)
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
	return (true);
}

static bool	stringCheck(const std::string &str)
{
	return (str.size() > 1 && !std::isdigit(str[0]) && !isNum(str));
}

std::string	ScalarConverter::makeChar(std::string &str)
{
	if (simpleCheck(str)
		|| stringCheck(str))
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
	if (simpleCheck(str) || stringCheck(str))
		return ("impossible");

	std::ostringstream os;
	if (str.size() == 1 && !std::isdigit(str[0]))
		os << static_cast<int>(str[0]);
	else
		os << std::atoi(str.c_str());

	return (os.str());
}
std::string	ScalarConverter::makeFloat(std::string &str)
{
	if (simpleCheck(str))
		return (str + "f");
	if (stringCheck(str))
		return ("impossible");

	std::ostringstream	os;
	if (str.size() == 1 && !std::isdigit(str[0]))
		os <<
		std::fixed << std::setprecision(1) << static_cast<float>(str[0]);
	else
		os <<
		std::fixed << std::setprecision(1) << std::atof(str.c_str());
	
	return (os.str() + "f");
}
std::string	ScalarConverter::makeDouble(std::string &str)
{
	if (simpleCheck(str))
		return (str);
	if (stringCheck(str))
		return ("impossible");

	std::ostringstream	os;
	if (str.size() == 1 && !std::isdigit(str[0]))
		os <<
		std::fixed << std::setprecision(1) << static_cast<double>(str[0]);
	else
		os <<
		std::fixed << std::setprecision(1) << std::atof(str.c_str());
	
	return (os.str());
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
