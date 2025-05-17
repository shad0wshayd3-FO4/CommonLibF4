#pragma once

namespace RE
{
	enum class SCRIPT_OUTPUT;
	class ConditionCheckParams;
	class SCRIPT_LINE;
	class SCRIPT_PARAMETER;
	class ScriptCompileData;
	class ScriptLocals;

	class SCRIPT_FUNCTION
	{
	public:
		using ConditionFunction_t = bool(ConditionCheckParams& a_data, void* a_param2, void* a_param1, float& a_returnValue);
		using CompileFunction_t = bool(const std::uint16_t a_paramCount, const SCRIPT_PARAMETER* a_parameters, SCRIPT_LINE* a_scriptLine, ScriptCompileData* a_compileData);
		using ExecuteFunction_t = bool(const SCRIPT_PARAMETER* a_parameters, const char* a_compiledParams, TESObjectREFR* a_refObject, TESObjectREFR* a_container, Script* a_script, ScriptLocals* a_scriptLocals, float& a_returnValue, std::uint32_t& a_offset);

		[[nodiscard]] static auto GetConsoleFunctions()
		{
			static REL::Relocation<SCRIPT_FUNCTION(*)[526]> functions{ ID::SCRIPT_FUNCTION::ConsoleFunctions };
			return std::span{ *functions };
		}

		static SCRIPT_FUNCTION* LocateConsoleCommand(const std::string_view a_longName)
		{
			for (auto& command : GetConsoleFunctions()) {
				if (command.functionName && std::strlen(command.functionName) == a_longName.size())
					if (_strnicmp(command.functionName, a_longName.data(), a_longName.size()) == 0)
						return std::addressof(command);
			}

			return nullptr;
		}

		[[nodiscard]] static auto GetScriptFunctions()
		{
			static REL::Relocation<SCRIPT_FUNCTION(*)[819]> functions{ ID::SCRIPT_FUNCTION::ScriptFunctions };
			return std::span{ *functions };
		}

		static SCRIPT_FUNCTION* LocateScriptCommand(const std::string_view a_longName)
		{
			for (auto& command : GetScriptFunctions()) {
				if (command.functionName && std::strlen(command.functionName) == a_longName.size())
					if (_strnicmp(command.functionName, a_longName.data(), a_longName.size()) == 0)
						return std::addressof(command);
			}

			return nullptr;
		}

		// members
		const char*                               functionName{ "" };                        // 00
		const char*                               shortName{ "" };                           // 08
		REX::EnumSet<SCRIPT_OUTPUT, std::int32_t> output;                                    // 10
		const char*                               helpString{ "" };                          // 18
		bool                                      referenceFunction{ false };                // 20
		std::uint16_t                             paramCount{ 0 };                           // 22
		SCRIPT_PARAMETER*                         parameters{ nullptr };                     // 28
		ExecuteFunction_t*                        executeFunction{ nullptr };                // 30
		CompileFunction_t*                        compileFunction{ CompileFunction.get() };  // 38
		ConditionFunction_t*                      conditionFunction{ nullptr };              // 40
		bool                                      editorFilter{ false };                     // 48
		bool                                      invalidatesCellList{ false };              // 49

	private:
		inline static REL::Relocation<CompileFunction_t*> CompileFunction{ ID::SCRIPT_FUNCTION::CompileFunction };
	};
	static_assert(sizeof(SCRIPT_FUNCTION) == 0x50);
}
