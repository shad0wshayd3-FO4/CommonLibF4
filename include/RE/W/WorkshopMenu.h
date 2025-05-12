#pragma once

namespace RE
{
	class __declspec(novtable) WorkshopMenu :
		public GameMenuBase,                                 // 000
		public BSTEventSink<UserEventEnabledEvent>,          // 0E0
		public BSTEventSink<Workshop::BuildableAreaEvent>,   // 0E8
		public BSTEventSink<PickRefUpdateEvent>,             // 0F0
		public BSTEventSink<Workshop::PlacementStatusEvent>  // 0F8
	{
	public:
		static constexpr auto RTTI{ RTTI::WorkshopMenu };
		static constexpr auto VTABLE{ VTABLE::WorkshopMenu };
		static constexpr auto MENU_NAME{ "WorkshopMenu"sv };

		class FXWorkshopMenu :
			public BSGFxShaderFXTarget  // 000
		{
		public:
			// members
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground1;            // 0B0
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground2;            // 0B8
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground3;            // 0C0
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground4;            // 0C8
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground5;            // 0D0
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground6;            // 0D8
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground7;            // 0E0
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground8;            // 0E8
			msvc::unique_ptr<BSGFxShaderFXTarget> buttonBackground;            // 0F0
			msvc::unique_ptr<BSGFxShaderFXTarget> iconCardBackground;          // 0F8
			msvc::unique_ptr<BSGFxShaderFXTarget> requirementsListBackground;  // 100
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessPeopleBase;         // 108
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessFoodBase;           // 110
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessWaterBase;          // 118
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessPowerBase;          // 120
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessSafetyBase;         // 128
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessBedsBase;           // 130
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessHappyValue;         // 138
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessHappyLabel;         // 140
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessHappyIcon;          // 148
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessHappyArrow;         // 150
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessSizeBase;           // 158
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessBarBrackets;        // 160
			msvc::unique_ptr<BSGFxShaderFXTarget> requirementsBase;            // 168
			msvc::unique_ptr<BSGFxShaderFXTarget> itemName;                    // 170
			msvc::unique_ptr<BSGFxShaderFXTarget> selectionBracket;            // 178
			msvc::unique_ptr<BSGFxShaderFXTarget> itemCounts;                  // 180
			msvc::unique_ptr<BSGFxShaderFXTarget> newRecipeIcon;               // 188
			msvc::unique_ptr<BSGFxShaderFXTarget> iconCardBracketsAndText;     // 190
			msvc::unique_ptr<BSGFxShaderFXTarget> producesIcons;               // 198
			msvc::unique_ptr<BSGFxShaderFXTarget> requiresIcon1;               // 1A0
			msvc::unique_ptr<BSGFxShaderFXTarget> requiresIcon2;               // 1A8
			msvc::unique_ptr<BSGFxShaderFXTarget> assignmentIcon;              // 1B0
			msvc::unique_ptr<BSGFxShaderFXTarget> rowBrackets;                 // 1B8
			msvc::unique_ptr<BSGFxShaderFXTarget> displayPath;                 // 1C0
			msvc::unique_ptr<BSGFxShaderFXTarget> perkPanel1;                  // 1C8
			msvc::unique_ptr<BSGFxShaderFXTarget> perkPanel2;                  // 1D0
			msvc::unique_ptr<BSGFxShaderFXTarget> descriptionBase;             // 1D8
			msvc::unique_ptr<BSGFxShaderFXTarget> iconBackground;              // 1E0
		};
		static_assert(sizeof(FXWorkshopMenu) == 0x1E8);

		struct IconBG
		{
		public:
			BSTAlignedArray<UIShaderFXInfo> cachedColorFXInfos;       // 00
			BSTAlignedArray<UIShaderFXInfo> cachedBackgroundFXInfos;  // 18
			BSReadWriteLock                 cachedQuadsLock;          // 30
		};
		static_assert(sizeof(IconBG) == 0x38);

		void CheckAndSetItemForPlacement()
		{
			using func_t = decltype(&WorkshopMenu::CheckAndSetItemForPlacement);
			static REL::Relocation<func_t> func{ REL::ID(1541862) };
			return func(this);
		}

		void UpdateButtonText()
		{
			using func_t = decltype(&WorkshopMenu::UpdateButtonText);
			static REL::Relocation<func_t> func{ REL::ID(1089189) };
			return func(this);
		}

		// members
		BSTArray<NiPoint3>                                                                          item3DPositions[4];                      // 100
		BSTArray<BSTTuple<DisplayItemModel, TESObjectREFR*>>                                        displayItemModels;                       // 160
		IconBG                                                                                      iconBG;                                  // 178
		Inventory3DManager                                                                          inv3DModelManager;                       // 1B0
		BSTArray<BSTTuple<NiPointer<nsInventory3DManager::NewInventoryMenuItemLoadTask>, NiPoint3>> loadTasks;                               // 2F0
		BSTInterpolator<float, EaseOutInterpolator, GetCurrentPositionFunctor>                      upDownGlassAnimationInterpolator;        // 308
		BSTInterpolator<float, EaseOutInterpolator, GetCurrentPositionFunctor>                      leftRightGlassAnimationInterpolator[4];  // 320
		BSTSmartPointer<WorkshopMenuGeometry>                                                       displayGeometry;                         // 380
		BSFixedString                                                                               dpadInput;                               // 388
		BGSListForm                                                                                 includeList;                             // 390
		BGSListForm                                                                                 excludeList;                             // 3D8
		long double                                                                                 lastBudget;                              // 420
		std::uint16_t                                                                               topMenuCount;                            // 428
		bool                                                                                        inputAdjustMode;                         // 42A
		bool                                                                                        verticalAdjustment;                      // 42B
		bool                                                                                        disableAdjustOnThumbEvent;               // 42C
		bool                                                                                        initialized;                             // 42D
		bool                                                                                        inEditMode;                              // 42E
		bool                                                                                        electricalDevice;                        // 42F
		bool                                                                                        useMovementAsDirectional;                // 430
		bool                                                                                        motionBlurActive;                        // 431
		bool                                                                                        exitDebounce;                            // 432
		msvc::unique_ptr<FXWorkshopMenu>                                                            workshopMenuBase;                        // 438
	};
	static_assert(sizeof(WorkshopMenu) == 0x440);

}
