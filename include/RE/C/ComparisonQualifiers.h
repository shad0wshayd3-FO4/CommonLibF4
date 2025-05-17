#pragma once

namespace RE
{
	class BSExtraData;

	namespace ComparisonQualifiers
	{
		inline bool ContainerQualifier(const BSExtraData* a_extraData)
		{
			using func_t = decltype(&ComparisonQualifiers::ContainerQualifier);
			static REL::Relocation<func_t> func{ REL::ID(2190674) };
			return func(a_extraData);
		}

		inline bool UIQualifier(const BSExtraData* a_extraData)
		{
			using func_t = decltype(&ComparisonQualifiers::UIQualifier);
			static REL::Relocation<func_t> func{ REL::ID(2190675) };
			return func(a_extraData);
		}
	};
}
