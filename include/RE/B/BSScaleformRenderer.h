#pragma once

namespace RE
{
	struct BSScaleformRenderer :
		public BSTEventSource<SFRendererInitializedEvent>  // 000
	{
	public:
		void Initialize()
		{
			using func_t = decltype(&BSScaleformRenderer::Initialize);
			static REL::Relocation<func_t> func{ REL::ID(2284938) };
			return func(this);
		}

		// members
		Scaleform::Ptr<Scaleform::Render::Renderer2D>     renderer;            // 058
		Scaleform::Ptr<Scaleform::Render::HAL>            renderConfig;        // 060
		Scaleform::Ptr<Scaleform::Render::TextureManager> textureManager;      // 068
		Scaleform::Render::RenderTarget* renderTargets[100];  // 070
		bool                                              initialized;         // 390
	};
	static_assert(sizeof(BSScaleformRenderer) == 0x398);
}
