#pragma once

#include <cstddef>
#include <typeinfo>

#include "Tormenta/Api.hpp"

namespace Tormenta
{
	TORMENTA_API void* Malloc(size_t size, const std::type_info& type);
	TORMENTA_API void Free(void* ptr);

	template <class Ty>
	class Allocator
	{
	public:
		using value_type = Ty;

		Allocator() noexcept = default;

		template <class BinderTy>
		Allocator(const Allocator<BinderTy>&) noexcept
		{
		}

		value_type* allocate(const std::size_t n)
		{
			const size_t size = n * sizeof(value_type);
			void* ptr = Malloc(size, typeid(Ty));
			return static_cast<value_type*>(ptr);
		}

		void deallocate(value_type* p, [[maybe_unused]] std::size_t n) noexcept
		{
			Free(p);
		}
	};

	template <class Ty, class BinderTy>
	bool operator==(const Allocator<Ty>&, const Allocator<BinderTy>&) noexcept
	{
		return true;
	}

	template <class T, class U>
	bool operator!=(const Allocator<T>& x, const Allocator<U>& y) noexcept
	{
		return !(x == y);
	}
}
