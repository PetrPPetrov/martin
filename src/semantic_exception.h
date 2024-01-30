// SemanticException.h: interface for the CSemanticException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEMANTICEXCEPTION_H__006230E0_00B3_11D7_A1C2_DAF2F8FC12BF__INCLUDED_)
#define AFX_SEMANTICEXCEPTION_H__006230E0_00B3_11D7_A1C2_DAF2F8FC12BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CSemanticException : public CException  
{	
	CSemanticException(std::string,std::string,long);
	virtual ~CSemanticException();

	std::string m_sDescription;

};

__PETER_COMPILER_END

#endif // !defined(AFX_SEMANTICEXCEPTION_H__006230E0_00B3_11D7_A1C2_DAF2F8FC12BF__INCLUDED_)
