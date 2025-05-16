#include "RE/M/MenuCursor.h"

#include "RE/S/Setting.h"

namespace RE
{
	void MenuCursor::ConstrainForPipboy()
	{
		static REL::Relocation<Setting*> tlx{ REL::ID(60674) };
		static REL::Relocation<Setting*> tly{ REL::ID(719279) };
		static REL::Relocation<Setting*> width{ REL::ID(1376729) };
		static REL::Relocation<Setting*> height{ REL::ID(452591) };
		SetCursorConstraintsRaw(tlx->GetUInt(), tly->GetUInt(), width->GetUInt(), height->GetUInt());
	}

	void MenuCursor::ConstrainForPipboyPA()
	{
		static REL::Relocation<Setting*> tlx{ REL::ID(1110986) };
		static REL::Relocation<Setting*> tly{ REL::ID(187113) };
		static REL::Relocation<Setting*> width{ REL::ID(844985) };
		static REL::Relocation<Setting*> height{ REL::ID(1503497) };
		SetCursorConstraintsRaw(tlx->GetUInt(), tly->GetUInt(), width->GetUInt(), height->GetUInt());
	}
}
