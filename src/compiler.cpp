// Compiler.cpp: implementation of the CCompiler class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CCompiler::CCompiler()
{
	m_stTable.clear();
}

CCompiler::~CCompiler()
{
	m_stTable.clear();
}

void CCompiler::AddKey(std::string _table,std::string _key,std::string _value,int _tag)
{
	DeleteKey(_table,_key);
	m_stTable.insert(CKey(_table,_key,_value,_tag));
}

bool CCompiler::IsKey(std::string _table,std::string _key,int _tag)
{
	CKey key(_table,_key,"",_tag);
	std::set<CKey,Key_less>::iterator it;
	it=m_stTable.find(key);
	return it!=m_stTable.end();
}

std::string CCompiler::GetKey(std::string _table,std::string _key,int _tag)
{
	CKey key(_table,_key,"",_tag);
	std::set<CKey,Key_less>::iterator it;
	it=m_stTable.find(key);
	if (it!=m_stTable.end())
		return (*it).m_sValue;
	else
		return std::string("error!");
}
		
void CCompiler::DeleteTag(std::string _table,int _tag)
{
	std::set<CKey,Key_less>::iterator f,l,i;
	i=f=m_stTable.begin();
	l=m_stTable.end();
	while(i!=l)
	{
		if (((*i).m_sTable==_table)&&
			((*i).m_iTag==_tag))
		{
			m_stTable.erase(i);
			i=f=m_stTable.begin();
			l=m_stTable.end();
			continue;
		}
		i++;
	}
}

void CCompiler::DeleteTag(std::string _table)
{
	std::set<CKey,Key_less>::iterator f,l,i;
	i=f=m_stTable.begin();
	l=m_stTable.end();
	while(i!=l)
	{
		if (((*i).m_sTable==_table))
		{
			m_stTable.erase(i);
			i=f=m_stTable.begin();
			l=m_stTable.end();
			continue;
		}
		i++;
	}
}

void CCompiler::DeleteKey(std::string _table,std::string _key,int _tag)
{
	std::set<CKey,Key_less>::iterator f,l,i;
	i=f=m_stTable.begin();
	l=m_stTable.end();
	while(i!=l)
	{
		if (((*i).m_sTable==_table)&&
			((*i).m_sKey==_key)&&
			((*i).m_iTag==_tag))
		{
			m_stTable.erase(i);
			i=f=m_stTable.begin();
			l=m_stTable.end();
			continue;
		}
		i++;
	}
}

void CCompiler::DeleteKey(std::string _table,std::string _key)
{
	std::set<CKey,Key_less>::iterator f,l,i;
	i=f=m_stTable.begin();
	l=m_stTable.end();
	while(i!=l)
	{
		if (((*i).m_sTable==_table)&&
			((*i).m_sKey==_key))
		{
			m_stTable.erase(i);
			i=f=m_stTable.begin();
			l=m_stTable.end();
			continue;
		}
		i++;
	}
}

void CCompiler::DeleteAll()
{
	m_stTable.clear();
}

__PETER_COMPILER_END
