#include "Tormenta/Core/Config.hpp"

#include <iostream>

#include <argparse/argparse.hpp>

int main(const int argc, char* argv[])
{
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

    system("pause");
    return EXIT_SUCCESS;
}