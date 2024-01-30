// StateMachine.cpp: implementation of the CStateMachine class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CStateMachine::CStateMachine():
m_sLexem_name("????"),m_sLexem_description("????"),
m_iNumStates(0),m_pStateData(NULL),m_pStateEnd(NULL),
m_iState(0),m_bError(false),m_iNameID(-1),m_iOption(LEX_OPTION_NONE)
{
	m_vStates.clear();
	m_vJumps.clear();
}

CStateMachine::CStateMachine(int _id,std::string _name,std::string _desc,int _option):
m_iNameID(_id),m_sLexem_name(_name),m_sLexem_description(_desc),
m_iNumStates(0),m_pStateData(NULL),m_pStateEnd(NULL),
m_iState(0),m_bError(false),m_iOption(_option)
{
	m_vStates.clear();
	m_vJumps.clear();
}

CStateMachine::~CStateMachine()
{
	std::vector<CState*>::iterator beg,end,it;
	std::vector<CJump*>::iterator jbeg,jend,jt;
	jbeg=m_vJumps.begin();
	jend=m_vJumps.end();
	beg=m_vStates.begin();
	end=m_vStates.end();
	for(it=beg;it!=end;it++)
		delete (*it);
	m_vStates.clear();
	for(jt=jbeg;jt!=jend;jt++)
		delete (*jt);
	m_vJumps.clear();
	if (m_pStateData)
		delete[m_iNumStates*256] m_pStateData;
	if (m_pStateEnd)
		delete[m_iNumStates] m_pStateEnd;
}

void CStateMachine::CreateLexem()
{
	CState *begin,*end;
	begin=new CState();
	end=new CState();
	end->m_bEnd=true;
	m_vStates.clear();
	m_vJumps.clear();
	m_vStates.push_back(begin);
	m_vStates.push_back(end);
	CreateLexemSub(m_sLexem_description,begin,end);
		/*DumpStates("s1_"+m_sLexem_name);
		DumpJumps("j1_"+m_sLexem_name);*/
	DeleteEJumps();
		/*DumpStates("s2_"+m_sLexem_name);
		DumpJumps("j2_"+m_sLexem_name);*/
	OptimizeStates();
		/*DumpStates("s3_"+m_sLexem_name);
		DumpJumps("j3_"+m_sLexem_name);*/
	CheckDeterminate();
	CreateStateData();
		/*DumpStates("s4_"+m_sLexem_name);
		DumpJumps("j4_"+m_sLexem_name);*/
	DeleteExtraData();
		/*DumpStates("s5_"+m_sLexem_name);
		DumpJumps("j5_"+m_sLexem_name);*/
}

