#include "RE/Scaleform/GFx/GFx_Player.h"

#include "RE/Scaleform/GFx/GFx_ASMovieRootBase.h"

namespace RE::Scaleform::GFx
{
	void Movie::CreateArray(Value* a_value)
	{
		asMovieRoot->CreateArray(a_value);
	}

	void Movie::CreateFunction(Value* a_value, FunctionHandler* a_function, void* a_userData)
	{
		asMovieRoot->CreateFunction(a_value, a_function, a_userData);
	}

	void Movie::CreateObject(Value* a_value, const char* a_className, const GFx::Value* a_args, std::uint32_t a_numArgs)
	{
		asMovieRoot->CreateObject(a_value, a_className, a_args, a_numArgs);
	}

	bool Movie::GetVariable(Value* a_val, const char* a_pathToVar) const
	{
		return asMovieRoot->GetVariable(a_val, a_pathToVar);
	}

	bool Movie::SetVariable(const char* a_pathToVar, const Value& a_value, SetVarType a_setType)
	{
		return asMovieRoot->SetVariable(a_pathToVar, a_value, a_setType);
	}

	bool Movie::Invoke(const char* a_methodName, Value* a_result, const char* a_argFmt, ...)
	{
		return asMovieRoot->Invoke(a_methodName, a_result, a_argFmt);
	}

	bool Movie::Invoke(const char* a_methodName, Value* a_result, const Value* a_args, std::uint32_t a_numArgs)
	{
		return asMovieRoot->Invoke(a_methodName, a_result, a_args, a_numArgs);
	}

	bool Movie::InvokeArgs(const char* a_methodName, Value* a_result, const char* a_argFmt, std::va_list a_args)
	{
		return asMovieRoot->InvokeArgs(a_methodName, a_result, a_argFmt, a_args);
	}
}
