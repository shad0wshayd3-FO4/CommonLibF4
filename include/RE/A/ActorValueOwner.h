#pragma once

namespace RE
{
	enum class ACTOR_VALUE_MODIFIER;

	class __declspec(novtable) ActorValueOwner
	{
	public:
		static constexpr auto RTTI{ RTTI::ActorValueOwner };
		static constexpr auto VTABLE{ VTABLE::ActorValueOwner };

		virtual ~ActorValueOwner() = default;  // 00

		// add
		virtual float GetActorValue([[maybe_unused]] const ActorValueInfo& a_info) const { return 0.0F; }                                                                         // 01
		virtual float GetPermanentActorValue([[maybe_unused]] const ActorValueInfo& a_info) const { return 0.0F; }                                                                // 02
		virtual float GetBaseActorValue([[maybe_unused]] const ActorValueInfo& a_info) const { return 0.0F; }                                                                     // 03
		virtual void  SetBaseActorValue([[maybe_unused]] const ActorValueInfo& a_info, [[maybe_unused]] float a_value) { return; }                                                // 04
		virtual void  ModBaseActorValue([[maybe_unused]] const ActorValueInfo& a_info, [[maybe_unused]] float a_delta) { return; }                                                // 05
		virtual void  ModActorValue([[maybe_unused]] ACTOR_VALUE_MODIFIER a_modifier, [[maybe_unused]] const ActorValueInfo& a_info, [[maybe_unused]] float a_delta) { return; }  // 06
		virtual float GetModifier([[maybe_unused]] ACTOR_VALUE_MODIFIER a_modifier, [[maybe_unused]] const ActorValueInfo& a_info) const { return 0.0F; }                         // 07
		virtual void  RestoreActorValue([[maybe_unused]] const ActorValueInfo& a_info, [[maybe_unused]] float a_amount) { return; }                                               // 08
		virtual void  SetActorValue(const ActorValueInfo& a_info, float a_value) { SetBaseActorValue(a_info, a_value); }                                                          // 09
		virtual bool  GetIsPlayerOwner() const { return false; }                                                                                                                  // 0A
	};
	static_assert(sizeof(ActorValueOwner) == 0x8);
}
