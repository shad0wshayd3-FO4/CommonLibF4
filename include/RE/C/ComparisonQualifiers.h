#pragma once

namespace RE
{
	namespace ComparisonQualifiers
	{
		inline bool ContainerQualifier(const BSExtraData* a_extraData)
		{
			using func_t = decltype(&ComparisonQualifiers::ContainerQualifier);
			REL::Relocation<func_t> func{ REL::ID(2190674) };
			return func(a_extraData);
		}

		inline bool UIQualifier(const BSExtraData* a_extraData)
		{
			using func_t = decltype(&ComparisonQualifiers::UIQualifier);
			REL::Relocation<func_t> func{ REL::ID(2190675) };
			return func(a_extraData);
		}
	};
}