void CStateMachine::CreateLexemSub(std::string desc,CState* left,CState* right)
{
	CJump *jump;
	CState *state,*state1;
	std::string arg1,arg2;
	std::string number;
	int inumber;
	int str_len,i=0;
	char c,c1;
	str_len=desc.length();
	c=desc[0];		
	desc.erase(0,1);
	c1=desc[0];
	if (c1=='\'')
	{
		desc.erase(0,1);
		number="";
		c1=desc[0];
		while(c1!='\'')
		{
			number=number+c1;
			desc.erase(0,1);
			c1=desc[0];
		}
		desc.erase(0,1);
		inumber=atoi(number.c_str());
		switch(c)
		{
		case '*':
			jump = new CJump();
			jump->m_bE=true;
			jump->m_pFrom=left;
			jump->m_pTo=right;
			m_vJumps.push_back(jump);
			DeScob(desc,arg1);
			state1=left;
			for(i=0;i<inumber;i++)
			{
				state = new CState();
				m_vStates.push_back(state);
				CreateLexemSub(arg1,state1,state);
				jump = new CJump();
				jump->m_bE=true;
				jump->m_pFrom=state;
				jump->m_pTo=right;
				m_vJumps.push_back(jump);
				state1 = state;
			}
			break;
		case '+':
			DeScob(desc,arg1);
			state1 = new CState();
			m_vStates.push_back(state1);
			CreateLexemSub(arg1,left,state1);
			jump = new CJump();
			jump->m_bE=true;
			jump->m_pFrom=state1;
			jump->m_pTo=right;
			m_vJumps.push_back(jump);
			for(i=0;i<inumber-1;i++)
			{
				state = new CState();
				m_vStates.push_back(state);
				CreateLexemSub(arg1,state1,state);
				jump = new CJump();
				jump->m_bE=true;
				jump->m_pFrom=state;
				jump->m_pTo=right;
				m_vJumps.push_back(jump);
				state1 = state;
			}
			break;
		}
	}else
	{
		switch(c)
		{
		case '=':
			state = new CState();
			m_vStates.push_back(state);
			jump = new CJump();
			jump->m_bE=true;
			jump->m_pFrom=left;
			jump->m_pTo=state;
			m_vJumps.push_back(jump);
			jump = new CJump();
			jump->m_bE=true;
			jump->m_pFrom=state;
			jump->m_pTo=right;
			m_vJumps.push_back(jump);
			break;
		case '#':
			jump = new CJump();
			jump->m_bE=false;
			jump->m_cChar=atoi(desc.c_str());
			jump->m_pFrom=left;
			jump->m_pTo=right;
			m_vJumps.push_back(jump);
			break;
		case '$':
			jump = new CJump();
			jump->m_bE=false;
			jump->m_cChar=desc[0];
			jump->m_pFrom=left;
			jump->m_pTo=right;
			m_vJumps.push_back(jump);
			break;
		case '.':
			DeScob(desc,arg1);
			state = new CState();
			m_vStates.push_back(state);
			CreateLexemSub(arg1,left,state);
	
			DeScob(desc,arg2);
			while(!desc.empty())
			{
				state1 = new CState();
				m_vStates.push_back(state1);
				CreateLexemSub(arg2,state,state1);
				state=state1;
				DeScob(desc,arg2);
			}
			if (!arg2.empty())
				CreateLexemSub(arg2,state,right);
			else
			{
				jump = new CJump();
				jump->m_bE=true;
				jump->m_pFrom=state;
				jump->m_pTo=right;
				m_vJumps.push_back(jump);
			}
			break;
		case '|':
			DeScob(desc,arg1);
			DeScob(desc,arg2);
			CreateLexemSub(arg1,left,right);
			CreateLexemSub(arg2,left,right);
			while(!desc.empty())
			{
				DeScob(desc,arg2);
				CreateLexemSub(arg2,left,right);
			}
			break;
		case '?':
			DeScob(desc,arg1);
			CreateLexemSub(arg1,left,right);
			jump = new CJump();
			jump->m_bE=true;
			jump->m_pFrom=left;
			jump->m_pTo=right;
			m_vJumps.push_back(jump);
			break;
		case '+':
			DeScob(desc,arg1);
			CreateLexemSub(arg1,left,right);
			CreateLexemSub(arg1,right,right);
			break;
		case '*':
			DeScob(desc,arg1);
			CreateLexemSub(arg1,left,left);
			jump = new CJump();
			jump->m_bE=true;
			jump->m_pFrom=left;
			jump->m_pTo=right;
			m_vJumps.push_back(jump);
			break;
		}
	}
}

void CStateMachine::DeScob(std::string &s,std::string& out)
{
	int i;
	CLevelMachine l;
	if (s.empty()) 
	{ 
		out="";
		return;
	}
	s=s.substr(s.find_first_of("("));
	s.erase(0,1);
	for(i=0;i<s.length();i++)
	{
		l.Put(s[i]);
		if (l.m_iLevel<0)
		{
			out=s.substr(0,i);
			s.erase(0,i+1);
			break;
		}
	}
}

void CStateMachine::DeleteEJumps()
{
	std::vector<CJump*>::iterator beg,end,it,jt;
	std::vector<CJump*> vAddJumps;
	beg=m_vJumps.begin();
	end=m_vJumps.end();
	for(it=beg;it!=end;it++)
	{
		CJump *j=(*it);
		if ((j->m_bE)&&(j->m_pTo->m_bEnd)&&(!j->m_pFrom->m_bEnd))
		{
			j->m_pFrom->m_bEnd=true;
			it=beg;
		}
	}
	for(it=beg;it!=end;it++)
	{
		CJump *j=(*it);
		if (j->m_bE)
		{
			CState *s=j->m_pTo;
			vAddJumps.clear();
			for(jt=beg;jt!=end;jt++)
			{
				CJump *j2=(*jt);
				if (j2->m_pFrom==s)
				{
					CJump *j3=new CJump;
					j3->m_bE=j2->m_bE;
					j3->m_cChar=j2->m_cChar;
					j3->m_pTo=j2->m_pTo;
					j3->m_pFrom=j->m_pFrom;
					vAddJumps.push_back(j3);
				}
			}
			delete j;
			m_vJumps.erase(it);
			m_vJumps.insert(m_vJumps.begin(),vAddJumps.begin(),vAddJumps.end());
			vAddJumps.clear();
			beg=m_vJumps.begin();
			end=m_vJumps.end();
			it=beg;
		}
	}
}

