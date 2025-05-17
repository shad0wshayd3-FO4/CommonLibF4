#pragma once

#include "RE/B/BSTerrainEffect.h"
#include "RE/B/BSTempEffectWeaponBlood.h"
#include "RE/B/BSTempEffectScreenSpaceDecal.h"
#include "RE/B/BSTempEffectGeometryDecal.h"
#include "RE/B/BSTempEffectParticle.h"
#include "RE/B/BSTempEffectDebris.h"
#include "RE/B/BSTempEffectSPG.h"
#include "RE/B/BSTempEffect.h"
#include "RE/R/ReferenceEffect.h"
#include "RE/M/ModelReferenceEffect.h"
#include "RE/S/ShaderReferenceEffect.h"
#include "RE/S/SummonPlacementEffect.h"

#define F4SE_TEMPEFFECT_UTIL(a_elem)                                    \
	case a_elem::TYPE:                                                  \
		if constexpr (std::is_convertible_v<const a_elem*, const T*>) { \
			return static_cast<const a_elem*>(this);                    \
		}                                                               \
		break

namespace RE
{
    template <class T, class>
    [[nodiscard]] T* BSTempEffect::As() noexcept
    {
        return const_cast<T*>(static_cast<const BSTempEffect*>(this)->As<T>());
    }

    template <class T, class>
	[[nodiscard]] const T* BSTempEffect::As() const noexcept
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
}

#undef F4SE_TEMPEFFECT_UTIL
