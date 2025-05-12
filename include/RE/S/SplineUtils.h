#pragma once

namespace RE
{
	class TESObjectREFR;

	namespace SplineUtils
	{
		inline void DisconnectSpline(TESObjectREFR& a_spline)
		{
			using func_t = decltype(&DisconnectSpline);
			static REL::Relocation<func_t> func{ REL::ID(750682) };
			return func(a_spline);
		}

		inline void ConnectSpline(TESObjectREFR* akEndpoint1, int32_t linkType1, TESObjectREFR* akEndpoint2, int32_t linkType2, TESObjectREFR* akWireRef)
		{
			using func_t = decltype(&ConnectSpline);
			static REL::Relocation<func_t> func{ REL::ID(59311) };
			return func(akEndpoint1, linkType1, akEndpoint2, linkType2, akWireRef);
		}
	}
}
