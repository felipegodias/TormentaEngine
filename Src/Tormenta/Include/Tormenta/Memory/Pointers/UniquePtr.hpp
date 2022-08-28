#ifndef TORMENTA_UNIQUE_PTR_HPP_27_08_2022
#define TORMENTA_UNIQUE_PTR_HPP_27_08_2022

#include <memory>

#include "Tormenta/Memory/Allocators/MallocAllocator.hpp"

namespace Tormenta
{
    /**
     * \brief Default deleter for Tormenta UniquePtr.
     * \tparam Ty The type to be deleted.
     * \tparam AllocatorTy The allocator type to use when deallocate from memory.
     */
    template <typename Ty, typename AllocatorTy>
    class TormentaDefaultDeleter
    {
    public:
        /**
         * \brief Default constructor for the deleter.
         */
        TormentaDefaultDeleter()
            : _allocator(&AllocatorTy::GetGlobal())
        {
        }

        /**
         * \brief Constructs the Tormenta default deleter using the given allocator.
         * \param allocator The allocator to be used when needed to deallocate the given pointers.
         */
        explicit TormentaDefaultDeleter(AllocatorTy& allocator)
            : _allocator(&allocator)
        {
        }

        /**
         * \brief Copy ctor when rebinding this deleter to another one.
         * \tparam RebindTy The type to be rebind to.
         * \tparam RebindAllocatorTy The allocator type to rebind to. (Must be the same as current one)
         * \param other The other deleter instance to copy from.
         */
        template <typename RebindTy, typename RebindAllocatorTy,
                  std::enable_if_t<std::is_same_v<AllocatorTy, RebindAllocatorTy>, int>  = 0>
        TormentaDefaultDeleter(const TormentaDefaultDeleter<RebindTy, RebindAllocatorTy>& other)
            : _allocator(&other.GetAllocator())
        {
        }

        /**
         * \brief Move ctor when rebinding this deleter to another one.
         * \tparam RebindTy The type to be rebind to.
         * \tparam RebindAllocatorTy The allocator type to rebind to. (Must be the same as current one)
         * \param other The other deleter instance to move from.
         */
        template <typename RebindTy, typename RebindAllocatorTy,
                  std::enable_if_t<std::is_same_v<AllocatorTy, RebindAllocatorTy>, int>  = 0>
        TormentaDefaultDeleter(TormentaDefaultDeleter<RebindTy, RebindAllocatorTy>&& other)
            : _allocator(&other.GetAllocator())
        {
        }

        /**
         * \brief Invokes the type deleter and deallocate from the allocator.
         * \param ptr The pointer to be deleted.
         */
        void operator()(Ty* ptr) const noexcept
        {
            static_assert(sizeof(Ty) != 0, "Can't delete an incomplete type!");
            ptr->~Ty();
            _allocator->Deallocate(ptr);
        }

        /**
         * \brief Gets the current allocator attached to this deleter instance.
         * \return An reference to the allocator.
         */
        [[nodiscard]] AllocatorTy& GetAllocator() const
        {
            return *_allocator;
        }

    private:
        AllocatorTy* _allocator = nullptr;
    };

    template <typename Ty, typename AllocatorTy = MallocAllocator>
    using UniquePtr = std::unique_ptr<Ty, TormentaDefaultDeleter<Ty, AllocatorTy>>;

    template <typename Ty, typename AllocatorTy = MallocAllocator, typename ... ArgsTy,
              std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, int>  = 0>
    UniquePtr<Ty, AllocatorTy> MakeUnique(ArgsTy&& ... args, AllocatorTy& allocator)
    {
        Ty* ptr = static_cast<Ty*>(allocator.Allocate(sizeof(Ty)));
        new(ptr) Ty(std::forward<ArgsTy>(args)...);
        return UniquePtr<Ty, AllocatorTy>(ptr, TormentaDefaultDeleter<Ty, AllocatorTy>(allocator));
    }

    template <typename Ty, typename AllocatorTy = MallocAllocator, typename ... ArgsTy,
              std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, int>  = 0>
    UniquePtr<Ty, AllocatorTy> MakeUnique(ArgsTy&& ... args)
    {
        return MakeUnique<Ty, AllocatorTy>(args..., AllocatorTy::GetGlobal());
    }
}

#endif // TORMENTA_UNIQUE_PTR_HPP_27_08_2022
