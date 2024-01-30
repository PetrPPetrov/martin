// ResultLexem.cpp: implementation of the CResultLexem class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CResultLexem::CResultLexem():
m_iNameID(0),m_sLexem_name(""),m_sLexem_value(""),
m_lLine(0),m_sFile_source("")
{

}

CResultLexem::CResultLexem(int _id,std::string &_lexem_name,std::string &_lexem_value,long _line,std::string &_file_source):
m_iNameID(_id),m_lLine(_line)
{
	m_sLexem_name=_lexem_name;
	m_sLexem_value=_lexem_value;
	m_sFile_source=_file_source;
}

CResultLexem::~CResultLexem()
{
	
}

std::ofstream& operator<<(std::ofstream& sFile,CResultLexem& ResultLexem)
{
	sFile<<"Type: "<<ResultLexem.m_sLexem_name;
	sFile<<"\tValue: \""<<ResultLexem.m_sLexem_value;
	sFile<<"\"\tTypeID: "<<ResultLexem.m_iNameID;
	sFile<<"\tFile_source: "<<ResultLexem.m_sFile_source;
	sFile<<"\tLine: "<<ResultLexem.m_lLine;
	sFile<<std::endl;
	return sFile;
}

__PETER_COMPILER_END