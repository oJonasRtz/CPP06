#ifndef C_HPP
#define C_HPP

# define BRIGHT_RED "\033[1;31m"
# define BLUE "\033[38;5;117m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>
#include "Base.hpp"

class C: public Base
{
	public:
		C(void);
		~C(void);
};


#endif