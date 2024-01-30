// LexemException.cpp: implementation of the CLexemException class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CLexemException::CLexemException(std::string _file,long _line,char _char,int _column):
CException(_file,_line),m_cChar(_char),m_iColumn(_column)
{
	
}

CLexemException::~CLexemException()
{

}

__PETER_COMPILER_END