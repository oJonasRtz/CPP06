#include <iostream>
#include "ScalarConverter.hpp"

static int	error(void)
{
	std::cout << BRIGHT_RED "How to use: ./scalar <value>\n" RESET;
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (error());

	std::string	str = argv[1];
	ScalarConverter::convert(str);
	return (0);
}

