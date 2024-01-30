// Event.cpp: implementation of the CEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CEvent::CEvent():
m_iType(0),m_iRule(0),
m_sType_name(""),m_sLexem_value("")
{

}

CEvent::CEvent(int _type):
m_iType(_type),m_iRule(0),
m_sType_name(""),m_sLexem_value("")
{

}

CEvent::~CEvent()
{

}

__PETER_COMPILER_END