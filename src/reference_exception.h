// ReferenceException.h: interface for the CReferenceException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REFERENCEEXCEPTION_H__44F0F9A2_8461_473F_B192_392953C7F6F5__INCLUDED_)
#define AFX_REFERENCEEXCEPTION_H__44F0F9A2_8461_473F_B192_392953C7F6F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CReferenceException : public CException  
{
	CReferenceException(std::string,std::string);
	virtual ~CReferenceException();

	std::string m_sLexem1_name;
	std::string m_sLexem2_name;

};

__PETER_COMPILER_END

#endif // !defined(AFX_REFERENCEEXCEPTION_H__44F0F9A2_8461_473F_B192_392953C7F6F5__INCLUDED_)
