#pragma once

namespace RE
{
	struct SCRIPT_FUNCTION
	{
	public:
		using ConditionFunction_t = bool(ConditionCheckParams& a_data, void* a_param2, void* a_param1, float& a_returnValue);
		using CompileFunction_t = bool(const std::uint16_t a_paramCount, const SCRIPT_PARAMETER* a_parameters, SCRIPT_LINE* a_scriptLine, ScriptCompileData* a_compileData);
		using ExecuteFunction_t = bool(const SCRIPT_PARAMETER* a_parameters, const char* a_compiledParams, TESObjectREFR* a_refObject, TESObjectREFR* a_container, Script* a_script, ScriptLocals* a_scriptLocals, float& a_returnValue, std::uint32_t& a_offset);

		[[nodiscard]] static auto GetConsoleFunctions()
		{
			static REL::Relocation<SCRIPT_FUNCTION(*)[526]> functions{ REL::ID(901511) };
			return std::span{ *functions };
		}

		[[nodiscard]] static auto GetScriptFunctions()
		{
			static REL::Relocation<SCRIPT_FUNCTION(*)[819]> functions{ REL::ID(75173) };
			return std::span{ *functions };
		}

		// members
		const char*                               functionName{ "" };                                                                // 00
		const char*                               shortName{ "" };                                                                   // 08
		REX::EnumSet<SCRIPT_OUTPUT, std::int32_t> output;                                                                            // 10
		const char*                               helpString{ "" };                                                                  // 18
		bool                                      referenceFunction{ false };                                                        // 20
		std::uint16_t                             paramCount{ 0 };                                                                   // 22
		SCRIPT_PARAMETER*                         parameters{ nullptr };                                                             // 28
		ExecuteFunction_t*                        executeFunction{ nullptr };                                                        // 30
		CompileFunction_t*                        compileFunction{ REL::Relocation<CompileFunction_t*>{ REL::ID(2204343) }.get() };  // 38
		ConditionFunction_t*                      conditionFunction{ nullptr };                                                      // 40
		bool                                      editorFilter{ false };                                                             // 48
		bool                                      invalidatesCellList{ false };                                                      // 49
	};
	static_assert(sizeof(SCRIPT_FUNCTION) == 0x50);
}
