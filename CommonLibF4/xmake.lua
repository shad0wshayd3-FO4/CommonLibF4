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
    set_kind("static")

    -- set build by default
    set_default(path.directory(os.scriptdir()) == os.projectdir())

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

local PLUGIN_FILE = [[
#include <F4SE/F4SE.h>
F4SE_EXPORT constinit auto F4SEPlugin_Version = []() noexcept {
    F4SE::PluginVersionData v{};
    v.PluginVersion({ ${PLUGIN_VERSION_MAJOR}, ${PLUGIN_VERSION_MINOR}, ${PLUGIN_VERSION_PATCH}, 0 });
    v.PluginName("${PLUGIN_NAME}");
    v.AuthorName("${PLUGIN_AUTHOR}");
    v.UsesAddressLibrary(true);
    v.UsesSigScanning(false);
    v.IsLayoutDependent(true);
    v.HasNoStructUse(false);
    v.CompatibleVersions({ F4SE::RUNTIME_LATEST });
    return v;
}();
]]

local PLUGIN_RC_FILE = [[
#include <winres.h>

1 VERSIONINFO
FILEVERSION ${PLUGIN_VERSION_MAJOR}, ${PLUGIN_VERSION_MINOR}, ${PLUGIN_VERSION_PATCH}, 0
PRODUCTVERSION ${PROJECT_VERSION_MAJOR}, ${PROJECT_VERSION_MINOR}, ${PROJECT_VERSION_PATCH}, 0
FILEFLAGSMASK 0x17L
#ifdef _DEBUG
    FILEFLAGS 0x1L
#else
    FILEFLAGS 0x0L
#endif
FILEOS 0x4L
FILETYPE 0x1L
FILESUBTYPE 0x0L
BEGIN
    BLOCK "StringFileInfo"
    BEGIN
        BLOCK "040904b0"
        BEGIN
            VALUE "FileDescription", "${PLUGIN_DESCRIPTION}"
            VALUE "FileVersion", "${PLUGIN_VERSION}.0"
            VALUE "InternalName", "${PLUGIN_NAME}"
            VALUE "LegalCopyright", "${PLUGIN_AUTHOR} | ${PLUGIN_LICENSE}"
            VALUE "ProductName", "${PROJECT_NAME}"
            VALUE "ProductVersion", "${PROJECT_VERSION}.0"
        END
    END
    BLOCK "VarFileInfo"
    BEGIN
        VALUE "Translation", 0x409, 1200
    END
END]]

-- git submodule usage:
-- add_deps("commonlibf4")
-- add_rules("commonlibf4.plugin", {
--     name = "PluginName",
--     author = "Author Name",
--     description = "Plugin Description"
-- })

-- define rules
rule("commonlibf4.plugin")
    add_deps("win.sdk.resource")

    on_config(function(target)
        import("core.base.semver")
        import("core.project.depend")
        import("core.project.project")

        target:set("arch", "x64")
        target:set("kind", "shared")

        target:add("installfiles", target:targetfile(), { prefixdir = "F4SE/Plugins" })
        target:add("installfiles", target:symbolfile(), { prefixdir = "F4SE/Plugins" })

        if os.getenv("XSE_FO4_MODS_PATH") then
            target:set("installdir", path.join(os.getenv("XSE_FO4_MODS_PATH"), target:name()))
        elseif os.getenv("XSE_FO4_GAME_PATH") then
            target:set("installdir", path.join(os.getenv("XSE_FO4_GAME_PATH"), "Data"))
        end

        local conf = target:extraconf("rules", "commonlibf4.plugin")
        local conf_dir = path.join(target:autogendir(), "rules", "commonlibf4", "plugin")

        local conf_map = {
            PLUGIN_AUTHOR                = conf.author or "",
            PLUGIN_DESCRIPTION           = conf.description or "",
            PLUGIN_LICENSE               = (target:license() or "Unknown") .. " License",
            PLUGIN_NAME                  = conf.name or target:name(),
            PLUGIN_VERSION               = target:version() or "0.0.0",
            PLUGIN_VERSION_MAJOR         = semver.new(target:version() or "0.0.0"):major(),
            PLUGIN_VERSION_MINOR         = semver.new(target:version() or "0.0.0"):minor(),
            PLUGIN_VERSION_PATCH         = semver.new(target:version() or "0.0.0"):patch(),
            PROJECT_NAME                 = project.name() or "",
            PROJECT_VERSION              = project.version() or "0.0.0",
            PROJECT_VERSION_MAJOR        = semver.new(project.version() or "0.0.0"):major(),
            PROJECT_VERSION_MINOR        = semver.new(project.version() or "0.0.0"):minor(),
            PROJECT_VERSION_PATCH        = semver.new(project.version() or "0.0.0"):patch(),
        }

        local conf_parse = function(a_str)
            return a_str:gsub("(%${([^\n]-)})", function(_, a_var)
                local result = conf_map[a_var:trim()]
                if type(result) ~= "string" then
                    result = tostring(result)
                end
                assert(result ~= nil, "cannot get variable(%s)", a_var)
                return result
            end)
        end

        local add_file = function(a_path, a_data)
            local file_path = path.join(conf_dir, a_path)
            depend.on_changed(function()
                local file = io.open(file_path, "w")
                if file then
                    file:write(conf_parse(a_data), "\n")
                    file:close()
                end
            end, { dependfile = target:dependfile(file_path), files = project.allfiles()})
            target:add("files", file_path)
        end

        add_file("plugin.cpp", PLUGIN_FILE)
        add_file("version.rc", PLUGIN_RC_FILE)
    end)

    on_install(function(target)
        local srcfiles, dstfiles = target:installfiles()
        if srcfiles and #srcfiles > 0 and dstfiles and #dstfiles > 0 then
            for idx, srcfile in ipairs(srcfiles) do
                os.trycp(srcfile, dstfiles[idx])
            end
        end
    end)

    on_package(function(target)
        import("core.project.config")
        import("core.project.project")
        import("utils.archive")

        local archive_name = target:name() .. "-" .. (target:version() or "0.0.0") .. ".zip"
        print("packing %s .. ", archive_name)

        local root_dir = path.join(os.tmpdir(), "packages", project.name() or "", target:name())
        os.tryrm(root_dir)

        local srcfiles, dstfiles = target:installfiles(path.join(root_dir, "Data"))
        if srcfiles and #srcfiles > 0 and dstfiles and #dstfiles > 0 then
            for idx, srcfile in ipairs(srcfiles) do
                os.trycp(srcfile, dstfiles[idx])
            end
        else
            return
        end

        local archive_path = path.join(config.buildir(), "packages", archive_name)
        local old_dir = os.cd(root_dir)
        local archive_files = os.files("**")
        os.cd(old_dir)
        archive.archive(path.absolute(archive_path), archive_files, { curdir = root_dir })
    end)

    after_build(function(target)
        import("core.project.depend")
        import("core.project.project")
        import("core.project.task")

        depend.on_changed(function()
            local srcfiles, dstfiles = target:installfiles()
            if srcfiles and #srcfiles > 0 and dstfiles and #dstfiles > 0 then 
                task.run("install")
            end
        end, { changed = target:is_rebuilt(), files = { target:targetfile() } })
    end)
