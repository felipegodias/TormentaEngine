add_library(Tormenta STATIC 
	"Src/Containers/String.cpp"
	"Src/Containers/UnorderedMap.cpp"
	"Src/Containers/UnorderedSet.cpp"
	"Src/Memory/Allocators/FreeListAllocator.cpp"
	"Src/Memory/Allocators/MallocAllocator.cpp"
	"Src/Memory/Allocators/StlAllocator.cpp"
	"Src/Memory/Allocators/TrackerAllocator.cpp"
	"Src/Tormenta.cpp"
)

target_compile_definitions(Tormenta PRIVATE TORMENTA_EXPORTS)

configure_file("Include/Tormenta/Config.hpp.in" "Tormenta/Include/Tormenta/Config.hpp")

target_include_directories(Tormenta PUBLIC
	"Include"
	"${CMAKE_CURRENT_BINARY_DIR}/Tormenta/Include"
)

target_link_libraries(Tormenta PRIVATE fmt::fmt)
