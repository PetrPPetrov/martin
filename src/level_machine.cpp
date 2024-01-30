// LevelMachine.cpp: implementation of the CLevelMachine class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CLevelMachine::CLevelMachine():
m_iLevel(0)
{

}

CLevelMachine::~CLevelMachine()
{

}

void CLevelMachine::Put(char c)
{
	if (c=='(') m_iLevel++; else
	if (c==')') m_iLevel--;
}

__PETER_COMPILER_END