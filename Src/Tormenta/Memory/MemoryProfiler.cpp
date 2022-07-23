#include "Tormenta/Memory/MemoryProfiler.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

namespace Tormenta
{
	namespace
	{
		size_t totalUsedBytes = 0;

		template <class Ty>
		class MPAllocator
		{
		public:
			using value_type = Ty;

			MPAllocator() noexcept = default;

			template <class RebindTy>
			MPAllocator(const MPAllocator<RebindTy>&) noexcept
			{
			}

			value_type* allocate(const std::size_t n)
			{
				const size_t size = n * sizeof(value_type);
				totalUsedBytes += size;
				return static_cast<value_type*>(std::malloc(size));
			}

			void deallocate(value_type* p, const std::size_t n) noexcept
			{
				const size_t size = n * sizeof(value_type);
				totalUsedBytes -= size;
				std::free(p);
			}
		};

		template <class Ty, class RebindTy>
		bool operator==(const MPAllocator<Ty>&, const MPAllocator<RebindTy>&) noexcept
		{
			return true;
		}

		template <class Ty, class RebindTy>
		bool operator!=(const MPAllocator<Ty>& x, const MPAllocator<RebindTy>& y) noexcept
		{
			return !(x == y);
		}

		using MPString = std::basic_string<char, std::char_traits<char>, MPAllocator<char>>;

		template <typename Ty>
		using MPVector = std::vector<Ty, MPAllocator<Ty>>;

		template <typename KTy, typename VTy>
		using MPMap = std::map<KTy, VTy, std::less<KTy>, MPAllocator<std::pair<const KTy, VTy>>>;

		template <typename KTy, typename VTy>
		using MPUnorderedMap = std::unordered_map<KTy, VTy, std::hash<KTy>, std::equal_to<KTy>, MPAllocator<std::pair<
			                                          const KTy, VTy>>>;

		struct PointerMetaData
		{
			size_t Size;
			MPMap<MPString, MPString> Tags;

			explicit PointerMetaData(const size_t size)
				: Size(size)
			{
			}

			friend std::ostream& operator<<(std::ostream& os, const PointerMetaData& pointerMetaData)
			{
				os << "<<<<<<<<<<<<<<<<<<<<<<<\n";
				os << "Size: " << pointerMetaData.Size << " bytes\n";
				for (auto& tag : pointerMetaData.Tags)
				{
					os << tag.first << ": " << tag.second << "\n";
				}
				os << ">>>>>>>>>>>>>>>>>>>>>>>\n";
				return os;
			}
		};

		bool PointerMetaDataComparator(const PointerMetaData* lhs, const PointerMetaData* rhs)
		{
			return lhs->Size > rhs->Size;
		}

		MPUnorderedMap<uintptr_t, PointerMetaData> pointersMetaData;
	}

	void MemoryProfiler::Track(void* ptr, const size_t size)
	{
		totalUsedBytes += size;
		pointersMetaData.emplace(reinterpret_cast<uintptr_t>(ptr), PointerMetaData(size));
	}

	void MemoryProfiler::Untrack(void* ptr)
	{
		if (const auto it = pointersMetaData.find(reinterpret_cast<uintptr_t>(ptr)); it != pointersMetaData.end())
		{
			totalUsedBytes -= it->second.Size;
			pointersMetaData.erase(it);
		}
	}

	void MemoryProfiler::AddTag(void* ptr, const StringView name, const StringView value)
	{
		const auto it = pointersMetaData.find(reinterpret_cast<uintptr_t>(ptr));
		if (it == pointersMetaData.end())
		{
			return;
		}

		MPMap<MPString, MPString>& tags = it->second.Tags;
		MPString nameStr = name.data();
		MPString valueStr = value.data();
		if (const auto tagsIt = tags.find(nameStr); tagsIt == tags.end())
		{
			tags.emplace(std::move(nameStr), std::move(valueStr));
		}
		else
		{
			tagsIt->second = std::move(valueStr);
		}
	}

	size_t MemoryProfiler::GetUsedMemory()
	{
		return totalUsedBytes;
	}

	void MemoryProfiler::DumpMemorySummary(std::ostream& os)
	{
		MPVector<PointerMetaData*> pointerMetaDataHeap;
		pointerMetaDataHeap.reserve(pointersMetaData.size());
		for (auto& [size, pointerMetaData] : pointersMetaData)
		{
			pointerMetaDataHeap.push_back(&pointerMetaData);
			std::push_heap(pointerMetaDataHeap.begin(), pointerMetaDataHeap.end(), PointerMetaDataComparator);
		}

		while (pointerMetaDataHeap.empty() == false)
		{
			os << *pointerMetaDataHeap.front() << "\n";
			std::pop_heap(pointerMetaDataHeap.begin(), pointerMetaDataHeap.end(), PointerMetaDataComparator);
			pointerMetaDataHeap.pop_back();
		}
	}
}
