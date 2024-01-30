// Key.h: interface for the CKey class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KEY_H__C1B15581_FFBB_11D6_A1C2_CBA2EFABE888__INCLUDED_)
#define AFX_KEY_H__C1B15581_FFBB_11D6_A1C2_CBA2EFABE888__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN
	
struct CKey  
{
	CKey();
	CKey(std::string,std::string,std::string,int);
	virtual ~CKey();

	std::string m_sTable;
	std::string m_sKey;
	std::string m_sValue;
	int m_iTag;
};

struct Key_less : std::binary_function<CKey,CKey,bool> 
{
	bool operator()(const CKey&,const CKey&) const;
};

__PETER_COMPILER_END

#endif // !defined(AFX_KEY_H__C1B15581_FFBB_11D6_A1C2_CBA2EFABE888__INCLUDED_)
