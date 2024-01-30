// ResultLexemSet.cpp: implementation of the CResultLexemSet class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CResultLexemSet::CResultLexemSet()
{
	m_vLexems.clear();
}

CResultLexemSet::~CResultLexemSet()
{
	std::vector<CResultLexem*>::iterator beg,end,i;
	beg=m_vLexems.begin();
	end=m_vLexems.end();
	for(i=beg;i!=end;i++)
		delete (*i);
	m_vLexems.clear();	
}

void CResultLexemSet::Reset()
{
	std::vector<CResultLexem*>::iterator beg,end,i;
	beg=m_vLexems.begin();
	end=m_vLexems.end();
	for(i=beg;i!=end;i++)
		delete (*i);
	m_vLexems.clear();	
}

void CResultLexemSet::AddLexem(int _id,std::string &_lexem_name,std::string &_lexem_value,long _line,std::string &_file_source)
{
	CResultLexem *new_result_lexem;
	new_result_lexem = new CResultLexem(_id,_lexem_name,_lexem_value,_line,_file_source);
	m_vLexems.push_back(new_result_lexem);
}

void CResultLexemSet::AddLexem(CResultLexem &res_lexem)
{
	CResultLexem *new_result_lexem;
	new_result_lexem = new CResultLexem(res_lexem.m_iNameID,res_lexem.m_sLexem_name,res_lexem.m_sLexem_value,res_lexem.m_lLine,res_lexem.m_sFile_source);
	m_vLexems.push_back(new_result_lexem);
}

void CResultLexemSet::Dump(std::string file_name)
{
	std::ofstream sFile(file_name.c_str());
	std::vector<CResultLexem*>::iterator beg,end,i;
	beg=m_vLexems.begin();
	end=m_vLexems.end();
	for(i=beg;i!=end;i++)
	{
		CResultLexem* lex=(*i);
		sFile<<(*lex);
	}
	sFile.close();
}

std::ofstream& operator<<(std::ofstream& sFile,CResultLexemSet& ResultLexemSet)
{
	std::vector<CResultLexem*>::iterator beg,end,i;
	beg=ResultLexemSet.m_vLexems.begin();
	end=ResultLexemSet.m_vLexems.end();
	for(i=beg;i!=end;i++)
	{
		CResultLexem* lex=(*i);
		sFile<<(*lex);
	}
	return sFile;
}

void CResultLexemSet::GetNextLexem(CResultLexem &rl,bool go)
{
	if (m_itCur==m_vLexems.end())
	{
		rl.m_iNameID=0;
		rl.m_sLexem_name="e";
		rl.m_sLexem_value="";
	}else
	{
		rl=*(*m_itCur);
		if (go) m_itCur++;
	}
}
		
void CResultLexemSet::Prepare()
{
	m_itCur=m_vLexems.begin();
}

__PETER_COMPILER_END