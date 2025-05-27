#include "identify.hpp"

static void	generateTest(void)
{
	std::cout << ORANGE << std::string(30, '=') << "\n\tGenerate\n" << std::string(30, '=') << RESET << std::endl;
	Base	*b[10];
	for (int i = 0; i < 10; i++)
		b[i] = generate();


	std::cout << ORANGE << std::string(30, '=') << "\n\tDestructors\n" << std::string(30, '=') << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		delete b[i];
}

static void	identifyTest1(void)
{
	std::cout << ORANGE << std::string(30, '=') << "\n\tIdentify-pointer tests\n" << std::string(30, '=') << RESET << std::endl;\

	std::cout << std::string(30, '=') << "\n\tConstructors\n" << std::string(30, '=') << std::endl;
	Base	*a = new A();
	Base	*b = new B();
	Base	*c = new C();
	Base	*d = new Base();

	std::cout << std::string(30, '=') << "\n\tIdentify(Base *p)\n" << std::string(30, '=') << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(d);
	identify(NULL);

	std::cout << std::string(30, '=') << "\n\tDestructors\n" << std::string(30, '=') << std::endl;
	delete a;
	delete b;
	delete c;
	delete d;
}

static void	identifyTest2(void)
{
	std::cout << ORANGE << std::string(30, '=') << "\n\tIdentify-reference tests\n" << std::string(30, '=') << RESET << std::endl;\

	std::cout << std::string(30, '=') << "\n\tConstructors\n" << std::string(30, '=') << std::endl;
	A		a;
	B		b;
	C		c;
	Base	d;

	std::cout << std::string(30, '=') << "\n\tIdentify(Base &p)\n" << std::string(30, '=') << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(d);

	std::cout << std::string(30, '=') << "\n\tDestructors\n" << std::string(30, '=') << std::endl;
}

static int	howToUse(void)
{
	std::cout << BRIGHT_RED "How to use: ./identify <Test number>\n" RESET;
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (howToUse());

	std::srand(std::time(0));

	const int	len = 3;
	std::string	input = argv[1];
	t_map	map[len] =
	{
		{"1", &generateTest},
		{"2", &identifyTest1},
		{"3", &identifyTest2}
	};
	for (int i = 0; i < len; i++)
		if (map[i].test == input)
		{
			map[i].f();
			break;
		}
	return (0);
}

