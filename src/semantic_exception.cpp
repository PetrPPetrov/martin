// SemanticException.cpp: implementation of the CSemanticException class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CSemanticException::CSemanticException(std::string _desc,std::string _file,long _line):
CException(_file,_line),m_sDescription(_desc)
{

}

CSemanticException::~CSemanticException()
{

}

__PETER_COMPILER_END