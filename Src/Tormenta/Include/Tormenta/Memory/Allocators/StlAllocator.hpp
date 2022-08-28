#ifndef TORMENTA_STL_ALLOCATOR_HPP
#define TORMENTA_STL_ALLOCATOR_HPP

#include "MallocAllocator.hpp"

namespace Tormenta
{
    template <typename Ty, typename ParentAllocator = MallocAllocator>
    class StlAllocator
    {
    public:
        using value_type = Ty;

        StlAllocator() noexcept = default;

        template <class BinderTy>
        StlAllocator(const StlAllocator<BinderTy, ParentAllocator>&) noexcept
        {
        }

        value_type* allocate(const size_t n)
        {
            return static_cast<value_type*>(ParentAllocator::GetGlobal().Allocate(sizeof(Ty) * n));
        }

        void deallocate(value_type* ptr, [[maybe_unused]] const size_t n)
        {
            ParentAllocator::GetGlobal().Deallocate(ptr);
        }
    };
}

#endif // !TORMENTA_STL_ALLOCATOR_HPP
