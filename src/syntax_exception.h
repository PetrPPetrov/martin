// SyntaxException.h: interface for the CSyntaxException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYNTAXEXCEPTION_H__74C95D63_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_)
#define AFX_SYNTAXEXCEPTION_H__74C95D63_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CSyntaxException : public CException  
{
	CSyntaxException(std::string,long,std::string,std::string,std::string);
	virtual ~CSyntaxException();

	std::string m_sValue_found;
	std::string m_sType_found;
	std::string m_sType_expected;

};

__PETER_COMPILER_END

#endif // !defined(AFX_SYNTAXEXCEPTION_H__74C95D63_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_)
