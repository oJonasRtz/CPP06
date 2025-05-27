#ifndef C_HPP
#define C_HPP

# define BRIGHT_RED "\033[1;31m"
# define BLUE "\033[38;5;117m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>

class C
{
	private:
		/* data */
	public:
		C();
		C(const C &other);
		C	&operator=(const C &other);
		~C();
};

std::ostream	&operator<<(std::ostream &out, const C &other);

#endif