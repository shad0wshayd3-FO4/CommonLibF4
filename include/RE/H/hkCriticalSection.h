#pragma once

namespace RE
{
	class hkCriticalSection
	{
	public:
		hkCriticalSection(std::int32_t a_spinCount = 0)
		{
			if (a_spinCount == 0)
				a_spinCount = 1000 * hkHardwareInfo::CalcNumHardwareThreads();

			REX::W32::InitializeCriticalSectionAndSpinCount(&m_section, a_spinCount);
		}

		~hkCriticalSection()
		{
			REX::W32::DeleteCriticalSection(&m_section);
		}

		void Enter()
		{
			REX::W32::EnterCriticalSection(&m_section);
		}

		void Leave()
		{
			REX::W32::LeaveCriticalSection(&m_section);
		}

	protected:
		REX::W32::CRITICAL_SECTION m_section;
	};
}
