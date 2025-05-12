#pragma once

namespace RE
{
	class __declspec(novtable) PowerArmorGeometry :
		public SimpleAnimationGraphManagerHolder,       // 00
		public BSTEventSink<PreloadPowerArmor::Event>,  // 18
		public BSTEventSink<ExitPowerArmor::Event>,     // 20
		public BSIntrusiveRefCounted,                   // 28
		public BSTSingletonSDM<PowerArmorGeometry>      // 2C
	{
	public:
		static constexpr auto RTTI{ RTTI::PowerArmorGeometry };
		static constexpr auto VTABLE{ VTABLE::PowerArmorGeometry };

		virtual ~PowerArmorGeometry();  // 00

		// override
		virtual void                 BackgroundTaskFinishedLoading() override;                                                                            // 01
		virtual BSEventNotifyControl ProcessEvent(const PreloadPowerArmor::Event& a_event, BSTEventSource<PreloadPowerArmor::Event>* a_source) override;  // 02
		virtual BSEventNotifyControl ProcessEvent(const ExitPowerArmor::Event& a_event, BSTEventSource<ExitPowerArmor::Event>* a_source) override;        // 03

		[[nodiscard]] static PowerArmorGeometry* GetSingleton()
		{
			static REL::Relocation<PowerArmorGeometry**> singleton{ REL::ID(1365745) };
			return *singleton;
		}

		void HidePipboyPAGeometry()
		{
			using func_t = decltype(&PowerArmorGeometry::HidePipboyPAGeometry);
			static REL::Relocation<func_t> func{ REL::ID(976332) };
			return func(this);
		}

		void ShowPipboyPAGeometry()
		{
			using func_t = decltype(&PowerArmorGeometry::ShowPipboyPAGeometry);
			static REL::Relocation<func_t> func{ REL::ID(19066) };
			return func(this);
		}

		// members
		BSTValueEventSink<PipboyLightEvent>            pipboySpotLightEvent;        // 030
		BSTValueEventSink<PlayerAmmoCountEvent>        nextAmmoCount;               // 048
		BSTValueEventSink<PlayerWeaponReloadEvent>     playerReloaded;              // 068
		BSTValueEventSink<CurrentRadsDisplayMagnitude> radsCount;                   // 080
		BSTValueEventSink<CurrentRadsPercentOfLethal>  radsPercentOfLethal;         // 0A0
		BSTValueEventSink<CurrentRadiationSourceCount> radiationSourceCount;        // 0C0
		TESImageSpaceModifier* paPipboyEffect;              // 0E0
		NiPointer<NiNode>                              paDashDials;                 // 0E8
		NiPointer<NiNode>                              pipboyPAGlass;               // 0F0
		NiAVObject* paDashLightSpot;             // 0F8
		NiAVObject* paDashLightScope;            // 100
		NiAVObject* paDashLightAux;              // 108
		NiAVObject* paDash;                      // 110
		NiAVObject* plane;                       // 118
		NiAVObject* compass;                     // 120
		BSTArray<void*>                                queued3D;                    // 128
		HUDModes                                       validHUDModes;               // 140
		float                                          radiationSmoother;           // 160
		NiPointer<NiNode>                              dbHUDRain;                   // 168
		bool                                           hudRain;                     // 170
		bool                                           prevShouldBeVisible;         // 171
		bool                                           powerArmorEmergencyLightOn;  // 172
		bool                                           queueInit;                   // 173
		bool                                           prevIsFirstPerson;           // 174
		bool                                           ammoDirty;                   // 175
		bool                                           initialized;                 // 176
	};
	static_assert(sizeof(PowerArmorGeometry) == 0x178);
}
