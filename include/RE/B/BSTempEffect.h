#pragma once

#include "RE/N/NiObject.h"
#include "RE/T/TEMP_EFFECT_TYPE.h"

namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;
	class NiAVObject;

	class __declspec(novtable) BSTempEffect :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTempEffect };
		static constexpr auto VTABLE{ VTABLE::BSTempEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTempEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kDefault };

		// add
		virtual void                           Initialize();                                     // 25 - { initialized = true; }
		virtual void                           Attach();                                         // 26 - { return; }
		virtual void                           Detach();                                         // 27 - { return; }
		virtual bool                           Update(float a_arg1);                             // 28
		[[nodiscard]] virtual NiAVObject*      Get3D() const;                                    // 29 - { return 0; }
		[[nodiscard]] virtual bool             GetManagerHandlesSaveLoad() const;                // 2A - { return true; }
		[[nodiscard]] virtual bool             GetClearWhenCellIsUnloaded() const;               // 2B - { return true; }
		[[nodiscard]] virtual TEMP_EFFECT_TYPE GetType() const;                                  // 2C - { return 7; }
		virtual void                           SaveGame(BGSSaveGameBuffer* a_buf);               // 2D
		virtual void                           LoadGame(BGSLoadGameBuffer* a_buf);               // 2E
		virtual void                           FinishLoadGame(BGSLoadGameBuffer* a_buf);         // 2F - { return; }
		[[nodiscard]] virtual bool             IsInterfaceEffect() const;                        // 30 - { return false; }
		virtual void                           SetInterfaceEffect(bool a_set);                   // 31 - { return; }
		[[nodiscard]] virtual bool             GetStackable() const;                             // 32 - { return false; }
		virtual bool                           GetStackableMatch(BSTempEffect* a_effect) const;  // 33 - { return false; }
		virtual void                           Push();                                           // 34 - { return; }
		virtual void                           Pop();                                            // 35 - { return; }
		virtual void                           HandleDeferredDeleteImpl();                       // 36

		template <
			class T,
			class = std::enable_if_t<
				std::negation_v<
					std::disjunction<
						std::is_pointer<T>,
						std::is_reference<T>,
						std::is_const<T>,
						std::is_volatile<T>>>>>
		[[nodiscard]] T* As() noexcept;

		template <
			class T,
			class = std::enable_if_t<
				std::negation_v<
					std::disjunction<
						std::is_pointer<T>,
						std::is_reference<T>,
						std::is_const<T>,
						std::is_volatile<T>>>>>
		[[nodiscard]] const T* As() const noexcept;

		// members
		float          lifetime;     // 10
		TESObjectCELL* cell;         // 18
		float          age;          // 20
		bool           initialized;  // 24
		std::uint32_t  effectID;     // 28
	};
	static_assert(sizeof(BSTempEffect) == 0x30);
}
