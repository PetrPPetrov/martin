// NotLL1Exception.h: interface for the CNotLL1Exception class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOTLL1EXCEPTION_H__74C95D60_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_)
#define AFX_NOTLL1EXCEPTION_H__74C95D60_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CNotLL1Exception : public CException  
{
	CNotLL1Exception(std::string,std::string,std::string,std::string,std::string);
	virtual ~CNotLL1Exception();

	std::string m_sDesc1;
	std::string m_sDesc2;
	std::string m_sName1;
	std::string m_sName2;
	std::string m_sCommon;
	
};

__PETER_COMPILER_END

#endif // !defined(AFX_NOTLL1EXCEPTION_H__74C95D60_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_)
