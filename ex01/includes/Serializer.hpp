#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# define BRIGHT_RED "\033[1;31m"
# define BLUE "\033[38;5;117m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer	&operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

std::ostream	&operator<<(std::ostream &out, const Serializer &other);

#endif