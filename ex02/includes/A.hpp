#ifndef A_HPP
#define A_HPP

# define BRIGHT_RED "\033[1;31m"
# define BLUE "\033[38;5;117m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>

class A
{
	private:
		/* data */
	public:
		A();
		A(const A &other);
		A	&operator=(const A &other);
		~A();
};

std::ostream	&operator<<(std::ostream &out, const A &other);

#endif