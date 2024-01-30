// NotLL1Exception.cpp: implementation of the CNotLL1Exception class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CNotLL1Exception::CNotLL1Exception(std::string _n1,std::string _d1,std::string _n2,std::string _d2,std::string _common):
CException("SYNTAX-FILE",0),m_sName1(_n1),m_sName2(_n2),m_sCommon(_common),
m_sDesc1(_d1),m_sDesc2(_d2)
{
	
}

CNotLL1Exception::~CNotLL1Exception()
{

}

__PETER_COMPILER_END