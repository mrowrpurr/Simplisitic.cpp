add_languages("c++20")

target("Simp1e.Editor")
    add_qt()
    set_kind("binary")
    add_files("Editor.cpp", "../Resources/Editor.qrc", "include/**/*_Q.h")
    add_includedirs("include")
    add_headerfiles("include/(**).h")
    add_deps("Simp1e.Data", "Simp1e.Data.Types", "Simp1e.Editor.Types")
    add_string_formatting()
    add_logging_support_for_binaries()
    if is_plat("windows") then
        add_files("Editor.rc")
    end

mac_icon_for_target("Simp1e.Editor", "Resources/Logo/iconset.icns")
