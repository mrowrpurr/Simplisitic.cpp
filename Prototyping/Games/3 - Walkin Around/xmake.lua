target("Game 3 - Walkin Around")
    add_files("Game 3 - Walkin Around.cpp")
    set_kind("binary")
    add_qt()
    add_includedirs(".")
    add_string_formatting()
    add_logging_support_for_binaries()
    add_deps("Simp1e.UI", "Simp1e.Qt.v1", "Simp1e.Maps", "Simp1e.UI.Maps", "Simp1e.Qt.Maps")