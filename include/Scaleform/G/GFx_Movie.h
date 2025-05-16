#pragma once

#include "Scaleform/G/GFx_StateBag.h"
#include "Scaleform/P/Ptr.h"
#include "Scaleform/R/RefCountBase.h"
#include "Scaleform/R/Render_Point.h"
#include "Scaleform/R/Render_Matrix.h"
#include "Scaleform/R/Render_Color.h"
#include "Scaleform/T/ThreadId.h"
#include "Scaleform/R/Render_TreeRoot.h"
#include "Scaleform/R/Render_ContextImpl_DisplayHandle.h"
#include "Scaleform/R/Render_Rect.h"

namespace Scaleform
{
	class MemoryHeap;
	class StatBag;

	namespace Render
	{
		enum class EdgeAAMode;
	}

	namespace GFx
	{
		enum class PlayState;

		class ASMovieRootBase;
		class Event;
		class FunctionHandler;
		class Log;
		class MovieDef;
		class Value;
		class Viewport;

		class __declspec(novtable) Movie :
			public RefCountBase<Movie, 327>,  // 00
			public StateBag                   // 10
		{
		public:
			enum class SetVarType : std::int32_t
			{
				kNormal,
				kSticky,
				kPermanent
			};

			enum class SetArrayType : std::int32_t
			{
				kInt,
				kDouble,
				kFloat,
				kString,
				kStringW,
				kValue
			};

			enum class ScaleModeType : std::int32_t
			{
				kNoScale,
				kShowAll,
				kExactFit,
				kNoBorder
			};

			enum class AlignType : std::int32_t
			{
				kCenter,
				kTopCenter,
				kBottomCenter,
				kCenterLeft,
				kCenterRight,
				kTopLeft,
				kTopRight,
				kBottomLeft,
				kBottomRight
			};

			enum HE_ReturnValueType
			{
				HE_NotHandled = 0,
				HE_Handled = 1,
				HE_NoDefaultAction = 2,
				HE_Completed = (HE_Handled | HE_NoDefaultAction)
			};

			enum class HitTestType : std::int32_t
			{
				kBounds = 0,
				kShapes = 1,
				kButtonEvents = 2,
				kShapesNoInvisible = 3
			};

			enum class ReportFlags : std::uint32_t
			{
				kNone = 0,
				kShortFileNames = 1 << 0,
				kNoCircularReferences = 1 << 1,
				kSuppressOverallStats = 1 << 2,
				kAddressesForAnonymObjsOnly = 1 << 3,
				kSuppressMovieDefsStats = 1 << 4,
				kNoEllipsis = 1 << 5
			};

			enum class MakeAllVisibleFlags : std::uint32_t
			{
				kNone = 0,
				kDontScaleDown = 1 << 0,
				kScaleUp50 = 1 << 1,
				kLeftTopToZero = 1 << 2
			};

			virtual MovieDef*                                                   GetMovieDef() const = 0;                                                                                                                                                        // 01
			virtual std::uint32_t                                               GetCurrentFrame() const = 0;                                                                                                                                                    // 02
			virtual bool                                                        HasLooped() const = 0;                                                                                                                                                          // 03
			virtual void                                                        GotoFrame(std::uint32_t a_frameNumber) = 0;                                                                                                                                     // 04
			virtual bool                                                        GotoLabeledFrame(const char* a_label, std::int32_t a_offset = 0) = 0;                                                                                                           // 05
			virtual void                                                        SetPlayState(PlayState a_state) = 0;                                                                                                                                            // 06
			virtual PlayState                                                   GetPlayState() const = 0;                                                                                                                                                       // 07
			virtual bool                                                        IsValid() = 0;                                                                                                                                                                  // 08
			virtual void                                                        SetVisible(bool a_visible) = 0;                                                                                                                                                 // 09
			virtual bool                                                        GetVisible() const = 0;                                                                                                                                                         // 0A
			virtual std::uint64_t                                               GetASTimerMs() const = 0;                                                                                                                                                       // 0B
			virtual void                                                        SetViewport(const Viewport& a_viewDesc) = 0;                                                                                                                                    // 0C
			virtual void                                                        GetViewport(Viewport* a_viewDesc) const = 0;                                                                                                                                    // 0D
			virtual void                                                        SetViewScaleMode(ScaleModeType) = 0;                                                                                                                                            // 0E
			virtual ScaleModeType                                               GetViewScaleMode() const = 0;                                                                                                                                                   // 0F
			virtual void                                                        SetViewAlignment(AlignType) = 0;                                                                                                                                                // 10
			virtual AlignType                                                   GetViewAlignment() const = 0;                                                                                                                                                   // 11
			virtual Render::Rect<float>                                         GetVisibleFrameRect() const = 0;                                                                                                                                                // 12
			virtual Render::Rect<float>                                         GetSafeRect() const = 0;                                                                                                                                                        // 13
			virtual void                                                        SetSafeRect(const Render::Rect<float>& a_rect) = 0;                                                                                                                             // 14
			virtual void                                                        SetEdgeAAMode(Render::EdgeAAMode a_edgeAA) = 0;                                                                                                                                 // 15
			virtual Render::EdgeAAMode                                          GetEdgeAAMode() const = 0;                                                                                                                                                      // 16
			virtual void                                                        Restart(bool a_advance0 = true) = 0;                                                                                                                                            // 17
			virtual float                                                       Advance(float a_deltaT, std::uint32_t a_frameCatchUpCount = 2, bool a_capture = true) = 0;                                                                                      // 18
			virtual void                                                        Capture(bool a_onChangeOnly = true) = 0;                                                                                                                                        // 19
			virtual const Render::ContextImpl::DisplayHandle<Render::TreeRoot>& GetDisplayHandle() const = 0;                                                                                                                                                   // 1A
			virtual void                                                        SetCaptureThread(ThreadId a_captureThreadId) = 0;                                                                                                                               // 1B
			virtual void                                                        ShutdownRendering(bool a_wait) = 0;                                                                                                                                             // 1C
			virtual bool                                                        IsShutdownRenderingComplete() const = 0;                                                                                                                                        // 1D
			virtual void                                                        SetPause(bool a_pause) = 0;                                                                                                                                                     // 1E
			virtual bool                                                        IsPaused() const = 0;                                                                                                                                                           // 1F
			virtual void                                                        SetBackgroundColor(Render::Color a_bgColor) = 0;                                                                                                                                // 20
			virtual void                                                        SetBackgroundAlpha(float a_alpha) = 0;                                                                                                                                          // 21
			virtual float                                                       GetBackgroundAlpha() const = 0;                                                                                                                                                 // 22
			virtual std::uint32_t                                               HandleEvent(const Event& a_event) = 0;                                                                                                                                          // 23
			virtual void                                                        GetMouseState(std::uint32_t a_mouseIndex, float* a_x, float* a_y, std::uint32_t* a_buttons) = 0;                                                                                // 24
			virtual void                                                        NotifyMouseState(float a_x, float a_y, std::uint32_t a_buttons, std::uint32_t a_mouseIndex = 0) = 0;                                                                            // 25
			virtual bool                                                        HitTest(float a_x, float a_y, HitTestType a_testCond = HitTestType::kShapes, std::uint32_t a_controllerIdx = 0) = 0;                                                            // 26
			virtual void*                                                       GetUserData() const = 0;                                                                                                                                                        // 27
			virtual void                                                        SetUserData(void*) = 0;                                                                                                                                                         // 28
			virtual bool                                                        IsMovieFocused() const = 0;                                                                                                                                                     // 29
			virtual bool                                                        GetDirtyFlag(bool a_doReset = true) = 0;                                                                                                                                        // 2A
			virtual void                                                        SetMouseCursorCount(std::uint32_t a_num) = 0;                                                                                                                                   // 2B
			virtual std::uint32_t                                               GetMouseCursorCount() const = 0;                                                                                                                                                // 2C
			virtual void                                                        SetControllerCount(std::uint32_t a_num) = 0;                                                                                                                                    // 2D
			virtual std::uint32_t                                               GetControllerCount() const = 0;                                                                                                                                                 // 2E
			virtual void                                                        GetStats(StatBag* a_bag, bool a_reset = true) = 0;                                                                                                                              // 2F
			virtual MemoryHeap*                                                 GetHeap() const = 0;                                                                                                                                                            // 30
			virtual void                                                        ForceCollectGarbage() = 0;                                                                                                                                                      // 31
			virtual void                                                        SuspendGC(bool a_suspend) = 0;                                                                                                                                                  // 32
			virtual void                                                        ScheduleGC() = 0;                                                                                                                                                               // 33
			virtual void                                                        PrintObjectsReport(ReportFlags a_flags = ReportFlags::kNone, Log* a_log = nullptr, const char* a_swfName = nullptr) = 0;                                                        // 34
			virtual Render::Point<float>                                        TranslateToScreen(const Render::Point<float>& a_pt, Render::Matrix2x4<float>* a_userMatrix = nullptr) = 0;                                                                      // 36
			virtual Render::Rect<float>                                         TranslateToScreen(const Render::Rect<float>& a_pt, Render::Matrix2x4<float>* a_userMatrix = nullptr) = 0;                                                                       // 35
			virtual bool                                                        TranslateLocalToScreen(const char* a_pathToCharacter, const Render::Point<float>& a_pt, Render::Point<float>* a_presPt, Render::Matrix2x4<float>* a_userMatrix = nullptr) = 0;  // 37
			virtual bool                                                        SetControllerFocusGroup(std::uint32_t a_controllerIdx, std::uint32_t a_focusGroupIndex) = 0;                                                                                    // 38
			virtual std::uint32_t                                               GetControllerFocusGroup(std::uint32_t a_controllerIdx) const = 0;                                                                                                               // 39
			virtual void                                                        ResetInputFocus(std::uint32_t a_controllerIdx) = 0;                                                                                                                             // 3A
			virtual bool                                                        IsExitRequested() const = 0;                                                                                                                                                    // 3B
			virtual void                                                        GetViewMatrix3D(Render::Matrix3x4<float>*) = 0;                                                                                                                                 // 3C
			virtual void                                                        SetViewMatrix3D(const Render::Matrix3x4<float>& a_matrix) = 0;                                                                                                                  // 3D
			virtual void                                                        GetProjectionMatrix3D(Render::Matrix4x4<float>*) = 0;                                                                                                                           // 3E
			virtual void                                                        SetProjectionMatrix3D(const Render::Matrix4x4<float>& a_matrix) = 0;                                                                                                            // 3F
			virtual void                                                        SetStageAutoOrients(bool a_value = true) = 0;                                                                                                                                   // 40
			virtual void                                                        ForceUpdateImages() = 0;                                                                                                                                                        // 41
			virtual void                                                        MakeAreaVisible(const Render::Rect<float>& a_screenRect, const Render::Rect<float>& a_box, MakeAllVisibleFlags a_flags = MakeAllVisibleFlags::kNone) = 0;                       // 42
			virtual void                                                        RestoreViewport() = 0;                                                                                                                                                          // 43

			void CreateArray(Value* a_value);
			void CreateFunction(Value* a_value, FunctionHandler* a_function, void* a_userData = nullptr);
			void CreateObject(Value* a_value, const char* a_className = nullptr, const GFx::Value* a_args = nullptr, std::uint32_t a_numArgs = 0);
			bool GetVariable(Value* a_val, const char* a_pathToVar) const;
			bool SetVariable(const char* a_pathToVar, const Value& a_value, SetVarType a_setType = SetVarType::kSticky);
			bool Invoke(const char* a_methodName, Value* a_result, const char* a_argFmt, ...);
			bool Invoke(const char* a_methodName, Value* a_result, const Value* a_args, std::uint32_t a_numArgs);
			bool InvokeArgs(const char* a_methodName, Value* a_result, const char* a_argFmt, std::va_list a_args);

			void Release()
			{
				using func_t = decltype(&Movie::Release);
				static REL::Relocation<func_t> func{ REL::ID(2287230) };
				return func(this);
			}

			// members
			Ptr<ASMovieRootBase> asMovieRoot;  // 18
		};
		static_assert(sizeof(Movie) == 0x20);
	}
}
