#ifndef TORMENTA_MALLOC_ALLOCATOR_HPP
#define TORMENTA_MALLOC_ALLOCATOR_HPP

namespace Tormenta
{
    class MallocAllocator
    {
    public:
        static MallocAllocator& GetGlobal();

        void* Allocate(size_t size);
        void Deallocate(void* ptr);
        bool Owns(void* ptr) const;

    private:
        MallocAllocator() = default;
    };
}

#endif // TORMENTA_MALLOC_ALLOCATOR_HPP
