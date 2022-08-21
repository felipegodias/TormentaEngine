#ifndef TORMENTA_UNORDERED_MAP_HPP
#define TORMENTA_UNORDERED_MAP_HPP

#include "Tormenta/Memory/StlAllocator.hpp"

#include <unordered_map>

namespace Tormenta
{
    template <typename KeyTy, typename ValueTy, typename AllocatorTy = MallocAllocator, typename HasherTy = std::hash<
                  KeyTy>, typename KeyEqTy = std::equal_to<KeyTy>>
    using UnorderedMap = std::unordered_map<KeyTy, ValueTy, HasherTy, KeyEqTy, StlAllocator<
                                                std::pair<const KeyTy, ValueTy>, AllocatorTy>>;
}

#endif // TORMENTA_UNORDERED_MAP_HPP