void CStateMachine::OptimizeStates()
{
	std::vector<CState*>::iterator beg,end,it;
	std::vector<CJump*>::iterator jbeg,jend,jt;
	jbeg=m_vJumps.begin();
	jend=m_vJumps.end();
	beg=m_vStates.begin();
	end=m_vStates.end();
	for(it=beg;it!=end;it++)
	{
		CState *s=(*it);
		bool was=false;
		for(jt=jbeg;jt!=jend;jt++)
		{
			CJump *j=(*jt);
			if ((j->m_pFrom==s)||(j->m_pTo==s))
				was=true;
		}
		if (!was)
		{
			delete s;
			m_vStates.erase(it);
			beg=m_vStates.begin();
			end=m_vStates.end();
			it=beg;
		}
	}
}

void CStateMachine::CheckDeterminate() throw(CPeterCompiler::CUndeterminateException)
{
	std::vector<CJump*>::iterator jbeg,jend,jt,j1;
	jbeg=m_vJumps.begin();
	jend=m_vJumps.end();
	for(jt=jbeg;jt!=jend;jt++)
	{
		j1=jt;
		for(j1++;j1!=jend;j1++)
		{
			CJump *jc,*jm;
			jc=(*jt); 
			jm=(*j1);
			if ((jc->m_cChar==jm->m_cChar)&&
				(jc->m_pFrom==jm->m_pFrom)&&
				(jc->m_pTo!=jm->m_pTo))
				throw CPeterCompiler::CUndeterminateException("LEXEM-FILE",m_sLexem_name,jm->m_cChar);
		}
	}
}

void CStateMachine::CreateStateData()
{
	int cur_state=0,i;
	std::vector<CState*>::iterator beg,end,it;
	std::vector<CJump*>::iterator jbeg,jend,jt;
	jbeg=m_vJumps.begin();
	jend=m_vJumps.end();
	beg=m_vStates.begin();
	end=m_vStates.end();
	for(it=beg;it!=end;it++,cur_state++)
	{
		CState *s=(*it);
		s->m_iState=cur_state;
		s->m_bOk=true;
	}
	m_iNumStates=cur_state;
	m_pStateData = new int[m_iNumStates*256];
	m_pStateEnd = new bool[m_iNumStates];
	for(i=0;i<m_iNumStates*256;i++)
		m_pStateData[i]=-1;
	for(i=0;i<m_iNumStates;i++)
		m_pStateEnd[i]=false;
	for(jt=jbeg;jt!=jend;jt++)
	{
		CJump *j=(*jt);
		if (!j->m_bE)
			m_pStateData[j->m_pFrom->m_iState\
			*256+static_cast<unsigned char>\
			(j->m_cChar)]=j->m_pTo->m_iState;
	}
	for(it=beg;it!=end;it++)
	{
		CState *s=(*it);
		m_pStateEnd[s->m_iState]=s->m_bEnd;
	}
}

void CStateMachine::DeleteExtraData()
{
	std::vector<CState*>::iterator beg,end,it;
	std::vector<CJump*>::iterator jbeg,jend,jt;
	jbeg=m_vJumps.begin();
	jend=m_vJumps.end();
	beg=m_vStates.begin();
	end=m_vStates.end();
	for(it=beg;it!=end;it++)
		delete (*it);
	m_vStates.clear();
	for(jt=jbeg;jt!=jend;jt++)
		delete (*jt);
	m_vJumps.clear();
}

void CStateMachine::DumpStates(std::string file_name)
{
	std::ofstream sFile(file_name.c_str());
	std::vector<CState*>::iterator beg,end,i;
	beg=m_vStates.begin();
	end=m_vStates.end();
	for(i=beg;i!=end;i++)
	{
		CState* s=(*i);
		sFile<<"ID: "<<s->m_iState;
		sFile<<"\tOk: "<<s->m_bOk;
		sFile<<"\tEnd: "<<s->m_bEnd<<std::endl;
	}
	sFile.close();
}

