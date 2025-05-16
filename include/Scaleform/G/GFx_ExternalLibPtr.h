#pragma once

namespace Scaleform::GFx
{
	class MovieImpl;

	class __declspec(novtable) ExternalLibPtr
	{
	public:
		ExternalLibPtr(MovieImpl* a_movieRoot) :
			owner(a_movieRoot)
		{}

		virtual ~ExternalLibPtr() = default;

		// members
		MovieImpl* owner;
	};
	static_assert(sizeof(ExternalLibPtr) == 0x10);
}
