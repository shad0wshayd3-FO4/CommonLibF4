#pragma once

namespace Scaleform::GFx
{
	class ResourceKey
	{
	public:
		using KeyHandle = void*;

		enum class KeyType : std::int32_t
		{
			kNone,
			kUnique,
			kFile,
			kGradient,
			kSubImage
		};

		class __declspec(novtable) KeyInterface
		{
		public:
			virtual ~KeyInterface() = default;  // 00

			// add
			virtual void        AddRef(KeyHandle a_data) = 0;                                 // 01
			virtual void        Release(KeyHandle a_data) = 0;                                // 02
			virtual KeyType     GetKeyType(KeyHandle a_data) const = 0;                       // 03
			virtual std::size_t GetHashCode(KeyHandle a_data) const = 0;                      // 04
			virtual bool        KeyEquals(KeyHandle a_data, const ResourceKey& a_other) = 0;  // 05
			virtual const char* GetFileURL(KeyHandle) const { return nullptr; }               // 06
		};
		static_assert(sizeof(KeyInterface) == 0x8);

		// members
		KeyInterface* keyInterface;  // 00
		KeyHandle     keyData;       // 08
	};
	static_assert(sizeof(ResourceKey) == 0x10);
}
