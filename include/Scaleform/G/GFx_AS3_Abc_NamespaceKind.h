#pragma once

namespace Scaleform::GFx::AS3::Abc
{
	enum class NamespaceKind : std::int32_t
	{
		kUndefined = -1,
		kPublic,
		kProtected,
		kStaticProtected,
		kPrivate,
		kExplicit,
		kPackageInternal
	};
}
