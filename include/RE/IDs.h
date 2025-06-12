#pragma once

namespace RE::ID
{
	namespace ActiveEffect
	{
		inline constexpr REL::ID CheckDisplacementSpellOnTarget{ 1415178 };
	}

	namespace Actor
	{
		inline constexpr REL::ID AddPerk{ 2230121 };
		inline constexpr REL::ID CanUseIdle{ 2229592 };
		inline constexpr REL::ID ClearAttackStates{ 2229773 };
		inline constexpr REL::ID EndInterruptPackage{ 2229892 };
		inline constexpr REL::ID ExitCover{ 2231166 };
		inline constexpr REL::ID GetAimVector{ 2230378 };
		inline constexpr REL::ID GetClosestBone{ 2230051 };
		inline constexpr REL::ID GetCollisionFilter{ 2277949 };
		inline constexpr REL::ID GetCombatStyle{ 2231053 };
		inline constexpr REL::ID SetCurrentAmmoCount{ 2229952 };
		inline constexpr REL::ID GetCurrentCollisionGroup{ 410500 };
		inline constexpr REL::ID GetCurrentFireLocation{ 2231167 };
		inline constexpr REL::ID GetDesiredSpeed{ 2230410 };
		inline constexpr REL::ID GetHostileToActor{ 2229968 };
		inline constexpr REL::ID GetMountHandle{ 2231230 };
		inline constexpr REL::ID GetLevel{ 2229734 };
		inline constexpr REL::ID GetPerkRank{ 2230125 };
		inline constexpr REL::ID GetSex{ 2229674 };
		inline constexpr REL::ID HandleDefaultAnimationSwitch{ 2229780 };
		inline constexpr REL::ID HandleItemEquip{ 2229781 };
		inline constexpr REL::ID InitiateDoNothingPackage{ 2229807 };
		inline constexpr REL::ID IsCrippled{ 1238666 };
		inline constexpr REL::ID IsFollowing{ 2230013 };
		inline constexpr REL::ID IsJumping{ 2229640 };
		inline constexpr REL::ID IsPathValid{ 2230279 };
		inline constexpr REL::ID IsPathing{ 2234312 };
		inline constexpr REL::ID IsPathingComplete{ 2230274 };
		inline constexpr REL::ID IsQuadruped{ 2229614 };
		inline constexpr REL::ID IsSneaking{ 2207655 };
		inline constexpr REL::ID Move{ 2229934 };
		inline constexpr REL::ID PerformAction{ 2231177 };
		inline constexpr REL::ID RemovePerk{ 2230122 };
		inline constexpr REL::ID Reset3D{ 2229913 };
		inline constexpr REL::ID RewardExperience{ 2230428 };
		inline constexpr REL::ID SetGunState{ 2231175 };
		inline constexpr REL::ID SetHeading{ 2229625 };
		inline constexpr REL::ID TrespassAlarm{ 2229834 };
		inline constexpr REL::ID UpdateVoiceTimer{ 2230178 };
		inline constexpr REL::ID GetBodyPartData{ 2229571 };
		inline constexpr REL::ID GetEquippedItem{ 2231089 };
		inline constexpr REL::ID GetCrimeTrackingFaction{ 2229787 };
		inline constexpr REL::ID ForceDetect{ 2230194 };
	}

	namespace ActorEquipManager
	{
		inline constexpr REL::ID Singleton{ 2690994 };
		inline constexpr REL::ID EquipObject{ 2231392 };
		inline constexpr REL::ID UnequipObject{ 2231395 };
		inline constexpr REL::ID UnequipItem{ 2231399 };
	}

	namespace ActorUtils
	{
		namespace ArmorRatingVisitorBase
		{
			inline constexpr REL::ID _operator{ 2227206 };
			inline constexpr REL::ID ctor{ 2227205 };
		}
	}

	namespace ActorValue
	{
		inline constexpr REL::ID Singleton{ 2189587 };
	}

	namespace AIProcess
	{
		inline constexpr REL::ID GetCurrentAmmo{ 2232300 };
		inline constexpr REL::ID GetCommandType{ 2231825 };
		inline constexpr REL::ID GetOccupiedFurniture{ 2232401 };
		inline constexpr REL::ID IsWeaponSubgraphFinishedLoading{ 2231757 };
		inline constexpr REL::ID KnockExplosion{ 2232384 };
		inline constexpr REL::ID ProcessGreet{ 2231808 };
		inline constexpr REL::ID RequestLoadAnimationsForWeaponChange{ 2231758 };
		inline constexpr REL::ID SetActorsDetectionEvent{ 2231738 };
		inline constexpr REL::ID SetCurrentAmmo{ 2232302 };
		inline constexpr REL::ID SetCommandType{ 2231826 };
		inline constexpr REL::ID SetEquippedItem{ 1200276 };
		inline constexpr REL::ID SetupSpecialIdle{ 2231704 };
		inline constexpr REL::ID SetWeaponBonesCulled{ 2232535 };
		inline constexpr REL::ID StopCurrentIdle{ 2231705 };
	}

	namespace AnimationSystemUtils
	{
		inline constexpr REL::ID WillEventChangeState{ 35074 };
	}

	namespace ApplyChangesFunctor
	{
		inline constexpr REL::ID WriteDataImpl{ 2223194 };
	}

