#pragma once

namespace RE
{
	class hkProcessContext
	{
	public:
		hkProcessContext() = default;

		virtual ~hkProcessContext() = default;

		virtual const char* GetType() = 0;

		virtual void SetOwner(hkVisualDebugger* a_owner)
		{
			owner = a_owner;
		}

		// members
		hkVisualDebugger* owner{ nullptr };     // 08
		hkInplaceArray<const char*, 6> monitorStreamBegins;  // 10
		hkInplaceArray<const char*, 6> monitorStreamEnds;    // 50
	};
	static_assert(sizeof(hkProcessContext) == 0x90);
}
