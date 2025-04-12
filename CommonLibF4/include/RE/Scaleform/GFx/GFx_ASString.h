#pragma once

#include "RE/Scaleform/Kernel/SF_RefCount.h"

namespace RE::Scaleform::GFx
{
	class ASStringNode;

	class __declspec(novtable) alignas(0x08) ASStringManager :
		public RefCountBase<ASStringManager, 324>  // 00
	{
	public:
		[[nodiscard]] ASStringNode* CreateStringNode(const char* a_str)
		{
			using func_t = decltype(&ASStringManager::CreateStringNode);
			static REL::Relocation<func_t> func{ REL::ID(2290014) };
			return func(this, a_str);
		}

		// members
		std::byte pad10[0xA0 - 0x10];  // 10
	};
	static_assert(sizeof(ASStringManager) == 0xA0);

	class ASStringNode
	{
	public:
		// members
		const char*      data;     // 00
		ASStringManager* manager;  // 08
		union
		{
			ASStringNode* lower;
			ASStringNode* next;
		};  // 10
		std::uint32_t refCount;   // 18
		std::uint32_t hashFlags;  // 1C
		std::uint32_t size;       // 20
	};
	static_assert(sizeof(ASStringNode) == 0x28);

	class ASStringNodeHolder
	{
	public:
		// members
		ASStringNode* node;  // 00
	};
	static_assert(sizeof(ASStringNodeHolder) == 0x08);

	class ASConstString :
		public ASStringNodeHolder
	{
	public:
		const char* ToCStr() const noexcept
		{
			return node->data;
		}
	};
	static_assert(sizeof(ASConstString) == 0x08);

	class ASString :
		public ASConstString
	{
	public:
	};
	static_assert(sizeof(ASString) == 0x08);

	template <class T, std::int32_t STAT>
	class ASStringBuiltinManagerT
	{
	public:
		// members
		ASStringNodeHolder builtins[STAT];  // 00
		ASStringManager*   stringManager;   // ??
		const char**       staticStrings;   // ??+08
	};
	static_assert(sizeof(ASStringBuiltinManagerT<void, 65>) == 0x218);
}