	namespace ApplyColorUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 2707340 };
	}

	namespace BarterMenu
	{
		inline constexpr REL::ID ClearTradingData{ 1112285 };
		inline constexpr REL::ID CompleteTrade{ 379932 };
		inline constexpr REL::ID GetCapsOwedByPlayer{ 672405 };
	}

	namespace BGSAnimationSystemUtils
	{
		inline constexpr REL::ID GetActiveSyncInfo{ 1349978 };
		inline constexpr REL::ID InitializeActorInstant{ 672857 };
		inline constexpr REL::ID IsActiveGraphInTransition{ 839650 };
	}

	namespace BGSAttachParentArray
	{
		inline constexpr REL::ID SetParentGroupNumber{ 1412266 };
	}

	namespace BGSCraftItemEvent
	{
		inline constexpr REL::ID EventIndex{ 2663409 };
	}

	namespace BGSCreatedObjectManager
	{
		inline constexpr REL::ID Singleton{ 1000678 };
		inline constexpr REL::ID DecrementRef{ 230928 };
		inline constexpr REL::ID IncrementRef{ 1042515 };
	}

	namespace BGSDefaultObject
	{
		inline constexpr REL::ID Singleton{ 2690473 };
		inline constexpr REL::ID ctor{ 2197003 };
	}

	namespace BGSDefaultObjectManager
	{
		inline constexpr REL::ID Singleton{ 484974 };
	}

	namespace BGSDynamicPersistenceManager
	{
		inline constexpr REL::ID Singleton{ 109630 };
		inline constexpr REL::ID PromoteReference{ 1300345 };
		inline constexpr REL::ID DemoteReference{ 222813 };
	}

	namespace BGSEntryPoint
	{
		inline constexpr REL::ID HandleEntryPoint{ 2206243 };
	}

	namespace BGSHackTerminal
	{
		inline constexpr REL::ID EventIndex{ 1186942 };
	}

	namespace BGSInventoryInterface
	{
		inline constexpr REL::ID Singleton{ 2689299 };
		inline constexpr REL::ID RequestInventoryItem{ 2194009 };
		inline constexpr REL::ID ForceMergeStacks{ 2194032 };
	}

	namespace BGSInventoryItem
	{
		inline constexpr REL::ID FindAndWriteStackData{ 2194123 };
		inline constexpr REL::ID GetDisplayFullName1{ 2194079 };
		inline constexpr REL::ID GetDisplayFullName2{ 2194080 };
		inline constexpr REL::ID GetInstanceData{ 2194072 };
		inline constexpr REL::ID GetInventoryValue{ 2194099 };
		inline constexpr REL::ID GetExtraDataAt{ 2194092 };
		inline constexpr REL::ID MergeStacks{ 2194109 };
	}

	namespace BGSInventoryList
	{
		inline constexpr REL::ID FindAndWriteStackDataForItem{ 2194179 };
		inline constexpr REL::ID BuildFromContainer{ 2194158 };
		inline constexpr REL::ID ctor{ 2194153 };
	}

	namespace BGSKeyword
	{
		inline constexpr REL::ID TypedKeywords{ 2692038 };
	}

	namespace BGSKeywordForm
	{
		inline constexpr REL::ID AddKeyword{ 2192766 };
		inline constexpr REL::ID RemoveKeyword{ 921694 };
	}

	namespace BGSListForm
	{
		inline constexpr REL::ID AddScriptAddedForm{ 1064874 };
		inline constexpr REL::ID ContainsItem{ 688500 };
	}

	namespace BGSLocalizedStringDL
	{
		inline constexpr REL::ID GetDescription{ 523613 };
		inline constexpr REL::ID GetText{ 472297 };
	}

	namespace BGSMessage
	{
		inline constexpr REL::ID AddButton{ 236744 };
		inline constexpr REL::ID GetConvertedDescription{ 8331 };
	}

	namespace BGSMod
	{
		namespace Attachment
		{
			namespace Mod
			{
				inline constexpr REL::ID FindModsForLooseMod{ 410363 };
				inline constexpr REL::ID GetData{ 33658 };
				inline constexpr REL::ID GetLooseMod{ 2197514 };
				inline constexpr REL::ID SetLooseMod{ 123132 };
			}

			inline constexpr REL::ID GetAllLooseMods{ 1108112 };
		}

		namespace Template
		{
			namespace Items
			{
				inline constexpr REL::ID CreateInstanceDataForObjectAndExtra{ 147297 };
			}
		}
	}

	namespace BGSObjectInstance
	{
		inline constexpr REL::ID ctor{ 2197563 };
	}

	namespace BGSObjectInstanceExtra
	{
		inline constexpr REL::ID AttachModToReference{ 2189033 };
		inline constexpr REL::ID HasMod{ 2189026 };
		inline constexpr REL::ID AddMod{ 2189025 };
		inline constexpr REL::ID RemoveInvalidMods{ 2189028 };
		inline constexpr REL::ID RemoveMod{ 2189027 };
		inline constexpr REL::ID GetNumMods{ 2189019 };
		inline constexpr REL::ID ctor{ 1222521 };
	}

	namespace BGSOpenCloseForm
	{
		inline constexpr REL::ID AutoCloseRef{ 2192797 };
		inline constexpr REL::ID GetOpenState{ 2192799 };
		inline constexpr REL::ID HasOnlyOpenCloseAnims{ 2192796 };
		inline constexpr REL::ID IsAnimating{ 2192801 };
		inline constexpr REL::ID IsOpenCloseEvent{ 2192795 };
		inline constexpr REL::ID IsOpenCloseForm{ 2192790 };
		inline constexpr REL::ID SetOpenState{ 2192798 };
	}

	namespace BGSPerkRankArray
	{
		inline constexpr REL::ID AllocatePerkRankArray{ 888419 };
		inline constexpr REL::ID ClearPerks{ 1247917 };
	}

	namespace BGSPickLockEvent
	{
		inline constexpr REL::ID EventIndex{ 701969 };
		inline constexpr REL::ID ctor{ 193329 };
	}

	namespace BGSProjectile
	{
		inline constexpr REL::ID CollidesWithSmallTransparentLayer{ 2197620 };
	}

	namespace BGSQuestInstanceText
	{
		inline constexpr REL::ID ParseString{ 2206630 };
	}

	namespace BGSSaveLoadManager
	{
		inline constexpr REL::ID Singleton{ 2697802 };
		inline constexpr REL::ID QueueSaveLoadTask{ 2228080 };
	}

	namespace BGSScene
	{
		inline constexpr REL::ID ResetAllSceneActions{ 2206864 };
		inline constexpr REL::ID SetSceneActive{ 2206845 };
	}

	namespace BGSSceneActionNPCResponseDialogue
	{
		inline constexpr REL::ID GetCurrentTopicInfo{ 2196825 };
	}

	namespace BGSSceneActionPlayerDialogue
	{
		inline constexpr REL::ID GetCurrentTopicInfo{ 2196825 };
	}

	namespace BGSStoryEventManager
	{
		inline constexpr REL::ID Singleton{ 2693504 };
		inline constexpr REL::ID AddEvent{ 2214088 };
	}

	namespace BGSSynchronizedAnimationManager
	{
		inline constexpr REL::ID Singleton{ 2690996 };
		inline constexpr REL::ID IsReferenceInSynchronizedScene{ 2214437 };
	}

	namespace BGSTerminal
	{
		inline constexpr REL::ID GetHackDifficultyLockLevel{ 2197777 };
		inline constexpr REL::ID IsTerminalRefInUse{ 2197779 };
		inline constexpr REL::ID Show{ 2197776 };
	}

	namespace bhkNPCollisionObject
	{
		inline constexpr REL::ID CopyMembers{ 2277907 };
		inline constexpr REL::ID GetBody{ 2277926 };
		inline constexpr REL::ID GetBodyId{ 2277928 };
		inline constexpr REL::ID GetShape{ 315427 };
		inline constexpr REL::ID GetTransform{ 1508189 };
		inline constexpr REL::ID SetMotionType{ 2277913 };
		inline constexpr REL::ID SetTransform{ 178085 };
		inline constexpr REL::ID Getbhk{ 2277919 };
	}

	namespace bhkPhysicsSystem
	{
		inline constexpr REL::ID AddToWorld{ 2278019 };
		inline constexpr REL::ID CopyMembers{ 2278007 };
	}

	namespace bhkPickData
	{
		inline constexpr REL::ID ctor{ 526783 };
		inline constexpr REL::ID SetStartEnd{ 747470 };
		inline constexpr REL::ID Reset{ 438299 };
		inline constexpr REL::ID HasHit{ 1181584 };
		inline constexpr REL::ID GetHitFraction{ 476687 };
		inline constexpr REL::ID GetAllCollectorRayHitSize{ 1288513 };
		inline constexpr REL::ID GetAllCollectorRayHitAt{ 583997 };
		inline constexpr REL::ID SortAllCollectorHits{ 1274842 };
		inline constexpr REL::ID GetNiAVObject{ 863406 };
		inline constexpr REL::ID GetBody{ 1223055 };
	}

	namespace bhkUtilFunctions
	{
		inline constexpr REL::ID FindFirstCollisionObject{ 2278093 };
	}

	namespace bhkWorld
	{
		inline constexpr REL::ID AddPhysicsSystem{ 2277752 };
		inline constexpr REL::ID RemovePhysicsSystem{ 2277753 };
		inline constexpr REL::ID RemoveObjects{ 2277721 };
	}

	namespace BIPOBJECT
	{
		inline constexpr REL::ID dtor{ 765242 };
	}

	namespace BSAudioManager
	{
		inline constexpr REL::ID Singleton{ 1321158 };
		inline constexpr REL::ID GetSoundHandleByName{ 196484 };
	}

	namespace BSAwardsSystemUtility
	{
		inline constexpr REL::ID Singleton{ 1569384 };
	}

	namespace BSGFxDisplayObject
	{
		inline constexpr REL::ID RemoveChild{ 2287327 };
	}

	namespace BSGFxObject
	{
		inline constexpr REL::ID AcquireFlashObjectByMemberName{ 2287014 };
		inline constexpr REL::ID AcquireFlashObjectByPath{ 2287015 };
	}

	namespace BSGFxShaderFXTarget
	{
		inline constexpr REL::ID ProcessEvent{ 848563 };
		inline constexpr REL::ID AppendShaderFXInfos{ 2287021 };
		inline constexpr REL::ID CreateAndSetFiltersToColor1{ 2287028 };
		inline constexpr REL::ID CreateAndSetFiltersToColor2{ 783104 };
		inline constexpr REL::ID CreateAndSetFiltersToHUD{ 2287027 };
		inline constexpr REL::ID EnableShadedBackground{ 2287022 };
	}

	namespace BSGraphics
	{
		namespace Renderer
		{
			inline constexpr REL::ID IncRef{ 1337764 };
			inline constexpr REL::ID DecRef{ 194808 };
			inline constexpr REL::ID Begin{ 2276833 };
			inline constexpr REL::ID End{ 2276834 };
			inline constexpr REL::ID Lock{ 2276828 };
			inline constexpr REL::ID Unlock{ 2276829 };
		}

		namespace RenderTargetManager
		{
			inline constexpr REL::ID Singleton{ 2666735 };
			inline constexpr REL::ID SetEnableDynamicResolution{ 116947 };
		}

		namespace State
		{
			inline constexpr REL::ID Singleton{ 2704621 };
		}

		namespace Utility
		{
			inline constexpr REL::ID ConvertHALFToNiPoint3Stream{ 2277113 };
			inline constexpr REL::ID ConvertNiPoint3ToHALFStream{ 2277114 };
			inline constexpr REL::ID PackVertexData{ 2277106 };
			inline constexpr REL::ID UnpackVertexData{ 2277129 };
		}

		inline constexpr REL::ID GetRendererData{ 2704429 };
		inline constexpr REL::ID GetCurrentRendererWindow{ 2704431 };
	}

	namespace BSInputDeviceManager
	{
		inline constexpr REL::ID Singleton{ 1284221 };
	}

	namespace BSInputEnableLayer
	{
		inline constexpr REL::ID DecRef{ 2268272 };
	}

	namespace BSInputEnableManager
	{
		inline constexpr REL::ID Singleton{ 2689007 };
		inline constexpr REL::ID AllocateNewLayer{ 2268244 };
		inline constexpr REL::ID EnableUserEvent{ 2268263 };
		inline constexpr REL::ID EnableOtherEvent{ 2268265 };
	}

	namespace BSModelDB
	{
		inline constexpr REL::ID Demand1{ 1066398 };
		inline constexpr REL::ID Demand2{ 1225688 };
	}

	namespace BSPointerHandle
	{
		namespace BSPointerHandleManagerInterface
		{
			inline constexpr REL::ID CreateHandle{ 2188375 };
			inline constexpr REL::ID GetHandle{ 2188676 };
			inline constexpr REL::ID GetSmartPointer{ 2188681 };
		}
	}

	namespace BSRandom
	{
		inline constexpr REL::ID UnsignedInt{ 2267950 };
		inline constexpr REL::ID Float{ 2267953 };
		inline constexpr REL::ID Float0To1{ 2267954 };
	}

	namespace BSResource_Archive2_AsyncReaderStream
	{
		inline constexpr REL::ID DoOpen{ 1401160 };
		inline constexpr REL::ID DoClose{ 883012 };
		inline constexpr REL::ID DoClone{ 803750 };
		inline constexpr REL::ID DoStartRead{ 1215072 };
		inline constexpr REL::ID DoStartPacketAlignedBufferedRead{ 603387 };
		inline constexpr REL::ID DoWait{ 2269399 };
	}

	namespace BSResource_Archive2_ReaderStream
	{
		inline constexpr REL::ID DoOpen{ 762048 };
		inline constexpr REL::ID DoClose{ 109149 };
		inline constexpr REL::ID DoGetKey{ 772817 };
		inline constexpr REL::ID DoClone{ 855081 };
		inline constexpr REL::ID DoRead{ 1359347 };
		inline constexpr REL::ID DoSeek{ 1000164 };
		inline constexpr REL::ID DoPrefetchAll{ 1518821 };
		inline constexpr REL::ID DoCreateAsync{ 893405 };
	}

	namespace BSResource_EntryDBBaseUtil
	{
		inline constexpr REL::ID ReleaseEntryAction{ 2269463 };
	}

	namespace BSResource_GlobalLocations
	{
		inline constexpr REL::ID Singleton{ 2703394 };
	}

	namespace BSResource_GlobalPaths
	{
		inline constexpr REL::ID Singleton{ 2703393 };
	}

	namespace BSResource
	{
		inline constexpr REL::ID RegisterLocation{ 918408 };
		inline constexpr REL::ID GetOrCreateStream{ 1143155 };
	}

	namespace BSResourceNiBinaryStream
	{
		inline constexpr REL::ID Seek{ 358512 };
		inline constexpr REL::ID DoRead{ 424286 };
		inline constexpr REL::ID DoWrite{ 1208863 };
		inline constexpr REL::ID GetBufferInfo{ 265501 };
		inline constexpr REL::ID ctor{ 1198116 };
		inline constexpr REL::ID dtor{ 1516202 };
		inline constexpr REL::ID BinaryStreamWithRescan{ 543595 };
	}

	namespace BSScaleformManager
	{
		inline constexpr REL::ID Singleton{ 2689600 };
		inline constexpr REL::ID LoadMovie{ 2287422 };
		inline constexpr REL::ID GetMovieFilename{ 1191277 };
		inline constexpr REL::ID InitMovieViewport{ 2287430 };
		inline constexpr REL::ID FileUncacheOnMenuOpen{ 2667999 };
	}

	namespace BSScaleformRenderer
	{
		inline constexpr REL::ID Initialize{ 2284938 };
	}

	namespace BSScript_Array
	{
		inline constexpr REL::ID ctor{ 870924 };
	}

	namespace BSScript_ArrayWrapper
	{
		inline constexpr REL::ID ReplaceArray{ 445184 };
	}

	namespace BSScript_Internal_NativeFunctionBase
	{
		inline constexpr REL::ID Call{ 2314780 };
	}

	namespace BSScript_Internal_Stack
	{
		inline constexpr REL::ID GetPageForFrame{ 1429302 };
		inline constexpr REL::ID GetStackFrameVariable{ 2314681 };
	}

	namespace BSScript_Object
	{
		inline constexpr REL::ID DecRef{ 541793 };
		inline constexpr REL::ID GetHandle{ 2314431 };
		inline constexpr REL::ID IncRef{ 2314436 };
	}

	namespace BSScript_ObjectTypeInfo
	{
		inline constexpr REL::ID dtor{ 1047917 };
	}

	namespace BSScript_ObjectBindPolicy
	{
		inline constexpr REL::ID BindObject{ 709728 };
		inline constexpr REL::ID UnbindObject{ 522763 };
	}

	namespace BSScriptUtil
	{
		inline constexpr REL::ID BaseObjectName{ 648543 };
	}

	namespace BSShaderProperty
	{
		inline constexpr REL::ID SetMaterial{ 706318 };
	}

	namespace BSShaderTextureSet
	{
		inline constexpr REL::ID CreateObject{ 2316324 };
	}

	namespace BSSoundHandle
	{
		inline constexpr REL::ID FadeInPlay{ 2267075 };
		inline constexpr REL::ID FadeOutAndRelease{ 2267076 };
	}

	namespace BSSpinLock
	{
		namespace BSReadWriteLock
		{
			inline constexpr REL::ID lock_read{ 2267897 };
			inline constexpr REL::ID lock_write{ 2267898 };
			inline constexpr REL::ID try_lock_read{ 2267901 };
			inline constexpr REL::ID try_lock_write{ 2267902 };
		}

		inline constexpr REL::ID lock{ 2192245 };
		inline constexpr REL::ID try_lock{ 2267902 };
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			inline constexpr REL::ID Release{ 2268720 };
		}

		inline constexpr REL::ID GetEntry_char{ 2268729 };
		inline constexpr REL::ID GetEntry_wchar{ 2268730 };
	}

	namespace BSStringT
	{
		inline constexpr REL::ID Set{ 2189084 };
	}

	namespace BSSystemFileStreamer
	{
		inline constexpr REL::ID UncacheAll{ 2268797 };
	}

	namespace BSTempEffectDebris
	{
		inline constexpr REL::ID ctor{ 2212059 };
	}

	namespace BSTEvent
	{
		namespace BSTGlobalEvent
		{
			inline constexpr REL::ID Singleton{ 2688814 };
		}
	}

	namespace BSThreadEvent
	{
		inline constexpr REL::ID InitSDM{ 2268180 };
	}

	namespace BSTimer
	{
		inline constexpr REL::ID Singleton{ 2703179 };
		inline constexpr REL::ID QGlobalTimeMultiplier{ 2666307 };
		inline constexpr REL::ID QGlobalTimeMultiplierTarget{ 2666308 };
		inline constexpr REL::ID SetGlobalTimeMultiplier{ 2267970 };
	}

	namespace BSUIMessageData
	{
		inline constexpr REL::ID SendUIBoolMessage{ 1388308 };
		inline constexpr REL::ID SendUIStringMessage{ 1270833 };
		inline constexpr REL::ID SendUIPtrMessage{ 1374542 };
		inline constexpr REL::ID SendUIStringUIntMessage{ 99795 };
	}

	namespace BSUtilities
	{
		inline constexpr REL::ID ConvertFloatToHalf{ 2212098 };
		inline constexpr REL::ID ConvertHalfToFloat{ 2195843 };
		inline constexpr REL::ID GetObjectByName{ 2274841 };
	}

	namespace Calendar
	{
		inline constexpr REL::ID Singleton{ 2689092 };
	}

	namespace CanDisplayNextHUDMessage
	{
		inline constexpr REL::ID GetEventSource{ 344866 };
	}

	namespace CellAttachDetachEvent
	{
		inline constexpr REL::ID GetEventSource{ 862142 };
	}

	namespace ColorUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 1226590 };
	}

	namespace CombatFormulas
	{
		inline constexpr REL::ID GetWeaponDisplayAccuracy{ 1137654 };
		inline constexpr REL::ID GetWeaponDisplayDamage{ 1431014 };
		inline constexpr REL::ID GetWeaponDisplayRange{ 1324037 };
		inline constexpr REL::ID GetWeaponDisplayRateOfFire{ 1403591 };
	}

	namespace CombatUtilities
	{
		inline constexpr REL::ID CalculateProjectileLOS1{ 798616 };
		inline constexpr REL::ID CalculateProjectileLOS2{ 55339 };
		inline constexpr REL::ID CalculateProjectileTrajectory{ 1575156 };
		inline constexpr REL::ID WorldGravity{ 1378547 };
	}

	namespace ComparisonQualifiers
	{
		inline constexpr REL::ID ContainerQualifier{ 2190674 };
		inline constexpr REL::ID UIQualifier{ 2190675 };
	}

	namespace Console
	{
		inline constexpr REL::ID ExecuteCommand{ 2248537 };
		inline constexpr REL::ID GetCurrentPickIndex{ 2701382 };
		inline constexpr REL::ID GetPickRef{ 2701395 };
		inline constexpr REL::ID GetPickRefs{ 2701391 };
		inline constexpr REL::ID SetCurrentPickREFR{ 2248551 };
	}

	namespace ConsoleLog
	{
		inline constexpr REL::ID Singleton{ 2690148 };
		inline constexpr REL::ID AddString{ 2248593 };
		inline constexpr REL::ID Print{ 2248591 };
	}

	namespace ContainerMenu
	{
		inline constexpr REL::ID TakeAllItems{ 1323703 };
	}

	namespace ContainerMenuBase
	{
		namespace ItemSorter
		{
			inline constexpr REL::ID IncrementSort{ 1307263 };
		}
	}

	namespace ControlMap
	{
		inline constexpr REL::ID Singleton{ 2692014 };
		inline constexpr REL::ID PopInputContext{ 2268336 };
		inline constexpr REL::ID PushInputContext{ 2268335 };
		inline constexpr REL::ID RemapButton{ 0 };
		inline constexpr REL::ID SaveRemappings{ 0 };
		inline constexpr REL::ID SetTextEntryMode{ 2268339 };
	}

	namespace CurrentRadiationSourceCount
	{
		inline constexpr REL::ID GetEventSource{ 2696196 };
	}

	namespace DEFAULT_OBJECT_DATA
	{
		inline constexpr REL::ID GetDefaultObjectData{ 838886 };
	}

	namespace DoBeforeNewOrLoadCompletedEvent
	{
		inline constexpr REL::ID GetEventSource{ 787908 };
	}

	namespace EffectItem
	{
		inline constexpr REL::ID GetDescription{ 2189612 };
	}

	namespace EquippedWeaponData
	{
		inline constexpr REL::ID SetupFireSounds{ 2232275 };
	}

	namespace ExamineMenu
	{
		inline constexpr REL::ID BuildWeaponScrappingArray{ 646841 };
		inline constexpr REL::ID GetSelectedIndex{ 2223022 };
		inline constexpr REL::ID ShowConfirmMenu{ 2223081 };
		inline constexpr REL::ID ConsumeSelectedItems{ 2223052 };
	}

	namespace ExteriorCellSingleton
	{
		inline constexpr REL::ID Singleton{ 2689084 };
	}

	namespace ExtraDataList
	{
		inline constexpr REL::ID CreateInstanceData{ 2190185 };
		inline constexpr REL::ID GetLegendaryMod{ 2190180 };
		inline constexpr REL::ID SetBendableSplineInfo{ 2190623 };
		inline constexpr REL::ID SetDisplayNameFromInstanceData{ 2190179 };
		inline constexpr REL::ID SetOverrideName{ 2190167 };
		inline constexpr REL::ID SetStartingWorldOrCell{ 2191213 };
		inline constexpr REL::ID GetHealthPerc{ 2190226 };
		inline constexpr REL::ID SetHealthPerc{ 2190124 };
		inline constexpr REL::ID ClearFavorite{ 2190191 };
		inline constexpr REL::ID IsFavorite{ 2190189 };
		inline constexpr REL::ID IsDamaged{ 2190224 };
		inline constexpr REL::ID CompareList{ 2190098 };
		inline constexpr REL::ID SetFavorite{ 2190188 };
		inline constexpr REL::ID GetPrimitive{ 2190427 };
	}

	namespace ExtraTextDisplayData
	{
		inline constexpr REL::ID GetDisplayName{ 1523343 };
	}

	namespace FavoritesManager
	{
		inline constexpr REL::ID Singleton{ 2694399 };
		inline constexpr REL::ID IsComponentFavorite{ 2248752 };
		inline constexpr REL::ID UseQuickkeyItem{ 2248744 };
	}

	namespace FlatScreenModel
	{
		inline constexpr REL::ID Singleton{ 847741 };
	}

	namespace GameMenuBase
	{
		inline constexpr REL::ID SetIsTopButtonBar{ 2223204 };
		inline constexpr REL::ID OnMenuDisplayStateChanged{ 2223205 };
		inline constexpr REL::ID CacheShaderFXQuadsForRenderer_Impl{ 2223200 };
		inline constexpr REL::ID TransferCachedShaderFXQuadsForRenderer{ 65166 };
		inline constexpr REL::ID SetViewportRect{ 2223202 };
		inline constexpr REL::ID AppendShaderFXInfos{ 2223203 };
		inline constexpr REL::ID SetUpButtonBar{ 2223197 };
	}

	namespace GamePlayFormulas
	{
		inline constexpr REL::ID CanHackGateCheck{ 269668 };
		inline constexpr REL::ID CanPickLockGateCheck{ 1160841 };
		inline constexpr REL::ID GetExperienceReward{ 853500 };
		inline constexpr REL::ID GetLockXPReward{ 880926 };
		inline constexpr REL::ID CalculateItemHealthDamageBonus{ 2209087 };
	}

	namespace GameScript
	{
		namespace HandlePolicy
		{
			inline constexpr REL::ID DropSaveLoadRemapData{ 2249995 };
			inline constexpr REL::ID GetInventoryObjFromHandle{ 2249989 };
			inline constexpr REL::ID UpdatePersistence{ 2249991 };
		}

		namespace ObjectBindPolicy
		{
			inline constexpr REL::ID EndSaveLoad{ 2250482 };
		}

		namespace GameVM
		{
			inline constexpr REL::ID Singleton{ 2689134 };
			inline constexpr REL::ID QueuePostRenderCall{ 2251314 };
			inline constexpr REL::ID RegisterForAllGameEvents{ 2251353 };
			inline constexpr REL::ID SendEventToObjectAndRelated{ 367992 };
		}

		inline constexpr REL::ID LogFormError{ 2251028 };
		inline constexpr REL::ID BindCObject{ 81787 };
	}

	namespace GameUIModel
	{
		inline constexpr REL::ID Singleton{ 17419 };
		inline constexpr REL::ID UpdateDataModels{ 2220905 };
	}

	namespace GridCellArray
	{
		inline constexpr REL::ID Get{ 2194566 };
	}

	namespace HolotapeMenu
	{
		inline constexpr REL::ID ShowHolotapeInPipboy{ 217953 };
		inline constexpr REL::ID ShowHolotapeInTerminal{ 390509 };
	}

	namespace HUDMenuUtils
	{
		inline constexpr REL::ID GetGameplayHUDColor{ 2248840 };
		inline constexpr REL::ID GetGameplayHUDBackgroundColor{ 2248845 };
		inline constexpr REL::ID WorldPtToScreenPt3{ 2222464 };
	}

	namespace HUDModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 683142 };
	}

	namespace IAnimationGraphManagerHolder
	{
		inline constexpr REL::ID SetGraphVariableBool{ 2214543 };
		inline constexpr REL::ID SetGraphVariableFloat{ 27400 };
		inline constexpr REL::ID SetGraphVariableInt{ 732926 };
		inline constexpr REL::ID RevertAnimationGraphManager{ 2214541 };
	}

	namespace IFormFactory
	{
		inline constexpr REL::ID Factories{ 2689177 };
	}

	namespace ImageSpaceEffectFullScreenBlur
	{
		inline constexpr REL::ID Disable{ 2713225 };
	}

	namespace ImageSpaceEffectGetHit
	{
		inline constexpr REL::ID Disable{ 2713237 };
	}

	namespace ImageSpaceEffectHDR
	{
		inline constexpr REL::ID UsePipboyScreenMask{ 2678029 };
	}

	namespace ImageSpaceEffectPipboyScreen
	{
		inline constexpr REL::ID PowerArmorPipboy{ 1065542 };
	}

	namespace ImageSpaceEffectRadialBlur
	{
		inline constexpr REL::ID Disable{ 2713225 };
	}

	namespace ImageSpaceEffectTemporalAA
	{
		inline constexpr REL::ID MaskS{ 775377 };
	}

	namespace ImageSpaceManager
	{
		inline constexpr REL::ID Singleton{ 2712627 };
	}

	namespace ImageSpaceModifierInstance
	{
		inline constexpr REL::ID Stop{ 2199897 };
	}

	namespace ImageSpaceModifierInstanceDOF
	{
		inline constexpr REL::ID Trigger{ 2199922 };
	}

	namespace ImageSpaceModifierInstanceForm
	{
		inline constexpr REL::ID Trigger1{ 2199906 };
		inline constexpr REL::ID Trigger2{ 2199907 };
		inline constexpr REL::ID Stop1{ 2199909 };
		inline constexpr REL::ID Stop2{ 2199910 };
	}

	namespace IMenu
	{
		inline constexpr REL::ID ShouldHandleEvent{ 2287392 };
		inline constexpr REL::ID PassesRenderConditionText{ 2287379 };
		inline constexpr REL::ID OnSetSafeRect{ 2287375 };
		inline constexpr REL::ID ProcessScaleformEvent{ 2287395 };
		inline constexpr REL::ID RefreshPlatform{ 2287374 };
	}

	namespace Interface3D
	{
		inline constexpr REL::ID Create{ 88488 };
		inline constexpr REL::ID GetByName{ 140387 };
		inline constexpr REL::ID MainScreen_AddPointLight{ 1335675 };
		inline constexpr REL::ID MainScreen_AddSpotLight{ 1056093 };
		inline constexpr REL::ID MainScreen_ClearLights{ 683530 };
		inline constexpr REL::ID MainScreen_SetScreenAttached3D{ 817727 };
		inline constexpr REL::ID MainScreen_SetWorldAttached3D{ 724778 };
		inline constexpr REL::ID Offscreen_AddLight{ 1267198 };
		inline constexpr REL::ID Offscreen_Clear3D{ 1533262 };
		inline constexpr REL::ID Offscreen_ClearLights{ 1039253 };
		inline constexpr REL::ID Offscreen_GetRenderTargetHeight{ 1280897 };
		inline constexpr REL::ID Offscreen_GetRenderTargetWidth{ 403273 };
		inline constexpr REL::ID Offscreen_Set3D{ 43983 };
		inline constexpr REL::ID Offscreen_SetDebugMode{ 1277879 };
		inline constexpr REL::ID Offscreen_SetDirectionalLight{ 987144 };
		inline constexpr REL::ID Enable{ 326895 };
		inline constexpr REL::ID Disable{ 938370 };
		inline constexpr REL::ID DisableAll{ 2222521 };
		inline constexpr REL::ID Release{ 74749 };
		inline constexpr REL::ID SetViewport{ 825410 };
	}

	namespace Inventory3DManager
	{
		inline constexpr REL::ID Begin3D{ 2249084 };
		inline constexpr REL::ID ClearModel{ 63218 };
		inline constexpr REL::ID DisableRendering{ 255893 };
		inline constexpr REL::ID EnableRendering{ 176578 };
		inline constexpr REL::ID End3D{ 1512675 };
		inline constexpr REL::ID SetModelScale{ 1319701 };
		inline constexpr REL::ID SetModelScreenPosition{ 2249096 };
	}

	namespace InventoryItemDisplayData
	{
		inline constexpr REL::ID ctor{ 2222612 };
	}

	namespace InventoryUserUIUtils
	{
		inline constexpr REL::ID AddItemCardInfoEntry{ 2222648 };
	}

	namespace ItemCrafted
	{
		inline constexpr REL::ID NotifyOfItemCrafted{ 2232809 };
		inline constexpr REL::ID RegisterSink{ 2232807 };
		inline constexpr REL::ID UnregisterSink{ 2232808 };
	}

	namespace LevelIncrease
	{
		inline constexpr REL::ID GetEventSource{ 2233736 };
	}

	namespace LoadingMenu
	{
		inline constexpr REL::ID StartTestingLoadMenu{ 2249224 };
	}

	namespace LockpickingMenu
	{
		inline constexpr REL::ID OpenLockpickingMenu{ 129892 };
	}

	namespace LocksPicked
	{
		inline constexpr REL::ID GetEventSource{ 2249292 };
	}

	namespace MagicTarget
	{
		inline constexpr REL::ID IsTakingHealthDamageFromActiveEffect{ 2226397 };
		inline constexpr REL::ID IsTakingRadDamageFromActiveEffect{ 2226398 };
	}

	namespace Main
	{
		inline constexpr REL::ID Singleton{ 2698043 };
		inline constexpr REL::ID WorldRootCamera{ 2228956 };
		inline constexpr REL::ID QGameSystemsShouldUpdate{ 2698031 };
		inline constexpr REL::ID QGameDataLoaded{ 2698032 };
		inline constexpr REL::ID SetCameraFOV{ 2228973 };
	}

	namespace MemoryManager
	{
		namespace AutoScrapBuffer
		{
			inline constexpr REL::ID ctor{ 2267865 };
			inline constexpr REL::ID dtor{ 2267867 };
		}

		inline constexpr REL::ID Singleton{ 2193197 };
		inline constexpr REL::ID Allocate{ 2267872 };
		inline constexpr REL::ID Deallocate{ 2267874 };
		inline constexpr REL::ID GetThreadScrapHeap{ 2267850 };
		inline constexpr REL::ID Reallocate{ 2267873 };
		inline constexpr REL::ID RegisterMemoryManager{ 2228356 };
	}

	namespace MenuControls
	{
		inline constexpr REL::ID Singleton{ 2689089 };
	}

	namespace MenuCursor
	{
		inline constexpr REL::ID Singleton{ 2696546 };
		inline constexpr REL::ID CenterCursor{ 2287473 };
		inline constexpr REL::ID RegisterCursor{ 1318193 };
		inline constexpr REL::ID SetCursorConstraintsRaw{ 907092 };
		inline constexpr REL::ID UnregisterCursor{ 1225249 };
		inline constexpr REL::ID PipboyConstraintTLX{ 60674 };
		inline constexpr REL::ID PipboyConstraintTLY{ 719279 };
		inline constexpr REL::ID PipboyConstraintWidth{ 1376729 };
		inline constexpr REL::ID PipboyConstraintHeight{ 452591 };
		inline constexpr REL::ID PipboyConstraintTLX_PowerArmor{ 1110986 };
		inline constexpr REL::ID PipboyConstraintTLY_PowerArmor{ 187113 };
		inline constexpr REL::ID PipboyConstraintWidth_PowerArmor{ 844985 };
		inline constexpr REL::ID PipboyConstraintHeight_PowerArmor{ 1503497 };
	}

	namespace MenuTopicManager
	{
		inline constexpr REL::ID Singleton{ 2689089 };
	}

	namespace MessageBoxMenu
	{
		inline constexpr REL::ID ShowMessage{ 442479 };
	}

	namespace MessageMenuManager
	{
		inline constexpr REL::ID Singleton{ 2689087 };
		inline constexpr REL::ID Create{ 2249456 };
	}

	namespace NiAlphaProperty
	{
		inline constexpr REL::ID SetDestBlendMode{ 725249 };
		inline constexpr REL::ID SetSrcBlendMode{ 976961 };
		inline constexpr REL::ID SetTestMode{ 976961 };
		inline constexpr REL::ID SetAlphaBlending{ 645586 };
		inline constexpr REL::ID SetAlphaTesting{ 645586 };
	}

	namespace NiCamera
	{
		inline constexpr REL::ID WorldPtToScreenPt3{ 2270344 };
	}

	namespace NiControllerManager
	{
		inline constexpr REL::ID GetNiControllerManager{ 2271798 };
		inline constexpr REL::ID GetSequenceByName{ 846648 };
	}

	namespace NiControllerSequence
	{
		inline constexpr REL::ID Activate{ 2271861 };
	}

	namespace NiMatrix3
	{
		inline constexpr REL::ID ToEulerAnglesXYZ1{ 2269806 };
		inline constexpr REL::ID ToEulerAnglesXZY2{ 2269807 };
		inline constexpr REL::ID ToEulerAnglesYXZ3{ 2269808 };
		inline constexpr REL::ID ToEulerAnglesYZX4{ 2269809 };
		inline constexpr REL::ID ToEulerAnglesZYX5{ 2269810 };
		inline constexpr REL::ID ToEulerAnglesZXY6{ 2269824 };
		inline constexpr REL::ID FromEulerAnglesXYZ1{ 2269813 };
		inline constexpr REL::ID FromEulerAnglesXZY2{ 2269814 };
		inline constexpr REL::ID FromEulerAnglesYXZ3{ 2269815 };
		inline constexpr REL::ID FromEulerAnglesYZX4{ 2269816 };
		inline constexpr REL::ID FromEulerAnglesZYX5{ 2269817 };
		inline constexpr REL::ID FromEulerAnglesZXY6{ 2269825 };
	}

	namespace NiNode
	{
		inline constexpr REL::ID ChildrenVTable{ 390064 };
	}

	namespace NiPoint
	{
		namespace NiPoint3
		{
			inline constexpr REL::ID GetZAngleFromVector{ 1450064 };
		}
	}

	namespace NiRefObject
	{
		inline constexpr REL::ID Objects{ 1161724 };
	}

	namespace NiTexture
	{
		inline constexpr REL::ID SetAllowDegrade{ 948181 };
	}

	namespace nsStatsMenuUtils
	{
		inline constexpr REL::ID GetEffectDisplayInfo{ 294691 };
	}

	namespace PerkPointIncreaseEvent
	{
		inline constexpr REL::ID GetEventSource{ 2697359 };
	}

	namespace PerkUtilities
	{
		inline constexpr REL::ID RemoveGrenadeTrajectory{ 672186 };
	}

	namespace PipboyDataManager
	{
		inline constexpr REL::ID Singleton{ 2689086 };
	}

	namespace PipboyInventoryData
	{
		inline constexpr REL::ID RepopulateItemCardsOnSection{ 2225279 };
		inline constexpr REL::ID PopulateItemCardInfo{ 2225266 };
		inline constexpr REL::ID AddItemCardInfoEntry{ 2225267 };
	}

	namespace PipboyInventoryMenu
	{
		inline constexpr REL::ID UpdateData{ 2224143 };
		inline constexpr REL::ID SetQuickkey{ 2224159 };
	}

	namespace PipboyInventoryUtils
	{
		inline constexpr REL::ID DoSlotsOverlap{ 1035436 };
		inline constexpr REL::ID FillDamageTypeInfo{ 928518 };
		inline constexpr REL::ID FillResistTypeInfo{ 1578434 };
	}

	namespace PipboyLightEvent
	{
		inline constexpr REL::ID GetEventSource{ 2696280 };
	}

	namespace PipboyLogMenu
	{
		inline constexpr REL::ID UpdateData{ 672256 };
	}

	namespace PipboyManager
	{
		inline constexpr REL::ID Singleton{ 2691945 };
		inline constexpr REL::ID AddMenuToPipboy{ 2225453 };
		inline constexpr REL::ID ClosedownPipboy{ 2225480 };
		inline constexpr REL::ID EnablePipboyShader{ 2225484 };
		inline constexpr REL::ID InitPipboy{ 2225479 };
		inline constexpr REL::ID LowerPipboy{ 2225454 };
		inline constexpr REL::ID OnPipboyCloseAnim{ 2225457 };
		inline constexpr REL::ID OnPipboyCloseAnimFailed{ 2225459 };
		inline constexpr REL::ID OnPipboyClosed{ 592088 };
		inline constexpr REL::ID OnPipboyOpenAnim{ 1500318 };
		inline constexpr REL::ID OnPipboyOpenAnimFailed{ 702357 };
		inline constexpr REL::ID OnPipboyOpened{ 1299608 };
		inline constexpr REL::ID PlayItemAnimOnClose{ 377837 };
		inline constexpr REL::ID PlayPipboyCloseAnim{ 273927 };
		inline constexpr REL::ID PlayPipboyGenericOpenAnim{ 809076 };
		inline constexpr REL::ID PlayPipboyLoadHolotapeAnim{ 477096 };
		inline constexpr REL::ID PlayPipboyOpenAnim{ 663900 };
		inline constexpr REL::ID PlayPipboyOpenTerminalAnim{ 743427 };
		inline constexpr REL::ID ProcessLoweringReason{ 302903 };
		inline constexpr REL::ID QPipboyActive{ 470886 };
		inline constexpr REL::ID RaisePipboy{ 726763 };
		inline constexpr REL::ID RefreshPipboyRenderSurface{ 81339 };
		inline constexpr REL::ID StartAnimationGraphListening{ 714713 };
		inline constexpr REL::ID StopAnimationGraphListening{ 621144 };
		inline constexpr REL::ID UpdateCursorConstraint{ 900802 };
	}

	namespace PipboyMapMenu
	{
		inline constexpr REL::ID UpdateData{ 2224074 };
	}

	namespace PipboyMenu
	{
		inline constexpr REL::ID RefreshMapMarkers{ 2224187 };
	}

	namespace PipboyObject
	{
		inline constexpr REL::ID AddMember{ 2225699 };
	}

	namespace PipboyPerksMenu
	{
		inline constexpr REL::ID UpdateData{ 783380 };
	}

	namespace PipboyPlayerInfoMenu
	{
		inline constexpr REL::ID UpdateData{ 426990 };
	}

	namespace PipboyPrimitiveValue
	{
		namespace uint32
		{
			inline constexpr REL::ID ctor{ 2225324 };
		}

		namespace boolean
		{
			inline constexpr REL::ID ctor{ 2225327 };
		}
	}

	namespace PipboyQuestMenu
	{
		inline constexpr REL::ID UpdateData{ 2224231 };
	}

	namespace PipboyRadioMenu
	{
		inline constexpr REL::ID UpdateData{ 713423 };
	}

	namespace PipboySpecialMenu
	{
		inline constexpr REL::ID UpdateData{ 1426810 };
	}

	namespace PipboyStatsMenu
	{
		inline constexpr REL::ID UpdateData{ 332518 };
	}

	namespace PipboySubMenu
	{
		inline constexpr REL::ID ProcessEvent{ 893703 };
	}

	namespace PipboyValue
	{
		inline constexpr REL::ID ctor{ 2225915 };
	}

	namespace PipboyWorkshopMenu
	{
		inline constexpr REL::ID UpdateData{ 2224273 };
	}

	namespace PlayerCamera
	{
		inline constexpr REL::ID Singleton{ 2688801 };
		inline constexpr REL::ID PopState{ 2248424 };
		inline constexpr REL::ID PushState{ 2248422 };
		inline constexpr REL::ID ToggleFreeCameraMode{ 2248368 };
		inline constexpr REL::ID SetState{ 2214742 };
		inline constexpr REL::ID StartFurnitureMode{ 2248373 };
		inline constexpr REL::ID StartPipboyMode{ 2248358 };
		inline constexpr REL::ID StopPipboyMode{ 2248359 };
		inline constexpr REL::ID QCameraEquals{ 2248421 };
	}

	namespace PlayerCharacter
	{
		namespace ScopedInventoryChangeMessageContext
		{
			inline constexpr REL::ID ctor{ 2233292 };
			inline constexpr REL::ID dtor{ 2233293 };
		}

		inline constexpr REL::ID Singleton{ 2690919 };
		inline constexpr REL::ID GetPlayerHandle{ 2698072 };
		inline constexpr REL::ID GetDifficultyLevel{ 2233056 };
		inline constexpr REL::ID IsGodMode{ 2232986 };
		inline constexpr REL::ID IsHolotapePlaying{ 2233206 };
		inline constexpr REL::ID IsImmortal{ 2232988 };
		inline constexpr REL::ID IsPipboyLightOn{ 2233202 };
		inline constexpr REL::ID PauseHolotape{ 2233208 };
		inline constexpr REL::ID PlayHolotape{ 2233207 };
		inline constexpr REL::ID QueueFastTravel{ 2232918 };
		inline constexpr REL::ID RemoveLastUsedPowerArmor{ 2233024 };
		inline constexpr REL::ID SelectPerk{ 2232926 };
		inline constexpr REL::ID SetEscaping{ 2233142 };
		inline constexpr REL::ID SetVATSCriticalCount{ 2233219 };
		inline constexpr REL::ID ShowPipboyLight{ 2233203 };
		inline constexpr REL::ID SetLastDialogueInput{ 2233190 };
		inline constexpr REL::ID ClearPrison{ 2233196 };
		inline constexpr REL::ID ReloadWeapon{ 2232907 };
		inline constexpr REL::ID SetPerkCount{ 2233187 };
	}

	namespace PlayerControls
	{
		inline constexpr REL::ID Singleton{ 2692013 };
		inline constexpr REL::ID CanPerformAction{ 565925 };
		inline constexpr REL::ID DoAction{ 818081 };
		inline constexpr REL::ID DoRegisterHandler{ 2234822 };
	}

	namespace PowerArmor
	{
		inline constexpr REL::ID ActorInPowerArmor{ 2219437 };
		inline constexpr REL::ID GetArmorKeyword{ 961172 };
		inline constexpr REL::ID GetBatteryKeyword{ 1493537 };
		inline constexpr REL::ID GetDefaultBatteryObject{ 1279247 };
		inline constexpr REL::ID IsPowerArmorBattery{ 1012910 };
		inline constexpr REL::ID SyncFurnitureVisualsToInventory{ 1078979 };
		inline constexpr REL::ID fNewBatteryCapacity{ 1134204 };
	}

	namespace PowerArmorGeometry
	{
		inline constexpr REL::ID Singleton{ 1365745 };
		inline constexpr REL::ID HidePipboyPAGeometry{ 976332 };
		inline constexpr REL::ID ShowPipboyPAGeometry{ 19066 };
	}

	namespace PowerArmorLightData
	{
		inline constexpr REL::ID GetEventSource{ 2701547 };
	}

	namespace ProcessLists
	{
		inline constexpr REL::ID Singleton{ 2688869 };
		inline constexpr REL::ID AreHostileActorsNear{ 2234105 };
		inline constexpr REL::ID IsActorTargetingREFinPackage{ 2234033 };
		inline constexpr REL::ID RequestHighestDetectionLevelAgainstActor{ 2234111 };
	}

	namespace REFR_LOCK
	{
		inline constexpr REL::ID GetLockLevel{ 2191018 };
		inline constexpr REL::ID SetLocked{ 2191020 };
		inline constexpr REL::ID IsBroken{ 2191021 };
	}

	namespace ScrapHeap
	{
		inline constexpr REL::ID Allocate{ 2267983 };
		inline constexpr REL::ID Deallocate{ 2267984 };
	}

	namespace SCRIPT_FUNCTION
	{
		inline constexpr REL::ID ConsoleFunctions{ 901511 };
		inline constexpr REL::ID ScriptFunctions{ 75173 };
		inline constexpr REL::ID CompileFunction{ 2204343 };
	}

	namespace Script
	{
		inline constexpr REL::ID ParseParameters{ 2204298 };
		inline constexpr REL::ID CompileAndRun{ 2204287 };
		inline constexpr REL::ID GetProcessScripts{ 2204310 };
		inline constexpr REL::ID SetProcessScripts{ 2204309 };
	}

	namespace SendHUDMessage
	{
		inline constexpr REL::ID PopHUDMode{ 2222444 };
		inline constexpr REL::ID PushHUDMode{ 2222443 };
		inline constexpr REL::ID SetPowerArmorMode{ 361745 };
		inline constexpr REL::ID ShowHUDMessage{ 2222440 };
	}

	namespace Setting
	{
		namespace INISettingCollection
		{
			inline constexpr REL::ID Singleton{ 2704108 };
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::ID Singleton{ 2703234 };
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::ID InitCollection{ 2188690 };
			inline constexpr REL::ID Singleton{ 2690301 };
		}
	}

	namespace SitWaitMenu
	{
		inline constexpr REL::ID OnEnterFurniture{ 2249503 };
		inline constexpr REL::ID OnExitFurniture{ 2249504 };
	}

	namespace Sky
	{
		inline constexpr REL::ID Singleton{ 2192448 };
		inline constexpr REL::ID ForceWeather{ 2208861 };
		inline constexpr REL::ID ResetWeather{ 2208860 };
	}

	namespace SplineUtils
	{
		inline constexpr REL::ID DisconnectSpline{ 750682 };
		inline constexpr REL::ID ConnectSpline{ 59311 };
	}

	namespace SWFToCodeFunctionHandler
	{
		inline constexpr REL::ID MapCodeMethodToASFunction{ 2287419 };
		inline constexpr REL::ID RegisterCodeObject{ 2287415 };
	}

	namespace TaskQueueInterface
	{
		inline constexpr REL::ID Singleton{ 7491 };
		inline constexpr REL::ID QueueClosePipboy{ 69886 };
		inline constexpr REL::ID QueueRebuildBendableSpline{ 198419 };
		inline constexpr REL::ID QueueShow1stPerson{ 994377 };
		inline constexpr REL::ID QueueShowPipboy{ 1133684 };
		inline constexpr REL::ID QueueUpdate3D{ 581890 };
		inline constexpr REL::ID QueueWeaponFire{ 15449 };
	}

	namespace TerminalHacked
	{
		inline constexpr REL::ID GetEventSource{ 2233751 };
	}

	namespace TES
	{
		inline constexpr REL::ID Singleton{ 2698044 };
	}

	namespace TESActivateEvent
	{
		inline constexpr REL::ID GetEventSource{ 166230 };
	}

	namespace TESActorBaseData
	{
		inline constexpr REL::ID GetLevel{ 2192891 };
	}

	namespace TESAmmo
	{
		inline constexpr REL::ID GetReloadsWithAmmoRef{ 2197864 };
	}

	namespace TESBoundObject
	{
		inline constexpr REL::ID ApplyMods{ 2198325 };
	}

	namespace TESCellAttachDetachEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201823 };
	}

	namespace TESCellFullyLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201824 };
	}

	namespace TESCondition
	{
		inline constexpr REL::ID IsTrue{ 2211989 };
		inline constexpr REL::ID IsTrueForAllButFunction{ 1182457 };
		inline constexpr REL::ID ClearAllConditionItems{ 2211988 };
	}

	namespace TESConditionItem
	{
		inline constexpr REL::ID GetComparisonValue{ 2212007 };
		inline constexpr REL::ID IsTrue1{ 2212008 };
		inline constexpr REL::ID IsTrue2{ 2212009 };
	}

	namespace TESContainerChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 242538 };
	}

	namespace TESDataHandler
	{
		inline constexpr REL::ID Singleton{ 2688883 };
		inline constexpr REL::ID AddFormToDataHandler{ 2192271 };
		inline constexpr REL::ID CheckModsLoaded{ 2192323 };
		inline constexpr REL::ID CreateReferenceAtLocation{ 2192301 };
		inline constexpr REL::ID IsFormIDInuse{ 2192351 };
	}

	namespace TESDeathEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201833 };
	}

	namespace TESDescription
	{
		inline constexpr REL::ID GetDescription{ 2193019 };
	}

	namespace TESEnterSneakingEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201837 };
	}

	namespace TESFile
	{
		inline constexpr REL::ID CloseTES{ 2192491 };
		inline constexpr REL::ID GetChunkData{ 2192538 };
		inline constexpr REL::ID GetTESChunk{ 2192536 };
		inline constexpr REL::ID NextChunk{ 2192537 };
		inline constexpr REL::ID NextForm{ 2192527 };
		inline constexpr REL::ID NextGroup{ 2192522 };
		inline constexpr REL::ID OpenTES{ 2192490 };
	}

	namespace TESForm
	{
		inline constexpr REL::ID FormSortFunc{ 705530 };
		inline constexpr REL::ID AddCompileIndex{ 2193152 };
		inline constexpr REL::ID AllForms{ 2689178 };
		inline constexpr REL::ID AllFormsMapLock{ 2689189 };
		inline constexpr REL::ID AllFormsByEditorID{ 2689179 };
		inline constexpr REL::ID AllFormsEditorIDMapLock{ 2689190 };
		inline constexpr REL::ID GetFile{ 2193103 };
		inline constexpr REL::ID GetFormEnumString{ 1309967 };
		inline constexpr REL::ID GetFormTypeFromString{ 2193108 };
		inline constexpr REL::ID SetTemporary{ 2193125 };
	}

	namespace TESFormDeleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201842 };
	}

	namespace TESFullName
	{
		inline constexpr REL::ID SparseFullNameMap{ 2661402 };
	}

	namespace TESFurniture
	{
		inline constexpr REL::ID GetContainer{ 2198043 };
	}

	namespace TESFurnitureEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201844 };
	}

	namespace TESHarvestEvent
	{
		inline constexpr REL::ID GetEventSource{ 2193351 };
	}

	namespace TESHealthForm
	{
		inline constexpr REL::ID GetFormHealth{ 2193227 };
	}

	namespace TESHitEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201886 };
	}

	namespace TESInitScriptEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201846 };
	}

	namespace TESLeveledList
	{
		inline constexpr REL::ID AddLeveledObject{ 2193258 };
		inline constexpr REL::ID CalculateCurrentFormList{ 2193259 };
		inline constexpr REL::ID CalculateCurrentFormListForRef{ 2193260 };
		inline constexpr REL::ID GetUseAll{ 2193253 };
	}

	namespace TESLoadGameEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201848 };
	}

	namespace TESMagicEffectApplyEvent
	{
		inline constexpr REL::ID GetEventSource{ 1327824 };
	}

	namespace TESNPC
	{
		inline constexpr REL::ID AlternateHeadPartListMap{ 2662368 };
		inline constexpr REL::ID GetSex{ 2207107 };
		inline constexpr REL::ID GetFacialBoneMorphIntensity{ 2207416 };
		inline constexpr REL::ID SetHairColor{ 2207426 };
	}

	namespace TESObjectCELL
	{
		inline constexpr REL::ID GetbhkWorld{ 2200260 };
		inline constexpr REL::ID GetCantWaitHere{ 2200287 };
		inline constexpr REL::ID GetDataX{ 2200213 };
		inline constexpr REL::ID GetDataY{ 2200214 };
		inline constexpr REL::ID GetEncounterZone{ 2200242 };
		inline constexpr REL::ID GetLocation{ 2200179 };
		inline constexpr REL::ID GetOwner{ 2200236 };
		inline constexpr REL::ID GetRegionList{ 2200265 };
		inline constexpr REL::ID Pick{ 2200263 };
		inline constexpr REL::ID SetCullCellMarkers{ 2192259 };
		inline constexpr REL::ID UpdateAllRefsLoaded{ 2200415 };
		inline constexpr REL::ID AttatchReference3D{ 2200620 };
		inline constexpr REL::ID RemoveReference{ 2200299 };
		inline constexpr REL::ID UpdateAllDecals{ 2200643 };
		inline constexpr REL::ID DefaultWater{ 2691845 };
	}

	namespace TESObjectLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201853 };
	}

	namespace TESObjectREFR
	{
		inline constexpr REL::ID ActivateRef{ 2201147 };
		inline constexpr REL::ID AddInventoryItem{ 2200949 };
		inline constexpr REL::ID AddKeyword{ 2200860 };
		inline constexpr REL::ID AddLockChange{ 1578706 };
		inline constexpr REL::ID ApplyArtObject{ 2205200 };
		inline constexpr REL::ID ApplyEffectShader{ 2205201 };
		inline constexpr REL::ID Enable{ 1396707 };
		inline constexpr REL::ID GetCurrentLocation{ 2201163 };
		inline constexpr REL::ID GetDisplayFullName{ 2201126 };
		inline constexpr REL::ID GetEditorDead{ 2200781 };
		inline constexpr REL::ID GetOwner{ 1323437 };
		inline constexpr REL::ID GetGoldAmount{ 2200923 };
		inline constexpr REL::ID GetHandle{ 2201196 };
		inline constexpr REL::ID GetHasOwner{ 1016277 };
		inline constexpr REL::ID GetInventoryObjectCount{ 2200939 };
		inline constexpr REL::ID GetLinkedRef{ 897287 };
		inline constexpr REL::ID GetLock{ 930785 };
		inline constexpr REL::ID GetWeightInContainer{ 2201001 };
		inline constexpr REL::ID HasContainer{ 2201022 };
		inline constexpr REL::ID IsAnOwner{ 933798 };
		inline constexpr REL::ID IsCrimeToActivate{ 2201180 };
		inline constexpr REL::ID IsInWater{ 315318 };
		inline constexpr REL::ID IsLeveledCreature{ 2202655 };
		inline constexpr REL::ID MarkAsDeleted{ 192661 };
		inline constexpr REL::ID MoveRefToNewSpace{ 629658 };
		inline constexpr REL::ID RemoveKeyword{ 2200861 };
		inline constexpr REL::ID SetAngleOnReference{ 1049748 };
		inline constexpr REL::ID SetLinkedRef{ 192840 };
		inline constexpr REL::ID SetLocationOnReference{ 1101832 };
		inline constexpr REL::ID SetWantsDelete{ 761346 };
		inline constexpr REL::ID RebuildBendableSpline{ 340319 };
		inline constexpr REL::ID GetItemCount{ 2200996 };
		inline constexpr REL::ID UpdateReference3D{ 1568075 };
		inline constexpr REL::ID GetObjectCenter{ 777738 };
		inline constexpr REL::ID SetScale{ 2200893 };
		inline constexpr REL::ID IsMarker{ 2201157 };
		inline constexpr REL::ID IsDecalRef{ 2200794 };
	}

	namespace TESObjectWEAP
	{
		inline constexpr REL::ID GetMeleeAttackSpeed{ 2198957 };
		inline constexpr REL::ID GetMeleeAttackSpeedLabel{ 2198959 };
	}

	namespace TESQuest
	{
		inline constexpr REL::ID SetStage{ 2207743 };
		inline constexpr REL::ID GetAliasedRef{ 2207810 };
	}

	namespace TESResponse
	{
		inline constexpr REL::ID GetResponseText{ 2208288 };
		inline constexpr REL::ID GetSpeakerIdle{ 2208293 };
	}

	namespace TESSpellList
	{
		inline constexpr REL::ID AddSpell{ 1312083 };
	}

	namespace TESSwitchRaceCompleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 2201874 };
	}

	namespace TESTopicInfo
	{
		inline constexpr REL::ID GetParentInfoGroup{ 2208435 };
		inline constexpr REL::ID GetChallengeLevel{ 2208441 };
		inline constexpr REL::ID GetSuccessLevel{ 2208444 };
	}

	namespace TESValueForm
	{
		inline constexpr REL::ID GetFormValue{ 2193435 };
	}

	namespace TESWeightForm
	{
		inline constexpr REL::ID GetFormWeight{ 2193446 };
	}

	namespace TESWorldSpace
	{
		inline constexpr REL::ID DefaultWater{ 2691845 };
	}

	namespace UI
	{
		inline constexpr REL::ID CustomRendererHasQuads{ 1401451 };
		inline constexpr REL::ID GetMenuMapRWLock{ 2707105 };
		inline constexpr REL::ID Singleton{ 2689028 };
		inline constexpr REL::ID RefreshCursor{ 1436639 };
		inline constexpr REL::ID RegisterMenu{ 2284766 };
		inline constexpr REL::ID UpdateControllerType{ 175796 };
	}

	namespace UIAdvanceMenusFunctionCompleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 1067039 };
	}

	namespace UIMessageQueue
	{
		inline constexpr REL::ID Singleton{ 2689091 };
		inline constexpr REL::ID AddMessage{ 2284929 };
	}

	namespace UIUtils
	{
		inline constexpr REL::ID GetComparisonItems{ 593818 };
		inline constexpr REL::ID PlayPipboySound{ 2249706 };
		inline constexpr REL::ID PlayMenuSound{ 2249707 };
		inline constexpr REL::ID UpdateGamepadDependentButtonCodes{ 190238 };
	}

	namespace VATS
	{
		inline constexpr REL::ID Singleton{ 2690444 };
	}

	namespace WorkbenchMenuBase
	{
		inline constexpr REL::ID UpdateOptimizedAutoBuildInv{ 2224955 };
	}

	namespace Workshop
	{
		namespace PlacementItemData
		{
			inline constexpr REL::ID Set{ 1460935 };
		}

		namespace WorkshopMenuNode
		{
			inline constexpr REL::ID FindAndSetSelectedNode{ 1309368 };
		}

		inline constexpr REL::ID FindNearestValidWorkshop{ 2194970 };
		inline constexpr REL::ID FreeBuild{ 2194924 };
		inline constexpr REL::ID GetSelectedWorkshopMenuNode{ 2195024 };
		inline constexpr REL::ID InitializePlacementReference{ 1577199 };
		inline constexpr REL::ID IsLocationWithinBuildableArea{ 990965 };
		inline constexpr REL::ID PlaceCurrentReference{ 1058211 };
		inline constexpr REL::ID RegisterForItemDestroyed{ 1367004 };
		inline constexpr REL::ID RegisterForItemMoved{ 835323 };
		inline constexpr REL::ID RegisterForItemPlaced{ 849008 };
		inline constexpr REL::ID RegisterForWorkshopModeEvent{ 275798 };
		inline constexpr REL::ID RequestExitWorkshop{ 209891 };
		inline constexpr REL::ID ScrapReference{ 636327 };
		inline constexpr REL::ID SetSelectedEditItem{ 2562 };
		inline constexpr REL::ID StartWorkshop{ 2195134 };
		inline constexpr REL::ID ToggleEditMode{ 1243386 };
		inline constexpr REL::ID UnregisterForItemDestroyed{ 1101379 };
		inline constexpr REL::ID UnregisterForItemMoved{ 569432 };
		inline constexpr REL::ID UnregisterForItemPlaced{ 583255 };
		inline constexpr REL::ID UnregisterForWorkshopModeEvent{ 9236 };
		inline constexpr REL::ID UpdateActiveEdit{ 69261 };
		inline constexpr REL::ID WorkshopCanShowRecipe{ 239190 };
		inline constexpr REL::ID CurrentPlacementItemData{ 1279207 };
		inline constexpr REL::ID CurrentRow{ 833923 };
		inline constexpr REL::ID PlacementItem{ 526727 };
	}

	namespace WorkshopMenu
	{
		inline constexpr REL::ID CheckAndSetItemForPlacement{ 1541862 };
		inline constexpr REL::ID UpdateButtonText{ 1089189 };
	}

	inline constexpr REL::ID NiFree{ 242362 };
	inline constexpr REL::ID NiMalloc{ 974443 };
	inline constexpr REL::ID RTDynamicCast{ 2725673 };
}

