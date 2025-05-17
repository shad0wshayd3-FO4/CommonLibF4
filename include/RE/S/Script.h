#pragma once

#include "RE/B/BSSimpleList.h"
#include "RE/S/SCRIPT_HEADER.h"
#include "RE/T/TESForm.h"

namespace RE
{
	enum class COMPILER_NAME;
	class SCRIPT_FUNCTION;
	class SCRIPT_PARAMETER;
	class SCRIPT_REFERENCED_OBJECT;
	class ScriptCompiler;
	class ScriptLocals;
	class ScriptVariable;

	class __declspec(novtable) Script :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::Script };
		static constexpr auto VTABLE{ VTABLE::TESForm };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSCPT };

		template <class... Args>
		static bool ParseParameters(const SCRIPT_PARAMETER* a_parameters, const char* a_compiledParams, std::uint32_t& a_offset, TESObjectREFR* a_refObject, TESObjectREFR* a_container, Script* a_script, ScriptLocals* a_scriptLocals, Args... a_args)
		{
			static_assert((std::is_pointer_v<Args> && ...), "arguments must all be pointers");
			using func_t = bool(const SCRIPT_PARAMETER*, const char*, std::uint32_t&, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, ...);
			static REL::Relocation<func_t> func{ ID::Script::ParseParameters };
			return func(a_parameters, a_compiledParams, a_offset, a_refObject, a_container, a_script, a_scriptLocals, a_args...);
		}

		void CompileAndRun(ScriptCompiler* a_compiler, COMPILER_NAME a_compilerIndex, TESObjectREFR* a_ownerObject)
		{
			using func_t = decltype(&Script::CompileAndRun);
			static REL::Relocation<func_t> func{ ID::Script::CompileAndRun };
			return func(this, a_compiler, a_compilerIndex, a_ownerObject);
		}

		static bool GetProcessScripts()
		{
			using func_t = decltype(&Script::GetProcessScripts);
			static REL::Relocation<func_t> func{ ID::Script::GetProcessScripts };
			return func();
		}

		static void SetProcessScripts(bool a_processScripts)
		{
			using func_t = decltype(&Script::SetProcessScripts);
			static REL::Relocation<func_t> func{ ID::Script::SetProcessScripts };
			return func(a_processScripts);
		}

		void SetText(std::string_view a_text)
		{
			if (text) {
				free(text);
				text = nullptr;
			}

			text = calloc<char>(a_text.length() + 1);
			std::memset(text, '\0', a_text.length() + 1);
			std::memcpy(text, a_text.data(), a_text.length());
		}

		// members
		SCRIPT_HEADER                           header;                       // 20
		char*                                   text;                         // 38
		std::byte*                              data;                         // 40
		float                                   profilerTimer;                // 48
		float                                   questScriptDelay;             // 4C
		float                                   questScriptGetSecondsBuffer;  // 50
		TESQuest*                               parentQuest;                  // 58
		BSSimpleList<SCRIPT_REFERENCED_OBJECT*> refObjects;                   // 60
		BSSimpleList<ScriptVariable*>           variables;                    // 70
	};
	static_assert(sizeof(Script) == 0x80);
}
