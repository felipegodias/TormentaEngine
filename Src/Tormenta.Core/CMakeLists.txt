add_library(Tormenta.Core STATIC Tormenta.Core.cpp)

configure_file("Include/Tormenta/Core/Config.hpp.in" "Tormenta.Core/Include/Tormenta/Core/Config.hpp")
target_include_directories(Tormenta.Core PUBLIC
	"Include"
	"${CMAKE_CURRENT_BINARY_DIR}/Tormenta.Core/Include"
)
