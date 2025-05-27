#ifndef B_HPP
#define B_HPP

# define BRIGHT_RED "\033[1;31m"
# define BLUE "\033[38;5;117m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>

class B
{
	private:
		/* data */
	public:
		B();
		B(const B &other);
		B	&operator=(const B &other);
		~B();
};

std::ostream	&operator<<(std::ostream &out, const B &other);

#endif