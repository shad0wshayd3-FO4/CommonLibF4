#pragma once

namespace RE
{
	class hkCriticalSectionLock
	{
	public:
		hkCriticalSectionLock(hkCriticalSection* a_section)
		{
			m_section = a_section;
			m_section->Enter();
		}

		~hkCriticalSectionLock()
		{
			m_section->Leave();
		}

	protected:
		hkCriticalSection* m_section;
	};
}
