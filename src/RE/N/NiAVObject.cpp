#include "RE/N/NiAVObject.h"

#include "RE/B/BSGeometry.h"
#include "RE/B/BSVisit.h"
#include "RE/N/NiNode.h"
#include "RE/N/NiUpdateData.h"

namespace RE
{
	NiAVObject::NiAVObject()
	{
		REX::EMPLACE_VTABLE(this);
		local.MakeIdentity();
		world.MakeIdentity();
		previousWorld.MakeIdentity();
		flags.flags = 0xE;
	}

	NiAVObject::~NiAVObject() {}  // NOLINT(modernize-use-equals-default)

	void NiAVObject::CullGeometry(bool a_cull)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geo) -> BSVisit::BSVisitControl {
			a_geo->SetAppCulled(a_cull);
			return BSVisit::BSVisitControl::kContinue;
		});
	}

	void NiAVObject::CullNode(bool a_cull)
	{
		BSVisit::TraverseScenegraphObjects(this, [&](NiAVObject* a_object) -> BSVisit::BSVisitControl {
			a_object->SetAppCulled(a_cull);
			return BSVisit::BSVisitControl::kContinue;
		});
	}

	void NiAVObject::Update(NiUpdateData& a_data)
	{
		UpdateDownwardPass(a_data, 0);
		if (parent && ((a_data.flags & 0x200) == 0)) {
			parent->UpdateUpwardPass(a_data);
		}
	}
}
