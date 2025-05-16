#pragma once

namespace Scaleform::GFx::AS3
{
	class ASStringNode;
	class Class;
	class Object;
	class ThunkInfo;
	class Traits;
	class WeakProxy;

	namespace ClassTraits
	{
		class Traits;
	}

	namespace Instances
	{
		class Function;
		class ThunkFunction;

		namespace fl
		{
			class Namespace;
		}
	}

	namespace InstanceTraits
	{
		class Traits;
	}

	class Value
	{
	public:
		struct Extra
		{
		public:
			// members
			WeakProxy* weakProxy;  // 00
		};
		static_assert(sizeof(Extra) == 0x08);

		union V1U
		{
			bool                      vbool;
			std::int32_t              vint;
			std::uint32_t             vuint;
			ASStringNode*             vstr;
			Object*                   vobj;
			Class*                    vclass;
			Instances::Function*      vfunct;
			const ThunkInfo*          vthunk;
			Instances::ThunkFunction* vthunkfunct;
			Instances::fl::Namespace* vnamespace;
			InstanceTraits::Traits*   instanceTraits;
			ClassTraits::Traits*      classTraits;
		};

		union V2U
		{
			Object*       vobj;
			const Traits* traits;
		};

		struct VStruct
		{
		public:
			// members
			V1U _1;  // 00
			V2U _2;  // 08
		};
		static_assert(sizeof(VStruct) == 0x10);

		union VU
		{
			long double number;
			VStruct     VS;
		};

		// members
		std::uint32_t flags;  // 00
		Extra         bonus;  // 08
		VU            value;  // 10
	};
	static_assert(sizeof(Value) == 0x20);
}
