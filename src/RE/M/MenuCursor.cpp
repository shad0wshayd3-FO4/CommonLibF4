#include "RE/M/MenuCursor.h"

#include "RE/S/Setting.h"

namespace RE
{
	void MenuCursor::ConstrainForPipboy()
	{
		static REL::Relocation<Setting*> TLX{ ID::MenuCursor::PipboyConstraintTLX };
		static REL::Relocation<Setting*> TLY{ ID::MenuCursor::PipboyConstraintTLY };
		static REL::Relocation<Setting*> Width{ ID::MenuCursor::PipboyConstraintWidth };
		static REL::Relocation<Setting*> Height{ ID::MenuCursor::PipboyConstraintHeight };
		SetCursorConstraintsRaw(TLX->GetUInt(), TLY->GetUInt(), Width->GetUInt(), Height->GetUInt());
	}

	void MenuCursor::ConstrainForPipboyPA()
	{
		static REL::Relocation<Setting*> TLX{ ID::MenuCursor::PipboyConstraintTLX_PowerArmor };
		static REL::Relocation<Setting*> TLY{ ID::MenuCursor::PipboyConstraintTLY_PowerArmor };
		static REL::Relocation<Setting*> Width{ ID::MenuCursor::PipboyConstraintWidth_PowerArmor };
		static REL::Relocation<Setting*> Height{ ID::MenuCursor::PipboyConstraintHeight_PowerArmor };
		SetCursorConstraintsRaw(TLX->GetUInt(), TLY->GetUInt(), Width->GetUInt(), Height->GetUInt());
	}
}
