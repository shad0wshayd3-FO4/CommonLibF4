#pragma once

#define F4SE_TEMPEFFECT_UTIL(a_elem)                                    \
	case a_elem::TYPE:                                                  \
		if constexpr (std::is_convertible_v<const a_elem*, const T*>) { \
			return static_cast<const a_elem*>(this);                    \
		}                                                               \
		break

namespace RE
{
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
		[[nodiscard]] T* As() noexcept
		{
			return const_cast<T*>(static_cast<const BSTempEffect*>(this)->As<T>());
		}

		template <
			class T,
			class = std::enable_if_t<
				std::negation_v<
					std::disjunction<
						std::is_pointer<T>,
						std::is_reference<T>,
						std::is_const<T>,
						std::is_volatile<T>>>>>
		[[nodiscard]] const T* As() const noexcept
		{
			switch (GetType()) {
				F4SE_TEMPEFFECT_UTIL(BSTerrainEffect);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectWeaponBlood);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectScreenSpaceDecal);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectGeometryDecal);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectParticle);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectDebris);
				F4SE_TEMPEFFECT_UTIL(BSTempEffectSPG);
				F4SE_TEMPEFFECT_UTIL(BSTempEffect);
				F4SE_TEMPEFFECT_UTIL(ReferenceEffect);
				F4SE_TEMPEFFECT_UTIL(ModelReferenceEffect);
				F4SE_TEMPEFFECT_UTIL(ShaderReferenceEffect);
				F4SE_TEMPEFFECT_UTIL(SummonPlacementEffect);
				default:
					break;
			}

			return nullptr;
		}

		// members
		float          lifetime;     // 10
		TESObjectCELL* cell;         // 18
		float          age;          // 20
		bool           initialized;  // 24
		std::uint32_t  effectID;     // 28
	};
	static_assert(sizeof(BSTempEffect) == 0x30);
}

#undef F4SE_TEMPEFFECT_UTIL
