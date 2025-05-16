#pragma once

#include "Scaleform/G/GFx_FileTypeConstants.h"
#include "Scaleform/G/GFx_State.h"

namespace Scaleform::GFx
{
	class __declspec(novtable) StateBag :
		public FileTypeConstants  // 00
	{
	protected:
		// add
		virtual StateBag* GetStateBagImpl() const { return nullptr; }  // 00

	public:
		virtual ~StateBag() = default;  // 01

		// NOLINTNEXTLINE(misc-no-recursion)
		virtual void SetState(State::StateType a_stateType, State* a_state)  // 02
		{
			assert(a_state ? true : a_state->GetStateType() == a_stateType);
			const auto bag = GetStateBagImpl();
			if (bag) {
				bag->SetState(a_stateType, a_state);
			}
		}

		// NOLINTNEXTLINE(misc-no-recursion)
		virtual State* GetStateAddRef(State::StateType a_stateType) const  // 03
		{
			const auto bag = GetStateBagImpl();
			return bag ? bag->GetStateAddRef(a_stateType) : nullptr;
		}

		virtual void GetStatesAddRef(State** a_states, const State::StateType* a_stateTypes, std::uint32_t a_count) const  // 04
		{
			const auto bag = GetStateBagImpl();
			if (bag) {
				bag->GetStatesAddRef(a_states, a_stateTypes, a_count);
			}
		}
	};
	static_assert(sizeof(StateBag) == 0x8);
}
