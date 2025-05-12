#pragma once

namespace RE
{
	struct __declspec(novtable) BSReloadShaderI
	{
	public:
		static constexpr auto RTTI{ RTTI::BSReloadShaderI };
		static constexpr auto VTABLE{ VTABLE::BSReloadShaderI };

		// add
		virtual void ReloadShaders(BSIStream* a_stream) = 0;  // 00
	};
	static_assert(sizeof(BSReloadShaderI) == 0x8);
}
