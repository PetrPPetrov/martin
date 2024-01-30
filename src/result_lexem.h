// ResultLexem.h: interface for the CResultLexem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESULTLEXEM_H__615F5C61_D506_4774_AC45_509F492FEDE4__INCLUDED_)
#define AFX_RESULTLEXEM_H__615F5C61_D506_4774_AC45_509F492FEDE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN
	
struct CResultLexem  
{
	CResultLexem();
	CResultLexem(int,std::string&,std::string&,long,std::string&);
	virtual ~CResultLexem();

	int	m_iNameID;
	long m_lLine;
	std::string m_sLexem_name;
	std::string m_sLexem_value;
	std::string m_sFile_source;

	friend std::ofstream& operator<<(std::ofstream&,CResultLexem&);
};

__PETER_COMPILER_END

#endif // !defined(AFX_RESULTLEXEM_H__615F5C61_D506_4774_AC45_509F492FEDE4__INCLUDED_)
