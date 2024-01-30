// Event.h: interface for the CEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVENT_H__10DAC8E0_FD90_11D6_A1C2_9051435FEBAD__INCLUDED_)
#define AFX_EVENT_H__10DAC8E0_FD90_11D6_A1C2_9051435FEBAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CEvent  
{
	CEvent();
	CEvent(int);
	virtual ~CEvent();

	int m_iType;
	int m_iRule;
	long m_lLine;
	std::string m_sType_name;
	std::string m_sLexem_value;
	std::string m_sFile_source;
	
};

__PETER_COMPILER_END

#endif // !defined(AFX_EVENT_H__10DAC8E0_FD90_11D6_A1C2_9051435FEBAD__INCLUDED_)
