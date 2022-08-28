#include <iostream>
#include <Tormenta/Memory/Pointers/UniquePtr.hpp>
#include <Tormenta/Memory/Allocators/FreeListAllocator.hpp>
//#include <argparse/argparse.hpp>

class Foo
{
public:
    Foo()
    {
        std::cout << "Foo()" << std::endl;
    }

    virtual ~Foo()
    {
        std::cout << "~Foo()" << std::endl;
    }
};

class Bar : public Foo
{
public:
    Bar()
    {
        std::cout << "Bar()" << std::endl;
    }

    ~Bar() override
    {
        std::cout << "~Bar()" << std::endl;
    }
};

class Qux;

template <typename Ty>
using Alloc = Tormenta::FreeListAllocator<sizeof(Ty)>;

int main(const int argc, char* argv[])
{
    argc;
    argv;

    {
        //Tormenta::UniquePtr<Qux> qux();
        //Tormenta::MakeUnique<Qux>();

        Tormenta::UniquePtr<Foo> foo2;

        Tormenta::UniquePtr<Foo, Alloc<Foo>> foo = Tormenta::MakeUnique<Bar, Alloc<Bar>>();
        foo.reset();
    }

    /*
    argparse::ArgumentParser args(PROJECT_NAME, PROJECT_VER);
    try
    {
        args.parse_args(argc, argv);
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << args << std::endl;
    }
    */

    return EXIT_SUCCESS;
}
