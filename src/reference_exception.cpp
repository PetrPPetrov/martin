// ReferenceException.cpp: implementation of the CReferenceException class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CReferenceException::CReferenceException(std::string lex1,std::string lex2):
CException("LEXEM-FILE",0),m_sLexem1_name(lex1),m_sLexem2_name(lex2)
{

}

CReferenceException::~CReferenceException()
{

}

__PETER_COMPILER_END