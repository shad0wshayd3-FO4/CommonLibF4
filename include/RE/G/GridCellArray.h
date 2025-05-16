#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GridArray.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	struct GridCell;

	class __declspec(novtable) GridCellArray :
		public GridArray  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::GridCellArray };
		static constexpr auto VTABLE{ VTABLE::GridCellArray };

		struct QueuedAttatch
		{
			enum class ProgressiveAttatchState : std::int32_t
			{
				PROGRESSIVE_ATTATCH_TO_WORLD = 0x0,
				PROGRESSIVE_ATTATCH_MODELS = 0x1,
				PROGRESSIVE_ATTATCH_REGISTER_COMBINED_OBJECT_VISIBILITY = 0x2,
				PROGRESSIVE_ATTATCH_DONE = 0x3
			};

		public:
			// members
			TESObjectCELL*          cell;          // 00
			ProgressiveAttatchState attatchState;  // 08
		};
		static_assert(sizeof(QueuedAttatch) == 0x10);

		struct QueuedDetach
		{
			enum class ProgressiveDetachState : std::int32_t
			{
				PROGRESSIVE_DETATCH_ACTORS_NEXT = 0x0,
				PROGRESSIVE_DETATCH_REFS_NEXT = 0x1,
				PROGRESSIVE_DETATCH_COMBINED_ART_NEXT = 0x2,
				PROGRESSIVE_DETATCH_DONE = 0x3
			};

		public:
			// members
			TESObjectCELL*         cell;         // 00
			ProgressiveDetachState detachState;  // 08
		};
		static_assert(sizeof(QueuedDetach) == 0x10);

		struct AutoDisableQueuedCellAttatchDetach
		{
		public:
			// members
			GridCellArray* grid;  // 00
		};

		~GridCellArray() override;  // 00

		// override
		void KillAll() override;                                                                                         // 02
		bool SetCenter(std::int32_t a_x, std::int32_t a_y) override;                                                     // 03
		void Detach(std::uint32_t a_x, std::uint32_t a_y) override;                                                      // 05
		void ClearItem(std::uint32_t a_x, std::uint32_t a_y) override;                                                   // 06
		void MoveItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY) override;  // 07
		void SwapItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY) override;  // 08

		GridCell* Get(std::uint32_t a_x, std::uint32_t a_y)
		{
			using func_t = decltype(&GridCellArray::Get);
			static REL::Relocation<func_t> func{ REL::ID(2194566) };
			return func(this, a_x, a_y);
		}

		// members
		GridCell*               gridCell;
		std::uint32_t           cellAttachDetatchQueueDisabled;
		BSTArray<QueuedAttatch> queuedAttach;
		BSTArray<QueuedDetach>  queuedDetach;
		NiPoint3                worldCenter;
		bool                    landAttached;
	};
	static_assert(sizeof(GridCellArray) == 0x68);
}
