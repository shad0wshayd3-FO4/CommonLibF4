target("commonlibf4-rttidump")
    -- set build kind
    set_kind("shared")

    -- set build by default
    set_default(false)

    -- set build group
    set_group("commonlibf4/plugin")

    -- add dependencies
    add_deps("commonlibf4")

    -- add packages
    add_packages("spdlog")

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_headerfiles("src/**.h")

    -- add include dirs
    add_includedirs("src")

    -- set precompiled header
    set_pcxxheader("src/pch.h")
