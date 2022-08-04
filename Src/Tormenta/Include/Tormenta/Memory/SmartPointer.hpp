#pragma once

#include <functional>
#include <memory>

#include "Allocator.hpp"

namespace Tormenta
{
    template <typename Ty>
    using UniquePtr = std::unique_ptr<Ty, std::function<void(void*)>>;

    template <typename Ty, typename ... Args, std::enable_if_t<std::is_constructible_v<Ty, Args...>, int> = 0>
    UniquePtr<Ty> MakeUnique(Args&& ... args)
    {
        static Allocator<Ty> allocator;

        Ty* buffer = allocator.allocate(1);
        new(buffer) Ty(std::forward<Args>(args)...);
        return UniquePtr<Ty>(
            buffer,
            [](void* ptr)
            {
                Ty* toFree = static_cast<Ty*>(ptr);
                toFree->~Ty();
                allocator.deallocate(toFree, 1);
            }
        );
    }
}
