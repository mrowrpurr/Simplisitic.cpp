target("Simp1e.Qt.MapEditor")
    set_kind("headeronly")
    add_includedirs("include", {public = true})
    add_headerfiles("include/(**.h)")
    add_deps("Simp1e.UI.MapEditor", "Simp1e.Qt.Maps")
