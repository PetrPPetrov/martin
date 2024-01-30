// LexemException.h: interface for the CLexemException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEXEMEXCEPTION_H__B82BB3C5_DBF8_4A55_813A_10111B5F2D3B__INCLUDED_)
#define AFX_LEXEMEXCEPTION_H__B82BB3C5_DBF8_4A55_813A_10111B5F2D3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CLexemException : public CException
{
	CLexemException(std::string,long,char,int);
	virtual ~CLexemException();

	char m_cChar;
	int  m_iColumn;
};

__PETER_COMPILER_END

#endif // !defined(AFX_LEXEMEXCEPTION_H__B82BB3C5_DBF8_4A55_813A_10111B5F2D3B__INCLUDED_)
