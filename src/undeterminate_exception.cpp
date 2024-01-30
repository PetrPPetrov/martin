// UndeterminateException.cpp: implementation of the CUndeterminateException class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CUndeterminateException::CUndeterminateException(std::string _file,std::string _lexem,char _char):
CException(_file,0),m_sLexem_name(_lexem),m_cChar(_char)
{

}

CUndeterminateException::~CUndeterminateException()
{

}

__PETER_COMPILER_END