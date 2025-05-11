#pragma once

#include "RE/Havok/hkRefPtr.h"
#include "RE/Havok/hkSignalSlots.h"
#include "RE/Havok/hknpBodyId.h"
#include "RE/Havok/hknpConstraintId.h"
#include "RE/Havok/hknpMotionId.h"

namespace RE
{
	class hknpBodyCinfo;
	class hknpBodyManager;
	class hknpConstraint;
	class hknpConstraintCinfo;
	class hknpConstraintManager;
	class hknpMotionCinfo;
	class hknpMotionManager;
	class hknpShape;
	class hknpSolverData;
	class hknpStepInput;
	class hknpWorld;
	class hkVector4f;

	class hknpWorldSignals
	{
	public:
		struct BodyAddedSignal :
			public hkSignal2<hknpWorld*, hknpBodyId>
		{};

		struct BodyAttachToCompoundSignal :
			public hkSignal3<hknpWorld*, hknpBodyId, hknpBodyId>
		{};

		struct BodyBufferChangedSignal :
			public hkSignal2<hknpWorld*, hknpBodyManager*>
		{};

		struct BodyBufferFullSignal :
			public hkSignal2<hknpWorld*, hknpBodyManager*>
		{};

		struct BodyChangedSignal :
			public hkSignal2<hknpWorld*, hknpBodyId>
		{};

		struct BodyCreatedSignal :
			public hkSignal3<hknpWorld*, const hknpBodyCinfo*, hknpBodyId>
		{};

		struct BodyDestroyedSignal :
			public hkSignal2<hknpWorld*, hknpBodyId>
		{};

		struct BodyDetachToCompoundSignal :
			public hkSignal3<hknpWorld*, hknpBodyId, hknpMotionId>
		{};

		struct BodyRemovedSignal :
			public hkSignal2<hknpWorld*, hknpBodyId>
		{};

		struct BodyShapeSetSignal :
			public hkSignal3<hknpWorld*, hknpBodyId, hkRefPtr<const hknpShape>&>
		{};

		struct BodySwitchStaticDynamicSignal :
			public hkSignal3<hknpWorld*, hknpBodyId, bool>
		{};

		struct ConstraintBufferChangedSignal :
			public hkSignal2<hknpWorld*, hknpConstraintManager*>
		{};

		struct ConstraintBufferFullSignal :
			public hkSignal2<hknpWorld*, hknpConstraintManager*>
		{};

		struct ConstraintCreatedSignal :
			public hkSignal3<hknpWorld*, const hknpConstraintCinfo*, hknpConstraintId>
		{};

		struct ConstraintDestroyedSignal :
			public hkSignal2<hknpWorld*, hknpConstraintId>
		{};

		struct ConstraintDisabledSignal :
			public hkSignal2<hknpWorld*, hknpConstraintId>
		{};

		struct ConstraintEnabledSignal :
			public hkSignal2<hknpWorld*, hknpConstraintId>
		{};

		struct ImmediateConstraintAddedSignal :
			public hkSignal2<hknpWorld*, hknpConstraint*>
		{};

		struct MotionBufferChangedSignal :
			public hkSignal2<hknpWorld*, hknpMotionManager*>
		{};

		struct MotionBufferFullSignal :
			public hkSignal2<hknpWorld*, hknpMotionManager*>
		{};

		struct MotionCreatedSignal :
			public hkSignal3<hknpWorld*, const hknpMotionCinfo*, hknpMotionId>
		{};

		struct MotionDestroyedSignal :
			public hkSignal2<hknpWorld*, hknpMotionId>
		{};

		struct PostCollideSignal :
			public hkSignal2<hknpWorld*, const hknpSolverData*>
		{};

		struct PostSolveSignal :
			public hkSignal1<hknpWorld*>
		{};

		struct PreCollideSignal :
			public hkSignal2<hknpWorld*, const hknpStepInput&>
		{};

		struct PreSolveSignal :
			public hkSignal2<hknpWorld*, const hknpSolverData*>
		{};

		struct StaticBodyMovedSignal :
			public hkSignal2<hknpWorld*, hknpBodyId>
		{};

		struct WorldDestroyedSignal :
			public hkSignal1<hknpWorld*>
		{};

		struct WorldShiftedSignal :
			public hkSignal2<hknpWorld*, const hkVector4f&>
		{};

		WorldDestroyedSignal           worldDestroyed;
		WorldShiftedSignal             worldShifted;
		BodyBufferFullSignal           bodyBufferFull;
		BodyBufferChangedSignal        bodyBufferChanged;
		BodyCreatedSignal              bodyCreated;
		BodyAddedSignal                bodyAdded;
		BodyRemovedSignal              bodyRemoved;
		BodyDestroyedSignal            bodyDestroyed;
		MotionBufferFullSignal         motionBufferFull;
		MotionBufferChangedSignal      motionBufferChanged;
		MotionCreatedSignal            motionCreated;
		MotionDestroyedSignal          motionDestroyed;
		StaticBodyMovedSignal          staticBodyMoved;
		BodySwitchStaticDynamicSignal  bodySwitchStaticDynamic;
		BodyAttachToCompoundSignal     bodyAttached;
		BodyDetachToCompoundSignal     bodyDetached;
		BodyShapeSetSignal             bodyShapeChanged;
		BodyChangedSignal              bodyChanged;
		ConstraintBufferFullSignal     constraintBufferFull;
		ConstraintBufferChangedSignal  constraintBufferChanged;
		ConstraintCreatedSignal        constraintCreated;
		ConstraintDestroyedSignal      constraintDestroyed;
		ConstraintEnabledSignal        constraintEnabled;
		ConstraintDisabledSignal       constraintDisabled;
		ImmediateConstraintAddedSignal immediateConstraintAdded;
		PreCollideSignal               preCollide;
		PostCollideSignal              postCollide;
		PreSolveSignal                 preSolve;
		PostSolveSignal                postSolve;
	};
	static_assert(sizeof(hknpWorldSignals) == 0xE8);
}
