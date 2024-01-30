// Syntax.cpp: implementation of the CSyntax class.
//
//////////////////////////////////////////////////////////////////////

#include "PeterCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__PETER_COMPILER_BEGIN

CSyntax::CSyntax(CScanner &sc):
m_iNumUnterminals(0),m_iNumRules(0),m_pTableM(NULL),
m_iMain(-1),m_scScanner(sc),m_pRoot(NULL)
{
	m_vUnterminals.clear();
	m_vEvents.clear();
}

CSyntax::~CSyntax()
{
	std::vector<CUnterminal*>::iterator beg,end,i;
	std::vector<CEvent*>::iterator b,e,j;
	beg=m_vUnterminals.begin();
	end=m_vUnterminals.end();
	for(i=beg;i!=end;i++)
		delete (*i);
	m_vUnterminals.clear();	
	b=m_vEvents.begin();
	e=m_vEvents.end();
	for(j=b;j!=e;j++)
		delete (*j);
	m_vEvents.clear();
	if (m_pTableM)
		delete[(m_iNumUnterminals+m_iNumLexems+1)*(m_iNumLexems+1)] m_pTableM;
	if (m_pRoot)
		delete m_pRoot;
}

void CSyntax::CreateLL1(std::string filename)
{
	LoadSyntax(filename);
	NumUnterminals();
	MakeNumbers();
	CheckMain();
	GenerateFirst_and_Follow();
	CreateTableM();
}

void CSyntax::LoadSyntax(std::string filename)
{
	std::string str;
	std::string unt_name;
	std::string unt_desc;
	std::string sExclude;
	std::ifstream sFile(filename.c_str());
	int state=0x00;
	int option=SYN_OPTION_NONE;
	int i=1;
	while(sFile>>str)
	{
		switch(state)
		{
		case 0x00:
			unt_name=str;
			unt_name.erase(0,1);
			unt_desc="";
			state=0x01;
			option=ParseSynOption(unt_name,sExclude);
			break;
		case 0x01:
			if (str[0]==':')
			{
				Add(unt_name,unt_desc,option,sExclude);
				unt_name=str;
				unt_name.erase(0,1);
				unt_desc="";
				option=ParseSynOption(unt_name,sExclude);
			}else
			{
				unt_desc=unt_desc+str;
			}
			break;
		}
	}
	Add(unt_name,unt_desc,option,sExclude);
	sFile.close();
}

void CSyntax::AddRule(std::string _name,std::string _desc,int _option,std::string _exclude)
{
	CUnterminal *unterminal=new CUnterminal();
	unterminal->m_sName=_name;
	unterminal->m_sDesc=_desc;
	unterminal->m_iOption=_option;
	unterminal->m_sExclude=_exclude;
	m_vUnterminals.push_back(unterminal);
}

void CSyntax::NumUnterminals()
{
	std::vector<CUnterminal*>::iterator beg,end,i,j;
	beg=m_vUnterminals.begin();
	end=m_vUnterminals.end();
	int c,cun=0;
	m_iNumLexems=m_scScanner.m_smsSet.GetNumStateMachines();
	c=m_iNumLexems+1;

	for(i=beg;i!=end;i++)
	{
		CUnterminal *unt=(*i); 
		std::string cur=unt->m_sName;
		bool was=false;
		int old;
		for(j=beg;j!=i;j++)
			if ((*j)->m_sName==cur)
			{
				was=true;
				old=(*j)->m_iUnterminal;
			}
		if (!was)
		{
			unt->m_iUnterminal=c++;
			cun++;
		}else
			unt->m_iUnterminal=old;
	}
	m_iNumUnterminals=cun;
	c=1;
	for(i=beg;i!=end;i++)
		(*i)->m_iRule=c++;
	m_iNumRules=c-1;
}

int  CSyntax::GetID(std::string str)
{
	if (m_scScanner.m_smsSet.IsLexem(str))
		return m_scScanner.m_smsSet.GetID(str);
	else
	{
		std::vector<CUnterminal*>::iterator beg,end,i;
		beg=m_vUnterminals.begin();
		end=m_vUnterminals.end();	
		for(i=beg;i!=end;i++)
		{
			CUnterminal *unt=(*i); 
			if (unt->m_sName==str)
				return unt->m_iUnterminal;
		}
	}
	throw CPeterCompiler::CLexemNotFoundException(str);
}

