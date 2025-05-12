#pragma once

#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkProcessContext.h"

namespace RE
{
	class hknpProcessContext :
		public hkReferencedObject,
		public hkProcessContext
	{
	public:
		hknpProcessContext() = default;

		virtual const char* GetType() override
		{
			return "Physics";
		}

		void AddWorld(hknpWorld* a_world)
		{
			for (auto world : worlds) {
				if (world == a_world)
					return;
			}

			worlds.push_back(a_world);
		}

		void SetColorScheme(hknpViewerColorScheme* a_colorScheme)
		{
			if (a_colorScheme)
				colorScheme = a_colorScheme;
			else
				colorScheme = &defaultColorScheme;
		}

		// members
		hkArray<hknpWorld*>                  worlds;                              // A0
		hkArray<hknpProcessContextListener*> addListeners;                        // B0
		hknpViewerColorScheme*               colorScheme{ &defaultColorScheme };  // C0
		hknpDefaultViewerColorScheme         defaultColorScheme;                  // C8
		hkTaskQueue*                         taskQueue{ nullptr };                // E8
	};
	static_assert(sizeof(hknpProcessContext) == 0xF0);
}
