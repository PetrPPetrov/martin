// StateMachineSet.cpp: implementation of the CStateMachineSet class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CStateMachineSet::CStateMachineSet()
{
	m_vStateMachines.clear();
	m_bWasRight=false;
	m_bWasRight_LineTerminator=false;
}

CStateMachineSet::~CStateMachineSet()
{
	std::vector<CStateMachine*>::iterator beg,end,it;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	for(it=beg;it!=end;it++)
		delete (*it);
	m_vStateMachines.clear();
}

std::ifstream& operator>>(std::ifstream& sFile,CStateMachineSet &sm)
{
	std::string str;
	std::string lex_name;
	std::string lex_desc;
	int state=0x00;
	int option=LEX_OPTION_NONE;
	int i=1;
	while(sFile>>str)
	{
		switch(state)
		{
		case 0x00:
			lex_name=str;
			lex_name.erase(0,1);
			lex_desc="";
			state=0x01;
			option=ParseLexOption(lex_name);
			break;
		case 0x01:
			if (str[0]==':')
			{
				sm.AddLexem(i++,lex_name,lex_desc,option);
				lex_name=str;
				lex_name.erase(0,1);
				lex_desc="";
				option=ParseLexOption(lex_name);
			}else
			{
				lex_desc=lex_desc+str;
			}
			break;
		}
	}
	sm.AddLexem(i,lex_name,lex_desc,option);
	return sFile;
}

void CStateMachineSet::AddLexem(int _id,std::string lex_name,std::string lex_desc,int option) throw(CPeterCompiler::CReferenceException)
{
	std::string tmp;
	std::vector<CStateMachine*>::iterator beg,end,it;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	int a;
	for(it=beg;it!=end;it++)
	{
		if (lex_name.find((*it)->m_sLexem_name)<lex_name.length())
			throw CPeterCompiler::CReferenceException(lex_name,(*it)->m_sLexem_name);
	}
	for(it=beg;it!=end;it++)
	{
		CStateMachine *s=(*it);
		tmp=s->m_sLexem_name;
		while((a=lex_desc.find(tmp))<lex_desc.length())
		{
			lex_desc.erase(a,tmp.length());
			lex_desc.insert(a,s->m_sLexem_description);
		}
	}
	while((a=lex_desc.find_first_of(" "))<lex_desc.length())
	{
		lex_desc.erase(a,1);
	}
	CStateMachine *s=new CStateMachine(_id,lex_name,lex_desc,option);
	s->CreateLexem();
	m_vStateMachines.push_back(s);
}

void CStateMachineSet::Prepare()
{
	std::vector<CStateMachine*>::iterator beg,end,it;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	for(it=beg;it!=end;it++)
		(*it)->Prepare();
	m_itLastRight=beg;
	m_bWasRight=false;
	m_sRightValue="";
}

void CStateMachineSet::Prepare_LineTerminator()
{
	std::vector<CStateMachine*>::iterator beg,end,it;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	for(it=beg;it!=end;it++)
		(*it)->Prepare_LineTerminator();
	m_itLastRight_LineTerminator=beg;
	m_bWasRight_LineTerminator=false;
}

bool CStateMachineSet::Scan(char c,bool &error)
{
	std::vector<CStateMachine*>::iterator beg,end,it,last;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	last=beg;
	int num_right=0;
	bool bLast=false;
	for(it=beg;it!=end;it++)
		if ((*it)->Scan(c)) 
		{
			num_right++;
			if ((!bLast)&&((*it)->IsEndState()))
			{
				m_itLastRight=it;
				bLast=true;
			}
			m_bWasRight=true;
		}
	if (!num_right)
	{
		error=!m_bWasRight;
		return false;
	}else
	{
		m_sRightValue=m_sRightValue+c;
		error=false;
		return true;
	}
}

bool CStateMachineSet::Scan_LineTerminator(char c,bool &error)
{
	std::vector<CStateMachine*>::iterator beg,end,it,last;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	last=beg;
	int num_right=0;
	bool bLast=false;
	for(it=beg;it!=end;it++)
		if ((*it)->Scan_LineTerminator(c)) 
		{
			num_right++;
			if ((!bLast)&&((*it)->IsEndState()))
			{
				m_itLastRight_LineTerminator=it;
				bLast=true;
			}
			m_bWasRight_LineTerminator=true;
		}
	if (!num_right)
	{
		error=!m_bWasRight_LineTerminator;
		return false;
	}else
	{
		error=false;
		return true;
	}
}

void CStateMachineSet::GetLastRightLexem(int &id,std::string &name,std::string &value,int &option)
{
	id=(*m_itLastRight)->m_iNameID;
	name=(*m_itLastRight)->m_sLexem_name;
	value=m_sRightValue;
	option=(*m_itLastRight)->m_iOption;
}

int CStateMachineSet::GetNumStateMachines()
{
	return m_vStateMachines.size();
}

bool CStateMachineSet::IsLexem(std::string _name)
{
	std::vector<CStateMachine*>::iterator beg,end,it;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	for(it=beg;it!=end;it++)
	{
		if (_name==(*it)->m_sLexem_name) 
			return true;
	}
	return false;
}

int CStateMachineSet::GetID(std::string _name) throw(CPeterCompiler::CLexemNotFoundException)
{
	std::vector<CStateMachine*>::iterator beg,end,it;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	for(it=beg;it!=end;it++)
	{
		if (_name==(*it)->m_sLexem_name) 
			return (*it)->m_iNameID;
	}
	throw CPeterCompiler::CLexemNotFoundException(_name);
}

void CStateMachineSet::GetName(int code,std::string &str)
{
	std::vector<CStateMachine*>::iterator beg,end,it;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	for(it=beg;it!=end;it++)
	{
		if (code==(*it)->m_iNameID) 
		{
			str=(*it)->m_sLexem_name;
			return;
		}
	}
}

void CStateMachineSet::Save(std::ofstream &out)
{
	out<<m_vStateMachines.size()<<std::endl;
	std::vector<CStateMachine*>::iterator beg,end,it;
	beg=m_vStateMachines.begin();
	end=m_vStateMachines.end();
	for(it=beg;it!=end;it++)
		(*it)->Save(out);
}
		
void CStateMachineSet::Load(std::ifstream &in)
{
	long count,i;
	in>>count;
	for(i=0;i<count;i++)
	{
		CStateMachine *s=new CStateMachine(0,"","",0);
		s->Load(in);
		m_vStateMachines.push_back(s);
	}
}

int ParseLexOption(std::string &lex_name)
{
	int option=LEX_OPTION_NONE;
	if (lex_name.size()==0) return option;
	while((lex_name[0]=='*')||(lex_name[0]=='&')||(lex_name[0]=='%'))
	{
		switch(lex_name[0])
		{
		case '*':
			lex_name.erase(0,1);
			option|=LEX_OPTION_COMMENT;
			break;
		case '&':
			lex_name.erase(0,1);
			option|=LEX_OPTION_DISABLED;
			break;
		case '%':
			lex_name.erase(0,1);
			option|=LEX_OPTION_LINE_TERMINATOR;
			break;
		}
	}
	return option;
}

__PETER_COMPILER_END