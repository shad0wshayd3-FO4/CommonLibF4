#pragma once

#include "Scaleform/G/GFx_StatMovieView.h"
#include "Scaleform/R/RefCountBase.h"

namespace Scaleform::GFx
{
	class MovieDefImpl;
	class MovieImpl;

	class __declspec(novtable) ASIntervalTimerIntf :
		public RefCountBase<ASIntervalTimerIntf, kStatMV_ActionScript_Mem>  // 00
	{
	public:
		virtual ~ASIntervalTimerIntf() = default;  // 00

		// add
		virtual void          Start(MovieImpl* a_root) = 0;                          // 01
		virtual bool          Invoke(MovieImpl* a_root, float a_frameTime) = 0;      // 02
		virtual bool          IsActive() const = 0;                                  // 03
		virtual void          Clear() = 0;                                           // 04
		virtual bool          ClearFor(MovieImpl* a_root, MovieDefImpl* a_def) = 0;  // 05
		virtual std::uint64_t GetNextInvokeTime() const = 0;                         // 06
		virtual void          SetId(std::int32_t a_id) = 0;                          // 07
		virtual std::int32_t  GetId() const = 0;                                     // 08
	};
	static_assert(sizeof(ASIntervalTimerIntf) == 0x10);
}
