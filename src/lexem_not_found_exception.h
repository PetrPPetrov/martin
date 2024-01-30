// LexemNotFoundException.h: interface for the CLexemNotFoundException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEXEMNOTFOUNDEXCEPTION_H__4ACA9420_FCA2_11D6_A1C2_D2E0958EE28A__INCLUDED_)
#define AFX_LEXEMNOTFOUNDEXCEPTION_H__4ACA9420_FCA2_11D6_A1C2_D2E0958EE28A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CLexemNotFoundException : public CException  
{
	CLexemNotFoundException(std::string);
	virtual ~CLexemNotFoundException();

	std::string m_sLexem_name;
	
};

__PETER_COMPILER_END

#endif // !defined(AFX_LEXEMNOTFOUNDEXCEPTION_H__4ACA9420_FCA2_11D6_A1C2_D2E0958EE28A__INCLUDED_)
