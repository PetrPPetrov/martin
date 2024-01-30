// Tree.h: interface for the CTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREE_H__10DAC8E1_FD90_11D6_A1C2_9051435FEBAD__INCLUDED_)
#define AFX_TREE_H__10DAC8E1_FD90_11D6_A1C2_9051435FEBAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CTree : public CEvent 
{
	CTree();
	CTree(int);
	virtual ~CTree();

	std::vector<CTree*> m_vComponents;
};

__PETER_COMPILER_END

#endif // !defined(AFX_TREE_H__10DAC8E1_FD90_11D6_A1C2_9051435FEBAD__INCLUDED_)
