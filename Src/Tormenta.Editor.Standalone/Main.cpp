#include <iostream>
#include <argparse/argparse.hpp>

#include "Tormenta/Config.hpp"
#include "Tormenta/Memory/SmartPointer.hpp"
#include "Tormenta/String/String.hpp"

int main(const int argc, char* argv[])
{
	Tormenta::UniquePtr<int> smartPointer;
	Tormenta::String string;

	argparse::ArgumentParser args(PROJECT_NAME, PROJECT_VER);
	try
	{
		args.parse_args(argc, argv);
	}
	catch (const std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
		std::cerr << args;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
