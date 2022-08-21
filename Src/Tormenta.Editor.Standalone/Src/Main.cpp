#include <iostream>
#include <argparse/argparse.hpp>

#include "Tormenta/Config.hpp"
#include "Tormenta/Containers/String.hpp"
#include "Tormenta/Memory/FreeListAllocator.hpp"
#include "Tormenta/Memory/TrackerAllocator.hpp"

using TAlloc = Tormenta::TrackerAllocator<>;
using Alloc = Tormenta::FreeListAllocator<16, TAlloc, TAlloc>;

class Foo
{
public:
    Foo()
    {
        std::cout << __FUNCSIG__ << std::endl;
    }

    virtual ~Foo()
    {
        std::cout << __FUNCSIG__ << std::endl;
    }
};

class Bar : public Foo
{
public:
    Bar() : Foo()
    {
        std::cout << __FUNCSIG__ << std::endl;
    }

    ~Bar() override
    {
        std::cout << __FUNCSIG__ << std::endl;
    }
};

template <class Ty, typename AllocatorTy>
class TormentaDelete
{
public:
    explicit TormentaDelete(AllocatorTy& allocator)
        : _allocator(&allocator)
    {
    }

    template <typename RebindTy, typename RebindAllocatorTy>
    TormentaDelete(TormentaDelete<RebindTy, RebindAllocatorTy>&& other)
        : _allocator(&other.GetAllocator())
    {
    }

    void operator()(Ty* ptr) const noexcept
    {
        static_assert(0 < sizeof(Ty), "can't delete an incomplete type");
        ptr->~Ty();
        _allocator->Deallocate(ptr);
    }

    AllocatorTy& GetAllocator() const
    {
        return *_allocator;
    }

private:
    AllocatorTy* _allocator = nullptr;
};

template <typename Ty, typename AllocatorTy = Tormenta::MallocAllocator>
using UniquePtr = std::unique_ptr<Ty, TormentaDelete<Ty, AllocatorTy>>;

template <typename Ty, typename AllocatorTy = Tormenta::MallocAllocator, typename ... ArgsTy,
          std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, int>  = 0>
UniquePtr<Ty, AllocatorTy> MakeUnique(ArgsTy&& ... args, AllocatorTy& allocator)
{
    Ty* ptr = static_cast<Ty*>(allocator.Allocate(sizeof(Ty)));
    new(ptr) Ty(std::forward<ArgsTy>(args)...);
    return UniquePtr<Ty, AllocatorTy>(ptr, TormentaDelete<Ty, AllocatorTy>(allocator));
}

template <typename Ty, typename AllocatorTy = Tormenta::MallocAllocator, typename ... ArgsTy,
    std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, int> = 0>
UniquePtr<Ty, AllocatorTy> MakeUnique(ArgsTy&& ... args)
{
    return MakeUnique<Ty, AllocatorTy>(args..., AllocatorTy::GetGlobal());
}

int main(const int argc, char* argv[])
{
    {
        UniquePtr<Foo> bar = MakeUnique<Bar>();
    }

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
