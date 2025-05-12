#pragma once

namespace RE
{
	class __declspec(novtable) ImageSpaceEffect
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceEffect };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceEffect };

		struct EffectDesc
		{
		public:
			// members
			std::uint32_t     startEffect;   // 00
			std::uint32_t     lastEffect;    // 04
			ImageSpaceEffect* parentEffect;  // 08
			std::uint64_t     labelWait;     // 10
			std::uint64_t* writeLabel;    // 18
		};
		static_assert(sizeof(EffectDesc) == 0x20);

		struct EffectInput
		{
		public:
			// members
			std::int32_t                  texIndex;    // 00
			BSGraphics::TextureFilterMode filterMode;  // 04
		};
		static_assert(sizeof(EffectInput) == 0x08);

		virtual ~ImageSpaceEffect();  // 00

		// add
		virtual void Render(BSTriShape* a_geometry, ImageSpaceEffectParam* a_param);                                                   // 01
		virtual void Dispatch(ImageSpaceEffectParam* a_param, bool a_useAsyncPipe, std::uint32_t a_effect, EffectDesc* a_effectDesc);  // 02
		virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param);                                              // 03
		virtual void Shutdown();                                                                                                       // 04
		virtual void BorrowTextures(ImageSpaceEffectParam* a_param);                                                                   // 05
		virtual void ReturnTextures();                                                                                                 // 06
		virtual void UpdateComputeShaderParam(std::uint32_t a_effect);                                                                 // 07
		virtual bool IsActive();                                                                                                       // 08
		virtual bool UpdateParams(ImageSpaceEffectParam* a_param);                                                                     // 09
		virtual bool SetRenderStates(ImageSpaceEffectParam* a_param);                                                                  // 0A
		virtual bool RestoreRenderStates(ImageSpaceEffectParam* a_param);                                                              // 0B

		// members
		bool                                      isActive;              // 08
		bool                                      paramsChanged;         // 09
		NiTPrimitiveArray<ImageSpaceEffect*>      effectList;            // 10
		NiTPrimitiveArray<ImageSpaceEffectParam*> effectParamList;       // 28
		NiTPrimitiveArray<ImageSpaceTexture*>     textures;              // 40
		NiTPrimitiveArray<ImageSpaceTexture*>     vsTextures;            // 58
		NiTPrimitiveArray<EffectInput*>           effectInputs;          // 70
		NiTPrimitiveArray<std::int32_t*>          effectOutput;          // 88
		bool                                      isComputeShader;       // A0
		std::uint32_t                             nbOutput;              // A4
		bool                                      useDynamicResolution;  // A8
	};
	static_assert(sizeof(ImageSpaceEffect) == 0xB0);
}
