#include "Tormenta/Memory/Allocators/MallocAllocator.hpp"

#include <cstdlib>

namespace Tormenta
{
    MallocAllocator& MallocAllocator::GetGlobal()
    {
        static MallocAllocator global;
        return global;
    }

    void* MallocAllocator::Allocate(const size_t size)
    {
        return malloc(size);
    }

    void MallocAllocator::Deallocate(void* ptr)
    {
        free(ptr);
    }

    bool MallocAllocator::Owns([[maybe_unused]] void* ptr) const
    {
        return true;
    }
}