namespace Scaleform::ID
{
	namespace GFx::ASStringManager
	{
		inline constexpr REL::ID CreateStringNode{ 2290014 };
	}

	namespace GFx::Loader
	{
		inline constexpr REL::ID CreateMovie{ 2284723 };
	}

	namespace GFx::Movie
	{
		inline constexpr REL::ID Release{ 2287230 };
	}

	namespace GFx::Value
	{
		inline constexpr REL::ID ObjectAddRef{ 2286228 };
		inline constexpr REL::ID ObjectRelease{ 2286229 };
		inline constexpr REL::ID HasMember{ 2286078 };
		inline constexpr REL::ID GetArraySize{ 2285791 };
		inline constexpr REL::ID GetMember{ 2285936 };
		inline constexpr REL::ID GetElement{ 2285881 };
		inline constexpr REL::ID SetElement{ 2286575 };
		inline constexpr REL::ID SetMember{ 2286589 };
		inline constexpr REL::ID Invoke{ 2286101 };
		inline constexpr REL::ID PushBack{ 2286424 };
		inline constexpr REL::ID RemoveElements{ 2286475 };
		inline constexpr REL::ID VisitMembers{ 2286786 };
		inline constexpr REL::ID GetDisplayInfo{ 2285873 };
	}

	namespace Memory
	{
		inline constexpr REL::ID SetGlobalHeap{ 2707353 };
		inline constexpr REL::ID GetGlobalHeap{ 2707353 };
	}

	namespace SysAlloc
	{
		inline constexpr REL::ID InitHeapEngine{ 2284532 };
		inline constexpr REL::ID ShutdownHeapEngine{ 2284536 };
	}
}
