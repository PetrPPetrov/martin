// UndeterminateException.h: interface for the CUndeterminateException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNDETERMINATEEXCEPTION_H__9A67EF53_1D2A_4E23_A306_29FE4A001376__INCLUDED_)
#define AFX_UNDETERMINATEEXCEPTION_H__9A67EF53_1D2A_4E23_A306_29FE4A001376__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CUndeterminateException : public CException  
{
	CUndeterminateException(std::string,std::string,char);
	virtual ~CUndeterminateException();

	std::string m_sLexem_name;
	char m_cChar;

};

__PETER_COMPILER_END

#endif // !defined(AFX_UNDETERMINATEEXCEPTION_H__9A67EF53_1D2A_4E23_A306_29FE4A001376__INCLUDED_)
