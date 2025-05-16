#pragma once

#include "Scaleform/F/Flags.h"
#include "Scaleform/G/GFx_StateBag.h"

namespace Scaleform::GFx
{
	class LoaderImpl;
	class MovieDef;
	class ResourceLib;

	class __declspec(novtable) Loader :
		public StateBag  // 00
	{
	public:
		enum class LoadConstants : std::uint32_t
		{
			kAll = 0,
			kWaitCompletion = 1 << 0,
			kWaitFrame1 = 1 << 1,
			kOrdered = 1 << 4,
			kOnThread = 1 << 6,
			kKeepBindData = 1 << 7,
			kImageFiles = 1 << 16,
			kDisableSWF = 1 << 19,
			kDisableImports = 1 << 20,
			kQuietOpen = 1 << 21,

			kDebugHeap = 1 << 28
		};

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~Loader();  // 00

		// add
		virtual bool CheckTagLoader(std::int32_t a_tagType) const;  // 04

		[[nodiscard]] MovieDef* CreateMovie(const char* a_filename, Flags<LoadConstants> a_loadConstants = LoadConstants::kAll, std::size_t a_memoryArena = 0)
		{
			using func_t = decltype(&Loader::CreateMovie);
			static REL::Relocation<func_t> func{ REL::ID(2284723) };
			return func(this, a_filename, a_loadConstants, a_memoryArena);
		}

		// members
		LoaderImpl*          impl;               // 08
		ResourceLib*         strongResourceLib;  // 10
		Flags<LoadConstants> defLoadFlags;       // 18
	};
	static_assert(sizeof(Loader) == 0x20);
}
