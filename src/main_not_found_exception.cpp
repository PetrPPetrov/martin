// MainNotFoundException.cpp: implementation of the CMainNotFoundException class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CMainNotFoundException::CMainNotFoundException():
CException("SYNTAX-FILE",0)
{

}

CMainNotFoundException::~CMainNotFoundException()
{

}

__PETER_COMPILER_END