void CStateMachine::DumpJumps(std::string file_name)
{
	std::ofstream sFile(file_name.c_str());
	std::vector<CJump*>::iterator beg,end,i;
	beg=m_vJumps.begin();
	end=m_vJumps.end();
	for(i=beg;i!=end;i++)
	{
		CJump* s=(*i);
		sFile<<"Char: "<<s->m_cChar;
		sFile<<"\tE: "<<s->m_bE;
		sFile<<"\tID1: "<<s->m_pFrom->m_iState;
		sFile<<"\tID2: "<<s->m_pTo->m_iState;
		sFile<<"\tChar_code: "<<static_cast<unsigned char>(s->m_cChar);
		sFile<<std::endl;
	}
	sFile.close();
}

void CStateMachine::Prepare()
{
	if (m_iOption&LEX_OPTION_LINE_TERMINATOR)
		return;	
	m_iState = 0;
	m_bError = false;
	if (m_iOption&LEX_OPTION_DISABLED)
		m_bError = true;
}

void CStateMachine::Prepare_LineTerminator()
{
	if (m_iOption&LEX_OPTION_LINE_TERMINATOR)
	{
		m_iState = 0;
		m_bError = false;
		if (m_iOption&LEX_OPTION_DISABLED)
			m_bError = true;
	}
}

bool CStateMachine::Scan(char c)
{
	if (m_iOption&LEX_OPTION_LINE_TERMINATOR)
		return false;
	if (m_bError) return false;
	if (m_pStateData[m_iState*256+\
		static_cast<unsigned char>(c)]!=-1)
	{
		m_iState = m_pStateData[m_iState*256+\
		static_cast<unsigned char>(c)];
		return true;
	}else
	{
		m_bError=true;
		return false;
	}
}

bool CStateMachine::Scan_LineTerminator(char c)
{
	if (m_iOption&LEX_OPTION_LINE_TERMINATOR)
	{
		if (m_bError) return false;
		if (m_pStateData[m_iState*256+\
			static_cast<unsigned char>(c)]!=-1)
		{
			m_iState = m_pStateData[m_iState*256+\
			static_cast<unsigned char>(c)];
			return true;
		}else
		{
			m_bError=true;
			return false;
		}
	}else
		return false;
}

bool CStateMachine::IsEndState()
{
	if (m_bError) return false;
	return m_pStateEnd[m_iState];
}

void CStateMachine::Save(std::ofstream &out)
{
	out<<m_sLexem_name<<" ";
	out<<m_iNameID<<" ";
	out<<m_iNumStates<<" ";
	long i;
	for(i=0;i<(m_iNumStates*256);i++)
		out<<m_pStateData[i]<<" ";
	for(i=0;i<m_iNumStates;i++)
		out<<m_pStateEnd[i]<<" ";
	out<<m_iOption<<" ";
	out<<std::endl;
}

void CStateMachine::Load(std::ifstream &in)
{
	std::vector<CState*>::iterator beg,end,it;
	std::vector<CJump*>::iterator jbeg,jend,jt;
	jbeg=m_vJumps.begin();
	jend=m_vJumps.end();
	beg=m_vStates.begin();
	end=m_vStates.end();
	for(it=beg;it!=end;it++)
		delete (*it);
	m_vStates.clear();
	for(jt=jbeg;jt!=jend;jt++)
		delete (*jt);
	m_vJumps.clear();
	if (m_pStateData)
		delete[m_iNumStates*256] m_pStateData;
	if (m_pStateEnd)
		delete[m_iNumStates] m_pStateEnd;	
	
	in>>m_sLexem_name;
	in>>m_iNameID;
	in>>m_iNumStates;
	m_pStateData = new int[m_iNumStates*256];
	m_pStateEnd = new bool[m_iNumStates];
	long i;
	for(i=0;i<(m_iNumStates*256);i++)
		in>>m_pStateData[i];
	for(i=0;i<m_iNumStates;i++)
		in>>m_pStateEnd[i];
	in>>m_iOption;
	m_bError=false;
	m_iState=0;
}

__PETER_COMPILER_END
		