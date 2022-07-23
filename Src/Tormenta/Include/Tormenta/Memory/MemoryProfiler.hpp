#pragma once

#include "Tormenta/Api.hpp"
#include "Tormenta/String/String.hpp"

namespace Tormenta
{
	class TORMENTA_API MemoryProfiler
	{
	public:
		static void Track(void* ptr, size_t size);
		static void Untrack(void* ptr);
		static void AddTag(void* ptr, StringView name, StringView value);

		static size_t GetUsedMemory();

		static void DumpMemorySummary(std::ostream& os);
	};
}
