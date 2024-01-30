// Key.cpp: implementation of the CKey class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CKey::CKey()
{

}

CKey::CKey(std::string _table,std::string _key,std::string _value,int _tag):
m_sTable(_table),m_sKey(_key),m_sValue(_value),
m_iTag(_tag)
{

}

CKey::~CKey()
{

}

bool Key_less::operator()(const CKey &a,const CKey &b) const
{
	if (a.m_iTag<b.m_iTag)
		return true;
	else
	if (a.m_iTag>b.m_iTag)
		return false;
	else
	{
		if (a.m_sTable<b.m_sTable)
			return true;
		else
		if (a.m_sTable>b.m_sTable)
			return false;
		else
		{
			if (a.m_sKey<b.m_sKey)
				return true;
			else
			if (a.m_sKey>=b.m_sKey)
				return false;
		}
	}
	return false;
}

__PETER_COMPILER_END