#ifndef TORMENTA_TRACKER_ALLOCATOR_HPP
#define TORMENTA_TRACKER_ALLOCATOR_HPP

#include "MallocAllocator.hpp"

#include "Tormenta/Containers/UnorderedMap.hpp"

namespace Tormenta
{
    template <typename ParentAllocator = MallocAllocator, typename ControlAllocator = MallocAllocator>
    class TrackerAllocator
    {
    public:
        static TrackerAllocator& GetGlobal();

        void* Allocate(size_t size);
        void Deallocate(void* ptr);
        [[nodiscard]] bool Owns(const void* ptr) const;

        [[nodiscard]] size_t GetTrackedTotalSize() const;
        [[nodiscard]] size_t GetTrackedSize(const void* ptr) const;

    private:
        TrackerAllocator() = default;

        size_t _totalSize = 0;
        UnorderedMap<const void*, size_t, ControlAllocator> _pointers = {};
        ParentAllocator* _parentAllocator = &ParentAllocator::GetGlobal();
    };

    template <typename ParentAllocator, typename ControlAllocator>
    TrackerAllocator<ParentAllocator, ControlAllocator>& TrackerAllocator<
        ParentAllocator, ControlAllocator>::GetGlobal()
    {
        static TrackerAllocator<ParentAllocator, ControlAllocator> global;
        return global;
    }

    template <typename ParentAllocator, typename ControlAllocator>
    void* TrackerAllocator<ParentAllocator, ControlAllocator>::Allocate(const size_t size)
    {
        _totalSize += size;
        void* ptr = _parentAllocator->Allocate(size);
        _pointers.emplace(ptr, size);
        return ptr;
    }

    template <typename ParentAllocator, typename ControlAllocator>
    void TrackerAllocator<ParentAllocator, ControlAllocator>::Deallocate(void* ptr)
    {
        const auto findIt = _pointers.find(ptr);
        _totalSize -= findIt->second;
        _pointers.erase(findIt);

        _parentAllocator->Deallocate(ptr);
    }

    template <typename ParentAllocator, typename ControlAllocator>
    bool TrackerAllocator<ParentAllocator, ControlAllocator>::Owns(const void* ptr) const
    {
        return _pointers.contains(ptr);
    }

    template <typename ParentAllocator, typename ControlAllocator>
    size_t TrackerAllocator<ParentAllocator, ControlAllocator>::GetTrackedTotalSize() const
    {
        return _totalSize;
    }

    template <typename ParentAllocator, typename ControlAllocator>
    size_t TrackerAllocator<ParentAllocator, ControlAllocator>::GetTrackedSize(const void* ptr) const
    {
        return _pointers.at(ptr);
    }
}

#endif //TORMENTA_TRACKER_ALLOCATOR_HPP
