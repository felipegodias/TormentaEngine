#pragma once

#include <string>
#include <fmt/format.h>

#include "Tormenta/Api.hpp"
#include "Tormenta/Memory/Allocator.hpp"

namespace Tormenta
{
	template <typename Ty>
	using BasicString = std::basic_string<Ty, std::char_traits<Ty>, Allocator<Ty>>;

	using String = BasicString<char>;
	using WString = BasicString<wchar_t>;

	template <typename Ty>
	using BasicStringView = std::basic_string_view<Ty>;

	using StringView = BasicStringView<char>;
	using WStringView = BasicStringView<wchar_t>;

	TORMENTA_API [[nodiscard]] String FormatArgs(String::allocator_type alloc, StringView fmt, fmt::format_args args);

	template <typename ...Args>
	String Format(const StringView fmt, const Args& ... args)
	{
		return FormatArgs(String::allocator_type(), fmt, fmt::make_format_args(args...));
	}
}
