-- set minimum xmake version
set_xmakever("2.8.2")

-- set project
set_project("commonlibf4")
set_languages("c++23")
set_warnings("allextra")
set_encodings("utf-8")

-- add rules
add_rules("mode.debug", "mode.releasedbg")

-- make custom rules available
includes("xmake-rules.lua")

-- define options
option("f4se_xbyak", function()
    set_default(false)
    set_description("Enable trampoline support for Xbyak")
    add_defines("F4SE_SUPPORT_XBYAK=1")
end)

option("rex_ini", function()
    set_default(false)
    set_description("Enable ini config support for REX")
    add_defines("REX_OPTION_INI=1")
end)

option("rex_json", function()
    set_default(false)
    set_description("Enable json config support for REX")
    add_defines("REX_OPTION_JSON=1")
end)

option("rex_toml", function()
    set_default(false)
    set_description("Enable toml config support for REX")
    add_defines("REX_OPTION_TOML=1")
end)

-- require packages
add_requires("rsm-binary-io", "rsm-mmio")
add_requires("spdlog", { configs = { header_only = false, wchar = true, std_format = true } })

if has_config("f4se_xbyak") then
    add_requires("xbyak")
end

if has_config("rex_ini") then
    add_requires("simpleini")
end

if has_config("rex_json") then
    add_requires("nlohmann_json")
end

if has_config("rex_toml") then
    add_requires("toml11")
end

-- define targets
target("commonlibf4", function()
    -- set target kind
    set_kind("static")

    -- set build by default
    set_default(os.scriptdir() == os.projectdir())

    -- set build group
    set_group("commonlibf4")

    -- add packages
    add_packages("rsm-binary-io", "rsm-mmio", "spdlog", { public = true })

    if has_config("f4se_xbyak") then
        add_packages("xbyak", { public = true })
    end

    if has_config("rex_ini") then
        add_packages("simpleini", { public = true })
    end

    if has_config("rex_json") then
        add_packages("nlohmann_json", { public = true })
    end

    if has_config("rex_toml") then
        add_packages("toml11", { public = true })
    end

    -- add options
    add_options("f4se_xbyak", "rex_ini", "rex_json", "rex_toml", { public = true })

    -- add system links
    add_syslinks("advapi32", "bcrypt", "d3d11", "d3dcompiler", "dbghelp", "dxgi", "ole32", "shell32", "user32", "version")

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_includedirs("include", { public = true })
    add_headerfiles(
        "include/(F4SE/**.h)",
        "include/(RE/**.h)",
        "include/(REL/**.h)",
        "include/(REX/**.h)"
    )

    -- add extra files
    add_extrafiles("res/commonlibf4.natvis")

    -- set precompiled header
    set_pcxxheader("include/F4SE/Impl/PCH.h")

    -- add flags
    add_cxxflags("/EHsc", "/permissive-", { public = true })

    -- add flags (cl)
    add_cxxflags(
        "cl::/bigobj",
        "cl::/cgthreads8",
        "cl::/diagnostics:caret",
        "cl::/external:W0",
        "cl::/fp:contract",
        "cl::/fp:except-",
        "cl::/guard:cf-",
        "cl::/Zc:preprocessor",
        "cl::/Zc:templateScope"
    )

    -- add flags (cl: disable warnings)
    add_cxxflags(
        "cl::/wd4200", -- nonstandard extension used : zero-sized array in struct/union
        "cl::/wd4201", -- nonstandard extension used : nameless struct/union
        "cl::/wd4324", -- structure was padded due to alignment specifier
        { public = true }
    )

    -- add flags (cl: warnings -> errors)
    add_cxxflags(
        "cl::/we4715", -- not all control paths return a value
        { public = true }
    )
end)
