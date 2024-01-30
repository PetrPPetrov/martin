// LexemNotFoundException.cpp: implementation of the CLexemNotFoundException class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CLexemNotFoundException::CLexemNotFoundException(std::string _s):
CException("SYNTAX-FILE",0),m_sLexem_name(_s)
{

}

CLexemNotFoundException::~CLexemNotFoundException()
{

}

__PETER_COMPILER_END