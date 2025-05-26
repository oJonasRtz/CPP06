#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << BRIGHT_GREEN "Serializer: constructor called\n" RESET;
}
Serializer::Serializer(const Serializer &other)
{
	std::cout << BRIGHT_GREEN "Serializer: copy constructor called\n" RESET;
	*this = other;
}
Serializer&	Serializer::operator=(const Serializer &other)
{
	std::cout << BRIGHT_GREEN "Serializer: assignment operator\n" RESET;
	// if (this != &other)
	// 	/*	copy	*/
	(void)other;
	return (*this);
}
Serializer::~Serializer()
{
	std::cout << BRIGHT_RED "Serializer: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const Serializer &other)
{
	(void)other;
	out << "Serializer";
	return (out);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
