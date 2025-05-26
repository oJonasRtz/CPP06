#include <iostream>
#include "Serializer.hpp"

static void	printData(const Data &other)
{

	std::cout << BRIGHT_GREEN "\tname:\t\t" RESET << other.name <<
				BRIGHT_GREEN "\n\tlifePts:\t" RESET << other.lifePts <<
				BRIGHT_GREEN "\n\tclass:\t\t" RESET << other.role <<
				BRIGHT_GREEN "\n\tdamage:\t\t" RESET << other.dmg << std::endl;
	std::cout << ORANGE << std::string(40, '=') << RESET << std::endl;
}

int	main(void)
{
	//	Original
	std::cout << ORANGE << std::string(40, '=') << RESET << std::endl;
	std::cout << ORANGE "\t\tData-Original\n" << std::string(40, '=') << RESET << std::endl;
	Data	player = {"Xayah", 2000.0, "Marksman", 415};
	printData(player);

	//	Serialized variable
	std::cout << ORANGE << "\t\tSerialize\n" << std::string(40, '=') << RESET << std::endl;
	uintptr_t	s = Serializer::serialize(&player);
	std::cout << BRIGHT_GREEN "\tSerialized:\t" RESET << s << "\n";

	//	Deserialized variable
	std::cout << ORANGE << std::string(40, '=') << RESET << std::endl;
	std::cout << ORANGE << "\t\tDeserialized Data\n" << std::string(40, '=') << RESET << std::endl;
	Data	*deserialize = Serializer::deserialize(s);
	printData(*deserialize);

	return (0);
}

