#pragma once

#include "RE/B/BSTPoint.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiNode;
	class TESCameraState;

	class __declspec(novtable) TESCamera
	{
	public:
		static constexpr auto RTTI{ RTTI::TESCamera };
		static constexpr auto VTABLE{ VTABLE::TESCamera };

		virtual ~TESCamera();  // 00

		// add
		virtual void SetCameraRoot(NiNode* a_cameraRoot);                 // 01
		virtual void SetEnabled(bool a_enabled) { enabled = a_enabled; }  // 02
		virtual void Update();                                            // 03

		// members
		BSTPoint2<float>                rotationInput;     // 08
		BSTPoint3<float>                translationInput;  // 10
		float                           zoomInput;         // 1C
		NiPointer<NiNode>               cameraRoot;        // 20
		BSTSmartPointer<TESCameraState> currentState;      // 28
		bool                            enabled;           // 30
	};
	static_assert(sizeof(TESCamera) == 0x38);
}
