add_executable(Tormenta.Editor.Standalone 
    "Main.cpp"
)

target_link_libraries(Tormenta.Editor.Standalone PRIVATE 
    Tormenta
    argparse::argparse
)

install(TARGETS Tormenta.Editor.Standalone)
