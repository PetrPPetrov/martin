//////////////////////////////////////////////////
//
// Проект: библиотека классов С++ для создания 
// трансляторов
//
// Имя: PeterCompiler
//
// Автор: Петров Петя 
//
//
// 
// Модуль: Syntax
// Назначение: Синтаксический анализ цепочки лексем
//
//
// Дата начала проекта: 06.11.2002
// Дата последней модификации: 27.03.2003
//
//////////////////////////////////////////////////
// Syntax.h: interface for the CSyntax class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYNTAX_H__E72CB980_78B0_4E10_B1DB_12CB88BBD148__INCLUDED_)
#define AFX_SYNTAX_H__E72CB980_78B0_4E10_B1DB_12CB88BBD148__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

void GetVersion(int&,int&,int&);

#define SYN_OPTION_EXCLUDE	2
#define SYN_OPTION_DISABLED	1
#define SYN_OPTION_NONE		0

int ParseSynOption(std::string&,std::string&);

class CSyntax  
{
public:
	CSyntax(CScanner&);
	virtual ~CSyntax();

	void CreateLL1(std::string);
	void Syntax() throw(CPeterCompiler::CSyntaxException);
	void Translate(CCompiler*,std::string);
	void Compile(CCompiler*,std::string);

	void Add(std::string,std::string,int,std::string);
	void EndInitialization();

	void Save(std::string);
	void Load(std::string);

protected:
	void AddRule(std::string,std::string,int,std::string);
	void LoadSyntax(std::string);
	void NumUnterminals();
	int  GetID(std::string) throw(CPeterCompiler::CLexemNotFoundException);
	void DeScob(std::string&,std::string&);
	void MakeNumbers();
	void First1Sub(int,std::vector<int>&,std::set<int>&,bool);
	void First1(int,std::vector<int>&,std::set<int>&,bool);
	void PrepareForFirst();
	void PrepareForFollow();
	void Follow1(int,std::set<int>&);
	void Follow1Sub1(int,CUnterminal*,std::set<int>&);
	void Follow1Sub2(int,std::set<int>&);
	void CheckMain() throw(CPeterCompiler::CMainNotFoundException);
	void GenerateFirst_and_Follow();
	void CreateTableM() throw(CPeterCompiler::CNotLL1Exception);
	bool IsLexem(int n) { return n<=m_iNumLexems; };
	void DumpFirsts(std::string);
	void GetName(int,std::string&);
	void CreateTree();
	void CreateTreeSub(CTree*);
	void DumpTree(std::string);
	void DumpTreeSub(CTree*,std::string&,std::ofstream&);
				
private:
	CScanner &m_scScanner;
	std::vector<CUnterminal*> m_vUnterminals;
	std::vector<CEvent*> m_vEvents;
	std::stack<int> m_stack;
	int m_iNumUnterminals;
	int m_iNumRules;
	int m_iNumLexems;
	int m_iMain;
	CTableMItem *m_pTableM;
	std::vector<CEvent*>::iterator m_itEv;
public:
	CTree *m_pRoot;
};

__PETER_COMPILER_END

#endif // !defined(AFX_SYNTAX_H__E72CB980_78B0_4E10_B1DB_12CB88BBD148__INCLUDED_)
