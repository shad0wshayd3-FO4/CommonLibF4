#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSAnimationGraphChannel;
	class BSAnimationGraphManager;
	class BShkbAnimationGraph;
	class NiAVObject;

	class __declspec(novtable) IAnimationGraphManagerHolder
	{
	public:
		static constexpr auto RTTI{ RTTI::IAnimationGraphManagerHolder };
		static constexpr auto VTABLE{ VTABLE::IAnimationGraphManagerHolder };

		virtual ~IAnimationGraphManagerHolder() = default;  // 00

		// add
		virtual bool          NotifyAnimationGraphImpl(const BSFixedString& a_eventName);                                                                                                                                                     // 01
		virtual void          EventSuccessfullyProcessed() { return; }                                                                                                                                                                        // 02
		virtual void          ModifyInitialAnimationStateImpl(const bool) { return; }                                                                                                                                                         // 03
		virtual bool          GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& a_animGraphMgr) const = 0;                                                                                                               // 04
		virtual bool          SetAnimationGraphManagerImpl(const BSTSmartPointer<BSAnimationGraphManager>& a_animGraphMgr) = 0;                                                                                                               // 05
		virtual bool          PopulateGraphNodesToTarget([[maybe_unused]] BSScrapArray<NiAVObject*>& a_nodesToAnimate) const { return false; }                                                                                                // 06
		virtual bool          ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_animGraph) = 0;                                                                                                                                 // 07
		virtual bool          InitializeAnimationGraphVariables([[maybe_unused]] const BSTSmartPointer<BShkbAnimationGraph>& a_newGraph) const { return true; }                                                                               // 08
		virtual bool          SetupAnimEventSinks([[maybe_unused]] const BSTSmartPointer<BShkbAnimationGraph>& a_newGraph) { return true; }                                                                                                   // 09
		virtual void          DoFailedToLoadGraph() const { return; }                                                                                                                                                                         // 0A
		virtual bool          CreateAnimationChannels([[maybe_unused]] BSScrapArray<BSTSmartPointer<BSAnimationGraphChannel>>& a_channels) { return false; }                                                                                  // 0B
		virtual void          PostCreateAnimationGraphManager([[maybe_unused]] BSTSmartPointer<BSAnimationGraphManager>& a_animGraphMgr) { return; }                                                                                          // 0C
		virtual void          PostChangeAnimationManager([[maybe_unused]] const BSTSmartPointer<BSAnimationGraphManager>& a_newAnimGraphMgr, [[maybe_unused]] const BSTSmartPointer<BSAnimationGraphManager>& a_oldAnimGraphMgr) { return; }  // 0D
		virtual bool          ShouldUpdateAnimation() { return true; }                                                                                                                                                                        // 0E
		virtual std::uint32_t GetGraphVariableCacheSize() const { return 0; }                                                                                                                                                                 // 0F
		virtual bool          GetGraphVariableImpl([[maybe_unused]] std::uint32_t a_graphVarID, [[maybe_unused]] float& a_out) const { return false; }                                                                                        // 10
		virtual bool          GetGraphVariableImpl([[maybe_unused]] std::uint32_t a_graphVarID, [[maybe_unused]] bool& a_out) const { return false; }                                                                                         // 11
		virtual bool          GetGraphVariableImpl([[maybe_unused]] std::uint32_t a_graphVarID, [[maybe_unused]] std::int32_t& a_out) const { return false; }                                                                                 // 12
		virtual bool          GetGraphVariableImplFloat(const BSFixedString& a_variable, float& a_out) const;                                                                                                                                 // 13
		virtual bool          GetGraphVariableImplInt(const BSFixedString& a_variable, std::int32_t& a_out) const;                                                                                                                            // 14
		virtual bool          GetGraphVariableImplBool(const BSFixedString& a_variable, bool& a_out) const;                                                                                                                                   // 15
		virtual void          PreUpdateAnimationGraphManager([[maybe_unused]] const BSTSmartPointer<BSAnimationGraphManager>& a_animGraphMgr) const { return; }                                                                               // 16
		virtual void          PostUpdateAnimationGraphManager([[maybe_unused]] const BSTSmartPointer<BSAnimationGraphManager>& a_animGraphMgr) const { return; }                                                                              // 17
		virtual void          PreLoadAnimationGraphManager([[maybe_unused]] const BSTSmartPointer<BSAnimationGraphManager>& a_animGraphMgr) { return; }                                                                                       // 18
		virtual void          PostLoadAnimationGraphManager([[maybe_unused]] const BSTSmartPointer<BSAnimationGraphManager>& a_animGraphMgr) { return; }                                                                                      // 19

		bool SetGraphVariableBool(const BSFixedString& a_variable, bool a_var)
		{
			using func_t = decltype(&IAnimationGraphManagerHolder::SetGraphVariableBool);
			static REL::Relocation<func_t> func{ ID::IAnimationGraphManagerHolder::SetGraphVariableBool };
			return func(this, a_variable, a_var);
		};

		bool SetGraphVariableFloat(const BSFixedString& a_variable, float a_var)
		{
			using func_t = decltype(&IAnimationGraphManagerHolder::SetGraphVariableFloat);
			static REL::Relocation<func_t> func{ ID::IAnimationGraphManagerHolder::SetGraphVariableFloat };
			return func(this, a_variable, a_var);
		};

		bool SetGraphVariableInt(const BSFixedString& a_variable, int a_var)
		{
			using func_t = decltype(&IAnimationGraphManagerHolder::SetGraphVariableInt);
			static REL::Relocation<func_t> func{ ID::IAnimationGraphManagerHolder::SetGraphVariableInt };
			return func(this, a_variable, a_var);
		};

		bool RevertAnimationGraphManager(bool a_performModifyInitialAnimationStateC = true)
		{
			using func_t = decltype(&IAnimationGraphManagerHolder::RevertAnimationGraphManager);
			static REL::Relocation<func_t> func{ ID::IAnimationGraphManagerHolder::RevertAnimationGraphManager };
			return func(this, a_performModifyInitialAnimationStateC);
		}
	};
	static_assert(sizeof(IAnimationGraphManagerHolder) == 0x8);
}
