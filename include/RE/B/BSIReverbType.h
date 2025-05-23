#pragma once

namespace RE
{
	class __declspec(novtable) BSIReverbType
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIReverbType };
		static constexpr auto VTABLE{ VTABLE::BSIReverbType };

		// add
		virtual std::int32_t DoGetRoomLevel() const = 0;        // 00
		virtual std::int32_t DoGetRoomHFLevel() const = 0;      // 01
		virtual float        DoGetDecayTime() const = 0;        // 02
		virtual float        DoGetDecayHFRatio() const = 0;     // 03
		virtual std::int32_t DoGetReflectionLevel() const = 0;  // 04
		virtual float        DoGetReflectionDelay() const = 0;  // 05
		virtual std::int32_t DoGetReverbLevel() const = 0;      // 06
		virtual float        DoGetReverbDelay() const = 0;      // 07
		virtual float        DoGetDiffusion() const = 0;        // 08
		virtual float        DoGetDensity() const = 0;          // 09
		virtual float        DoGetHFReference() const = 0;      // 0A
	};
	static_assert(sizeof(BSIReverbType) == 0x8);
}
