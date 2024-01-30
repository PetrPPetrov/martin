// Exception.h: interface for the CException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXCEPTION_H__02A4B854_17EF_41B1_AAE2_DA46F03E50D5__INCLUDED_)
#define AFX_EXCEPTION_H__02A4B854_17EF_41B1_AAE2_DA46F03E50D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CException  
{
	CException(std::string,long);
	virtual ~CException();

	std::string m_sFile_name;
	long m_lLine;
};

__PETER_COMPILER_END

#endif // !defined(AFX_EXCEPTION_H__02A4B854_17EF_41B1_AAE2_DA46F03E50D5__INCLUDED_)
