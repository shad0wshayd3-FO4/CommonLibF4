#pragma once

namespace RE
{
	class BSTextureDB
	{
	public:
		class DBTraits
		{
		public:
			class ArgsType
			{
			public:
				// members
				std::uint32_t loadLevel;         // 00
				bool          isCubeMap;         // 04
				bool          replicateCubeMap;  // 05
				bool          isDDX;             // 06
				bool          isSRGB;            // 07
				bool          allowDegrade;      // 08
			};
			static_assert(sizeof(ArgsType) == 0x0C);
		};
		static_assert(std::is_empty_v<DBTraits>);
	};
}
