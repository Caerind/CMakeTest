#include <iostream>

#include <pugixml/pugixml.hpp>

#include <func.hpp>

int main(int argc, char** argv)
{
	pugi::xml_node node;

	std::cout << "Hello World!" << func(2, 3) << std::endl;
	return 0;
}