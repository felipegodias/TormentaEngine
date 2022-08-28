#ifndef TORMENTA_FREE_LIST_ALLOCATOR_HPP
#define TORMENTA_FREE_LIST_ALLOCATOR_HPP

#include "MallocAllocator.hpp"

#include "Tormenta/Containers/UnorderedSet.hpp"

namespace Tormenta
{
    template <size_t Size, typename ParentAllocator = MallocAllocator, typename ControlAllocator = MallocAllocator>
    class FreeListAllocator
    {
    public:
        static FreeListAllocator& GetGlobal();

        void* Allocate(size_t size);
        void Deallocate(void* ptr);
        bool Owns(const void* ptr) const;

    private:
        FreeListAllocator() = default;

        struct Node
        {
            Node* Next;
        };

        Node* _head = nullptr;
        UnorderedSet<const void*, ControlAllocator> _pointers = {};
        ParentAllocator* _parentAllocator = &ParentAllocator::GetGlobal();
    };

    template <size_t Size, typename ParentAllocator, typename ControlAllocator>
    FreeListAllocator<Size, ParentAllocator, ControlAllocator>& FreeListAllocator<Size, ParentAllocator,
        ControlAllocator>::GetGlobal()
    {
        static FreeListAllocator<Size, ParentAllocator, ControlAllocator> global;
        return global;
    }

    template <size_t Size, typename ParentAllocator, typename ControlAllocator>
    void* FreeListAllocator<Size, ParentAllocator, ControlAllocator>::Allocate(size_t size)
    {
        size;
        if (_head == nullptr)
        {
            void* ptr = _parentAllocator->Allocate(Size);
            _pointers.emplace(ptr);
            return ptr;
        }

        Node* current = _head;
        _head = current->Next;
        return current;
    }

    template <size_t Size, typename ParentAllocator, typename ControlAllocator>
    void FreeListAllocator<Size, ParentAllocator, ControlAllocator>::Deallocate(void* ptr)
    {
        auto node = static_cast<Node*>(ptr);
        node->Next = _head;
        _head = node;
    }

    template <size_t Size, typename ParentAllocator, typename ControlAllocator>
    bool FreeListAllocator<Size, ParentAllocator, ControlAllocator>::Owns(const void* ptr) const
    {
        return _pointers.contains(ptr);
    }
}

#endif // TORMENTA_FREE_LIST_ALLOCATOR_HPP
