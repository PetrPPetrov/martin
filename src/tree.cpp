// Tree.cpp: implementation of the CTree class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CTree::CTree()
{
	m_vComponents.clear();
}

CTree::CTree(int _type):
CEvent(_type)
{
	m_vComponents.clear();
}

CTree::~CTree()
{
	std::vector<CTree*>::iterator beg,end,i;
	beg=m_vComponents.begin();
	end=m_vComponents.end();
	for(i=beg;i!=end;i++)
		delete (*i);
	m_vComponents.clear();
}

__PETER_COMPILER_END