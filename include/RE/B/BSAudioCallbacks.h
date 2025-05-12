#pragma once

namespace RE
{
	class BSAudioCallbacks
	{
	public:
		using IDCallback_t = bool (*)(std::uint32_t, const BSISoundDescriptor**);
		using NameCallback_t = bool (*)(const char*, const BSISoundDescriptor**);
		using PostProcessCallback = void (*)();

		// members
		IDCallback_t        idCallback;           // 00
		NameCallback_t      nameCallback;         // 08
		PostProcessCallback postProcessCallback;  // 10
	};
	static_assert(sizeof(BSAudioCallbacks) == 0x18);
}
