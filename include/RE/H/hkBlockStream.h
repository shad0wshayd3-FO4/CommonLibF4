#pragma once

namespace RE
{
	template <class T>
	class hkBlockStream :
		public hkBlockStreamBase::Stream  // 00
	{
	public:
		class Consumer;
		class Modifier;
		class Reader;
		class Writer;
	};
}
