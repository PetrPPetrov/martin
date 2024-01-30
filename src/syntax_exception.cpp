// SyntaxException.cpp: implementation of the CSyntaxException class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CSyntaxException::CSyntaxException(std::string file,long _line,std::string val,std::string t1,std::string t2):
CException(file,_line),
m_sValue_found(val),
m_sType_found(t1),
m_sType_expected(t2)
{

}

CSyntaxException::~CSyntaxException()
{

}

__PETER_COMPILER_END