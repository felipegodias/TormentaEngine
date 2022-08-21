#include "Tormenta/Containers/String.hpp"

namespace Tormenta
{
	using StringMemoryBuffer = fmt::basic_memory_buffer<char, fmt::inline_buffer_size, String::allocator_type>;

	String FormatArgs(const String::allocator_type alloc, const StringView fmt, const fmt::format_args args)
	{
		auto buf = StringMemoryBuffer(alloc);
		fmt::vformat_to(std::back_inserter(buf), fmt, args);
		return String(buf.data(), buf.size(), alloc);
	}
}
