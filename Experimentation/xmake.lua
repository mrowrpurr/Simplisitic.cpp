target("Experimentation")
    set_kind("binary")
    add_logging_runtime()
    add_deps("Simp1e.ECS.Core", "Simp1e.ECS.PointerStorage", "Simp1e.ECS.PointerStorageClient", "Simp1e.ECS.Services")
    add_files("Experimentation.cpp")