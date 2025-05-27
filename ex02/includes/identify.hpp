#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

typedef struct s_map
{
	std::string	test;
	void	(*f)(void);
}	t_map;

#endif