target("Simp1e")
    set_kind("headeronly")
    add_headerfiles("include/(**).h")
    add_includedirs("include", {public = true})
