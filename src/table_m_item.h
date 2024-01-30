// TableMItem.h: interface for the CTableMItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLEMITEM_H__74C95D61_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_)
#define AFX_TABLEMITEM_H__74C95D61_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

#define TABLE_M_ERROR    0
#define TABLE_M_EJECT    1
#define TABLE_M_SUCCESS  2
#define TABLE_M_PUSH     3
struct CTableMItem  
{
	CTableMItem();
	virtual ~CTableMItem();

	int m_iItem_type;
	int m_iRule;

};

__PETER_COMPILER_END

#endif // !defined(AFX_TABLEMITEM_H__74C95D61_FCA7_11D6_A1C2_D2E0958EE28A__INCLUDED_)
