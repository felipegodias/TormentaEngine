#pragma once

#include <string>
#include <fmt/format.h>

#include "Tormenta/Api.hpp"
#include "Tormenta/Memory/Allocators/StlAllocator.hpp"

namespace Tormenta
{
	template <typename Ty>
	using BasicString = std::basic_string<Ty, std::char_traits<Ty>, StlAllocator<Ty>>;

	using String = BasicString<char>;
	using WString = BasicString<wchar_t>;

	template <typename Ty>
	using BasicStringView = std::basic_string_view<Ty>;

	using StringView = BasicStringView<char>;
	using WStringView = BasicStringView<wchar_t>;

	[[nodiscard]] TORMENTA_API String FormatArgs(String::allocator_type alloc, StringView fmt, fmt::format_args args);

	template <typename ...Args>
	String Format(const StringView fmt, const Args& ... args)
	{
		return FormatArgs(String::allocator_type(), fmt, fmt::make_format_args(args...));
	}
}