void CSyntax::DeScob(std::string &s,std::string& out)
{
	int i;
	CLevelMachine l;
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

void CSyntax::MakeNumbers()
{
	std::vector<CUnterminal*>::iterator beg,end,i;
	beg=m_vUnterminals.begin();
	end=m_vUnterminals.end();
	for(i=beg;i!=end;i++)
	{
		CUnterminal *unt=(*i); 
		std::string str=unt->m_sDesc;
		std::string arg;
		while(!str.empty())
		{	
			DeScob(str,arg);
			int code=GetID(arg);
			unt->m_vDesc.push_back(code);
		}
	}
}

void CSyntax::First1Sub(int irule,std::vector<int> &vDesc,std::set<int> &res,bool rule_num)
{
	std::vector<CUnterminal*>::iterator ubeg,uend,ui;
	std::vector<int> *Desc;
	CUnterminal *unt;

	if (rule_num)
	{
		unt=m_vUnterminals[irule-1];
		Desc=&unt->m_vDesc;
	}
	else
		Desc=&vDesc;
	if (rule_num)
		if (unt->m_bGenerated) return;

	if (Desc->empty())
	{
		res.insert(0);
		return;
	}
		
	std::vector<int>::iterator beg,end,i;
	beg=Desc->begin();
	end=Desc->end();
	i=beg;
	int first=(*i);
	if (IsLexem(first)) 
	{
		res.insert(first);
		return;
	}
	if (rule_num)
		unt->m_bGenerated=true;
	std::set<int> local_res;
	std::set<int> null;
	std::set<int>::iterator sb,se,si;
	int inull=0;
	bool null_was;
	null.insert(0);
	do{
		first=(*i);
		null_was=false;
		local_res.clear();
		ubeg=m_vUnterminals.begin();
		uend=m_vUnterminals.end();
		if (IsLexem(first)) 
			local_res.insert(first);
		else				
		for(ui=ubeg;ui!=uend;ui++)
		{
			unt=(*ui);
			if (unt->m_iUnterminal==first)
				First1Sub(unt->m_iRule,*Desc,local_res,true);
		}
		sb=local_res.begin();
		se=local_res.end();
		si=local_res.find(inull);
		null_was=si!=se;
		if (null_was)
			local_res.erase(0);
		sb=local_res.begin();
		se=local_res.end();
		for(si=sb;si!=se;si++)
			res.insert((*si));
		i++;
		if (i==end)
		{
			if (null_was) res.insert(0);
			null_was=false;
		}
	}while(null_was);
}

void CSyntax::PrepareForFirst()
{
	std::vector<CUnterminal*>::iterator ubeg,uend,ui;
	ubeg=m_vUnterminals.begin();
	uend=m_vUnterminals.end();
	for(ui=ubeg;ui!=uend;ui++)
		(*ui)->m_bGenerated=false;
}

void CSyntax::PrepareForFollow()
{
	std::vector<CUnterminal*>::iterator ubeg,uend,ui;
	ubeg=m_vUnterminals.begin();
	uend=m_vUnterminals.end();
	for(ui=ubeg;ui!=uend;ui++)
		(*ui)->m_bGenerated_follow=false;
}

void CSyntax::First1(int irule,std::vector<int> &Desc,std::set<int> &res,bool rule_num)
{
	res.clear();
	PrepareForFirst();
	First1Sub(irule,Desc,res,rule_num);
}

void CSyntax::Follow1(int iunt,std::set<int> &res)
{
	res.clear();
	PrepareForFollow();
	Follow1Sub2(iunt,res);
}

void CSyntax::Follow1Sub1(int iunt,CUnterminal *root,std::set<int> &res)
{
	int iparent;
	int inull=0;
	std::vector<int> &desc=root->m_vDesc;
	std::vector<int>::iterator b,e,i,j;
	std::vector<int> ost;
	std::set<int> first;
	std::set<int>::iterator sb,se,si;
	bool was_e;
	iparent=root->m_iUnterminal;
	b=desc.begin();
	e=desc.end();
	for(i=b;i!=e;i++)
	{
		if ((*i)==iunt)
		{
			ost.clear();
			j=i;
			j++;
			for(;j!=e;j++)
				ost.push_back(*j);
				
			first.clear();
			was_e=false;
			First1(0,ost,first,false);
			sb=first.begin();
			se=first.end();
			si=first.find(inull);
			was_e=si!=se;
			if (was_e) first.erase(0);
			sb=first.begin();
			se=first.end();
			for(si=sb;si!=se;si++)
				res.insert(*si);
			if (was_e)
				Follow1Sub2(iparent,res);
		}
	}
}

void CSyntax::Follow1Sub2(int iunt,std::set<int> &res)
{
	std::vector<int>::iterator b,e,i;
	std::vector<CUnterminal*>::iterator ub,ue,ui;
	CUnterminal* unt;
	bool was=false;
	if (iunt==m_iMain) 
	{
		res.insert(0);
		return;
	}
	ub=m_vUnterminals.begin();
	ue=m_vUnterminals.end();
	for(ui=ub;ui!=ue;ui++)
	{
		unt=(*ui);
		if ((unt->m_iUnterminal==iunt)&&(unt->m_bGenerated_follow))
			was=true;
	}
	for(ui=ub;ui!=ue;ui++)
	{
		unt=(*ui);
		if (unt->m_iUnterminal==iunt) 
			unt->m_bGenerated_follow=true;
	}
	if (was) return;
	ub=m_vUnterminals.begin();
	ue=m_vUnterminals.end();
	for(ui=ub;ui!=ue;ui++)
	{
		unt=(*ui);
		was=false;
		b=unt->m_vDesc.begin();
		e=unt->m_vDesc.end();
		for(i=b;i!=e;i++)
			if ((*i)==iunt) was=true;		
		if (was) 
			Follow1Sub1(iunt,unt,res);
	}
}

void CSyntax::CheckMain() throw(CPeterCompiler::CMainNotFoundException)
{
	std::vector<CUnterminal*>::iterator ubeg,uend,ui;
	int c=0;
	ubeg=m_vUnterminals.begin();
	uend=m_vUnterminals.end();
	for(ui=ubeg;ui!=uend;ui++)
		if ((*ui)->m_sName=="main")
		{
			c++;
			m_iMain=(*ui)->m_iUnterminal;
		}
	if (c!=1) throw CPeterCompiler::CMainNotFoundException();
	m_stack.push(m_iMain);
}

void CSyntax::GenerateFirst_and_Follow()
{
	std::vector<CUnterminal*>::iterator ubeg,uend,ui;
	std::set<int>::iterator ub,ue,u1b,u1e,i1,i2;
	CUnterminal *unt;
	std::set<int> temp;
	temp.clear();
	ubeg=m_vUnterminals.begin();
	uend=m_vUnterminals.end();
	for(ui=ubeg;ui!=uend;ui++)
	{
		unt=(*ui);
		First1(unt->m_iRule,unt->m_vDesc,unt->m_stFirst,true);
		Follow1(unt->m_iUnterminal,unt->m_stFollow);
		if (unt->m_iOption&SYN_OPTION_EXCLUDE)
		{
			int iExclude;
			iExclude=GetID(unt->m_sExclude);
			unt->m_stFirst.erase(iExclude);
			unt->m_stFollow.erase(iExclude);
		}
	}
	
#if defined(_DEBUG)
	DumpFirsts("fr1_fw1");
#endif
}

void CSyntax::CreateTableM() throw(CPeterCompiler::CNotLL1Exception)
{
	m_pTableM = new CTableMItem[(m_iNumUnterminals+m_iNumLexems+1)*(m_iNumLexems+1)];
	std::vector<CUnterminal*>::iterator ubeg,uend,ui;
	std::set<int>::iterator ub,ue,i;
	std::string name;
	CUnterminal *unt;
	bool was_e;
	ubeg=m_vUnterminals.begin();
	uend=m_vUnterminals.end();
	for(ui=ubeg;ui!=uend;ui++)
	{
		unt=(*ui);
		ub=unt->m_stFirst.begin();
		ue=unt->m_stFirst.end();
		was_e=false;
		for(i=ub;i!=ue;i++)
		{
			int f=(*i);
			if (f==0)
				was_e=true;
			else
			{
				GetName(f,name);
				if (m_pTableM[unt->m_iUnterminal*(m_iNumLexems+1)+f].m_iItem_type!=TABLE_M_ERROR)
					throw CPeterCompiler::CNotLL1Exception(unt->m_sName,unt->m_sDesc,unt->m_sName,m_vUnterminals[m_pTableM[unt->m_iUnterminal*(m_iNumLexems+1)+f].m_iRule-1]->m_sDesc,name);
				m_pTableM[unt->m_iUnterminal*(m_iNumLexems+1)+f].m_iItem_type=TABLE_M_PUSH;
				m_pTableM[unt->m_iUnterminal*(m_iNumLexems+1)+f].m_iRule=unt->m_iRule;
			}
		}
		if (was_e)
		{
			ub=unt->m_stFollow.begin();
			ue=unt->m_stFollow.end();
			for(i=ub;i!=ue;i++)
			{
				int f=(*i);
				GetName(f,name);
				if (m_pTableM[unt->m_iUnterminal*(m_iNumLexems+1)+f].m_iItem_type!=TABLE_M_ERROR)
					throw CPeterCompiler::CNotLL1Exception(unt->m_sName+".follow",unt->m_sDesc,unt->m_sName,m_vUnterminals[m_pTableM[unt->m_iUnterminal*(m_iNumLexems+1)+f].m_iRule-1]->m_sDesc,name);
				m_pTableM[unt->m_iUnterminal*(m_iNumLexems+1)+f].m_iItem_type=TABLE_M_PUSH;
				m_pTableM[unt->m_iUnterminal*(m_iNumLexems+1)+f].m_iRule=unt->m_iRule;
			}
		}
	}
	for(int a=1;a<=m_iNumLexems;a++)
		m_pTableM[a*(m_iNumLexems+1)+a].m_iItem_type=TABLE_M_EJECT;
}

void CSyntax::Syntax() throw(CPeterCompiler::CSyntaxException)
{
	std::vector<CEvent*>::iterator b,e,j;
	CResultLexem lex;
	CTableMItem item;
	CUnterminal *unt;
	CEvent *ev;
	std::string s;
	if (m_pRoot)
		delete m_pRoot;
	m_scScanner.m_rlsSet.Prepare();
	std::vector<int>::reverse_iterator beg,end,i;

	m_scScanner.m_rlsSet.GetNextLexem(lex,false);
	while(lex.m_iNameID||(!m_stack.empty()))
	{
		m_scScanner.m_rlsSet.GetNextLexem(lex,false);
		int poper;
		if (m_stack.empty())
			throw CPeterCompiler::CSyntaxException(m_scScanner.m_sFile_source,lex.m_lLine,lex.m_sLexem_value,lex.m_sLexem_name,"program always ended");
		poper=m_stack.top();
#if defined (_TRACE_PETER_COMPILER_)
		std::string tmp_name_trace;
		GetName(poper,tmp_name_trace);
//		std::cout<<" \tSTACK:\t"+tmp_name_trace<<std::endl;
#endif
		item=m_pTableM[poper*(m_iNumLexems+1)+lex.m_iNameID];
		switch(item.m_iItem_type)
		{
		case TABLE_M_PUSH:
			m_stack.pop();
			unt=m_vUnterminals[item.m_iRule-1];
			beg=unt->m_vDesc.rbegin();
			end=unt->m_vDesc.rend();
			for(i=beg;i!=end;i++)
			{
				int code=(*i);
				m_stack.push(code);
			}
			ev=new CEvent(poper);
			ev->m_iRule=item.m_iRule;
			ev->m_sType_name=unt->m_sName;
			ev->m_sFile_source=lex.m_sFile_source;
			ev->m_lLine=lex.m_lLine;
			m_vEvents.push_back(ev);
#if defined (_TRACE_PETER_COMPILER_)
			std::cout<<"PUSH:\t"+unt->m_sName+"->"+unt->m_sDesc<<std::endl;
#endif
			break;
		case TABLE_M_EJECT:
			m_stack.pop();
			ev=new CEvent(poper);
			ev->m_sType_name=lex.m_sLexem_name;
			ev->m_sLexem_value=lex.m_sLexem_value;
			ev->m_sFile_source=lex.m_sFile_source;
			ev->m_lLine=lex.m_lLine;
			m_vEvents.push_back(ev);
#if defined (_TRACE_PETER_COMPILER_)
			std::cout<<"EJECT:\t"+lex.m_sLexem_name+":"+lex.m_sLexem_value<<std::endl;
#endif
			m_scScanner.m_rlsSet.GetNextLexem(lex,true);
			m_scScanner.m_rlsSet.GetNextLexem(lex,false);
			break;
		case TABLE_M_ERROR:
			GetName(m_stack.top(),s);
			throw CPeterCompiler::CSyntaxException(m_scScanner.m_sFile_source,lex.m_lLine,lex.m_sLexem_value,lex.m_sLexem_name,s);
			break;
		}
	}
	if (!m_stack.empty())
		throw CPeterCompiler::CSyntaxException(m_scScanner.m_sFile_source,lex.m_lLine,lex.m_sLexem_value,lex.m_sLexem_name,"program end expected");
	CreateTree();
	b=m_vEvents.begin();
	e=m_vEvents.end();
	for(j=b;j!=e;j++)
		delete (*j);
	m_vEvents.clear();
#if defined(_DEBUG)
	DumpTree("tree");
#endif
}

void CSyntax::DumpFirsts(std::string file_name)
{
	std::ofstream sFile(file_name.c_str());
	std::vector<CUnterminal*>::iterator beg,end,i;
	beg=m_vUnterminals.begin();
	end=m_vUnterminals.end();
	for(i=beg;i!=end;i++)
	{
		CUnterminal *unt=(*i);
		sFile<<"==RULE=============="<<std::endl;
		sFile<<"\t"<<unt->m_sName<<"\t: "<<unt->m_iUnterminal<<std::endl;
		sFile<<"\t"<<unt->m_sDesc<<"\t: "<<unt->m_iRule<<std::endl;
		if (unt->m_iOption&SYN_OPTION_EXCLUDE)
			sFile<<"\t"<<"SYN_OPTION_EXCLUDE:"<<unt->m_sExclude<<std::endl;
		sFile<<"\t"<<"--FIRST-------------"<<std::endl;
		std::set<int>::iterator ib,ie,j;
		ib=unt->m_stFirst.begin();
		ie=unt->m_stFirst.end();
		for(j=ib;j!=ie;j++)
		{
			std::string s;
			GetName((*j),s);
			if (*j==0) s="**E-symbol**";
			sFile<<"\t\t"<<s<<std::endl;
		}
		sFile<<"\t"<<"--FOLLOW------------"<<std::endl;
		ib=unt->m_stFollow.begin();
		ie=unt->m_stFollow.end();
		for(j=ib;j!=ie;j++)
		{
			std::string s;
			GetName((*j),s);
			if (*j==0) s="**E-symbol**";
			sFile<<"\t\t"<<s<<std::endl;
		}
	}
	sFile.close();
}

void CSyntax::DumpTree(std::string file_name)
{
	std::ofstream sFile(file_name.c_str());
	std::string a="";
	DumpTreeSub(m_pRoot,a,sFile);
	sFile.close();
}

void CSyntax::DumpTreeSub(CTree *root,std::string &tab,std::ofstream &sFile)
{
	std::vector<CTree*>::iterator b,e,i;
	std::string new_tab;
	sFile<<tab<<root->m_sType_name<<":"<<root->m_sFile_source<<":"<<root->m_lLine<<std::endl;
	new_tab=tab+"    ";
	if (IsLexem(root->m_iType))
		sFile<<new_tab<<"\""<<root->m_sLexem_value<<"\""<<std::endl;
	else
	{
		b=root->m_vComponents.begin();
		e=root->m_vComponents.end();
		for(i=b;i!=e;i++)
			DumpTreeSub((*i),new_tab,sFile);
	}
}

void CSyntax::GetName(int code,std::string &name)
{
	if (IsLexem(code)) m_scScanner.m_smsSet.GetName(code,name);	
		else
		{
			std::vector<CUnterminal*>::iterator beg,end,i;
			beg=m_vUnterminals.begin();
			end=m_vUnterminals.end();
			for(i=beg;i!=end;i++)
			{
				CUnterminal *unt=(*i); 
				if (unt->m_iUnterminal==code)
				{
					name=unt->m_sName;
					return;
				}
			}
		}
}

void CSyntax::CreateTree()
{
	m_pRoot = new CTree(GetID("main"));
	m_itEv=m_vEvents.begin();
	CreateTreeSub(m_pRoot);
}

void CSyntax::CreateTreeSub(CTree *root)
{
	CUnterminal *unt;
	CEvent *ev;
	CTree *sub_tree;
	std::vector<int>::iterator b,e,i;
	ev=(*m_itEv);
	root->m_iRule=ev->m_iRule;
	root->m_iType=ev->m_iType;
	root->m_sLexem_value=ev->m_sLexem_value;
	root->m_sType_name=ev->m_sType_name;
	root->m_lLine=ev->m_lLine;
	root->m_sFile_source=ev->m_sFile_source;
	if (IsLexem(root->m_iType))
		root->m_vComponents.clear();
	else
	{
		unt=m_vUnterminals[root->m_iRule-1];
		b=unt->m_vDesc.begin();
		e=unt->m_vDesc.end();
		for(i=b;i!=e;i++)
		{
			sub_tree = new CTree((*i));
			root->m_vComponents.push_back(sub_tree);
			m_itEv++;
			CreateTreeSub(sub_tree);
		}
	}
}

void CSyntax::Save(std::string file)
{
	std::ofstream out(file.c_str());
	out<<m_iNumRules<<" ";
	std::vector<CUnterminal*>::iterator b,e,i;
	CUnterminal* unt;
	b=m_vUnterminals.begin();
	e=m_vUnterminals.end();
	for(i=b;i!=e;i++)
	{
		unt=(*i);
		out<<std::endl;
		out<<unt->m_sName<<" ";

		if (unt->m_sDesc.empty())
			out<<"**E-symbol**"<<" ";
		else
			out<<unt->m_sDesc<<" ";

		out<<unt->m_iUnterminal<<" ";
		out<<unt->m_iRule<<" ";

		std::vector<int>::iterator bi,ei,ii;
		bi=unt->m_vDesc.begin();
		ei=unt->m_vDesc.end();
		out<<unt->m_vDesc.size()<<" ";
		for(ii=bi;ii!=ei;ii++)
			out<<(*ii)<<" ";

		std::set<int>::iterator bs,es,is;
		bs=unt->m_stFirst.begin();
		es=unt->m_stFirst.end();
		out<<unt->m_stFirst.size()<<" ";
		for(is=bs;is!=es;is++)
			out<<(*is)<<" ";

		bs=unt->m_stFollow.begin();
		es=unt->m_stFollow.end();
		out<<unt->m_stFollow.size()<<" ";
		for(is=bs;is!=es;is++)
			out<<(*is)<<" ";
	}
	out<<std::endl;
	out<<m_iNumUnterminals<<" ";
	out<<m_iNumLexems<<" ";
	out<<m_iMain<<" ";
	out<<std::endl;
	long j;
	for(j=0;j<((m_iNumUnterminals+m_iNumLexems+1)*(m_iNumLexems+1));j++)
	{
		out<<m_pTableM[j].m_iItem_type<<" ";
		out<<m_pTableM[j].m_iRule<<" ";
	}
	out.close();
}

void CSyntax::Load(std::string file)
{
	std::vector<CUnterminal*>::iterator beg,end,ix;
	std::vector<CEvent*>::iterator b,e,jx;
	beg=m_vUnterminals.begin();
	end=m_vUnterminals.end();
	for(ix=beg;ix!=end;ix++)
		delete (*ix);
	m_vUnterminals.clear();	
	b=m_vEvents.begin();
	e=m_vEvents.end();
	for(jx=b;jx!=e;jx++)
		delete (*jx);
	m_vEvents.clear();
	if (m_pTableM)
		delete[(m_iNumUnterminals+m_iNumLexems+1)*(m_iNumLexems+1)] m_pTableM;
	if (m_pRoot)
		delete m_pRoot;
	while(!m_stack.empty())
		m_stack.pop();
	//==== destruction end

	std::ifstream out(file.c_str());
	out>>m_iNumRules;
	int i,j,desc_max,first_max,follow_max,t;
	CUnterminal* unt;
	for(i=0;i<m_iNumRules;i++)
	{
		unt=new CUnterminal();
		m_vUnterminals.push_back(unt);
		out>>unt->m_sName;
		out>>unt->m_sDesc;
		out>>unt->m_iUnterminal;
		out>>unt->m_iRule;

		out>>desc_max;
		for(j=0;j<desc_max;j++)
		{
			out>>t;
			unt->m_vDesc.push_back(t);
		}

		out>>first_max;
		for(j=0;j<first_max;j++)
		{
			out>>t;
			unt->m_stFirst.insert(t);
		}

		out>>follow_max;
		for(j=0;j<follow_max;j++)
		{
			out>>t;
			unt->m_stFollow.insert(t);
		}
	}
	out>>m_iNumUnterminals;
	out>>m_iNumLexems;
	out>>m_iMain;

	m_pTableM = new CTableMItem[(m_iNumUnterminals+m_iNumLexems+1)*(m_iNumLexems+1)];
	for(j=0;j<((m_iNumUnterminals+m_iNumLexems+1)*(m_iNumLexems+1));j++)
	{
		out>>m_pTableM[j].m_iItem_type;
		out>>m_pTableM[j].m_iRule;
	}
	m_stack.push(m_iMain);
	out.close();
}

void CSyntax::Translate(CCompiler* _compiler,std::string _file)
{
	_compiler->Clear();
	_compiler->Analisys(m_pRoot);
	std::ofstream out(_file.c_str());
	_compiler->PreTranslate();
	_compiler->Translate(out,m_pRoot);	
	out.close();
}

void CSyntax::Compile(CCompiler* _compiler,std::string _file)
{
	_compiler->Clear();
	_compiler->Analisys(m_pRoot);
	std::ofstream out(_file.c_str(),std::ios::out|std::ios::binary);
	_compiler->PreCompile();
	_compiler->Compile(out,m_pRoot);	
	out.close();
}

void CSyntax::Add(std::string _name,std::string _desc,int _option,std::string _exclude)
{
	if (!(_option&SYN_OPTION_DISABLED))
		AddRule(_name,_desc,_option,_exclude);
}

void CSyntax::EndInitialization()
{
	NumUnterminals();
	MakeNumbers();
	CheckMain();
	GenerateFirst_and_Follow();
	CreateTableM();
}

void GetVersion(int &maj,int &min,int &bui)
{
	maj=03;
	min=03;
	bui=27;
}

int ParseSynOption(std::string &unt_name,std::string &sExclude)
{
	int option=SYN_OPTION_NONE;
	if (unt_name.size()==0) return option;
	while((unt_name[0]=='&')||(unt_name[0]=='!'))
	{
		switch(unt_name[0])
		{
		case '&':
			unt_name.erase(0,1);
			option|=SYN_OPTION_DISABLED;
			break;
		case '!':
			unt_name.erase(0,1);
			option|=SYN_OPTION_EXCLUDE;
			sExclude="";
			while(unt_name[0]!='!')
			{
				sExclude=sExclude+unt_name[0];
				unt_name.erase(0,1);
			}
			unt_name.erase(0,1);
			break;
		}
	}
	return option;
}

__PETER_COMPILER_END

		