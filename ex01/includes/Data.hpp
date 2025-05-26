#ifndef DATA_HPP
#define DATA_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>

typedef struct s_data
{
	std::string	name;
	double		lifePts;
	std::string	role;
	int			dmg;
}	Data;

#endif