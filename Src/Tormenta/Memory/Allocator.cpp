#include "Tormenta/Memory/Allocator.hpp"

#include <iostream>
#include <typeinfo>

#include "Tormenta/Memory/MemoryProfiler.hpp"

void* operator new(const size_t size)
{
	return Tormenta::Malloc(size, typeid(void));
}

void operator delete(void* ptr) noexcept
{
	Tormenta::Free(ptr);
}

void operator delete(void* ptr, [[maybe_unused]] const size_t size) noexcept
{
	Tormenta::Free(ptr);
}

namespace Tormenta
{
	void* Malloc(const size_t size, const std::type_info& type)
	{
		void* ptr = std::malloc(size);
		MemoryProfiler::Track(ptr, size);
		MemoryProfiler::AddTag(ptr, "Type", type.name());
		return ptr;
	}

	void Free(void* ptr)
	{
		MemoryProfiler::Untrack(ptr);
		std::free(ptr);
	}
}
