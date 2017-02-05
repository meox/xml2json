#include <iostream>
#include "xml2json.hpp"

int main(int argc, char* argv[])
{
	std::string fname;
	int indent = -1;

	if (argc == 1)
	{
		std::cout << argv[0] << " <filename> [indentation]";
		return 1;
	}
	else
	{
		fname = argv[1];
	}

	if (argc == 3)
		indent = std::stoi(argv[2]);

	std::cout << xml2json::parseit(fname, indent) << std::endl;
	return 0;
}