add_library(Tormenta STATIC "Tormenta.cpp")

target_compile_definitions(Tormenta PRIVATE TORMENTA_EXPORTS)

configure_file("Include/Tormenta/Config.hpp.in" "Tormenta/Include/Tormenta/Config.hpp")

target_include_directories(Tormenta PUBLIC
	"Include"
	"${CMAKE_CURRENT_BINARY_DIR}/Tormenta/Include"
)

target_link_libraries(Tormenta PRIVATE fmt::fmt)

add_subdirectory("Memory")
add_subdirectory("String")
