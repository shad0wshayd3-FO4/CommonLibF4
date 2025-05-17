#include "RE/B/BGSCreatedObjectManager.h"

#include "RE/A/AlchemyItem.h"
#include "RE/T/TESForm.h"

namespace RE
{
	template class BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy<AlchemyItem>;
	static_assert(std::is_empty_v<BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy<AlchemyItem>>);

	template class BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy<TESForm>;
	static_assert(std::is_empty_v<BGSCreatedObjectManager::BSTCreatedObjectSmartPointerPolicy<TESForm>>);
}
