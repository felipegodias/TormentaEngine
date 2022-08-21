#ifndef TORMENTA_UNORDERED_SET_HPP
#define TORMENTA_UNORDERED_SET_HPP

#include "Tormenta/Memory/StlAllocator.hpp"

#include <unordered_set>

namespace Tormenta
{
    template <typename KeyTy, typename AllocatorTy = MallocAllocator, typename HasherTy = std::hash<KeyTy>,
              typename KeyEqTy = std::equal_to<KeyTy>>
    using UnorderedSet = std::unordered_set<KeyTy, HasherTy, KeyEqTy, StlAllocator<KeyTy, AllocatorTy>>;
}

#endif // TORMENTA_UNORDERED_SET_HPP
