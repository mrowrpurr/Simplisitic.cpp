target("Simp1e.Qt.ECS.GUI.DLL")
    set_kind_qt_shared_library()
    set_basename("Simp1e.Qt.ECS.GUI")
    add_logging_runtime()
    add_string_formatting()
    add_deps("Simp1e.ServiceHost", "Simp1e.ECS.Services", "Simp1e.Qt.ECS.GUI")
    add_files("Simp1e.Qt.ECS.GUI.DLL.cpp")
