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
// Модуль: Compiler
// Назначение: Семантический анализ 
//     и последующая трансляция
//
//
// Дата начала проекта: 06.11.2002
// Дата последней модификации: 27.03.2003
//
//////////////////////////////////////////////////
// Compiler.h: interface for the CCompiler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPILER_H__C1B15580_FFBB_11D6_A1C2_CBA2EFABE888__INCLUDED_)
#define AFX_COMPILER_H__C1B15580_FFBB_11D6_A1C2_CBA2EFABE888__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

class CCompiler  
{
public:
	CCompiler();
	virtual ~CCompiler();

	virtual void Analisys(CTree*) throw(CPeterCompiler::CSemanticException)=0;
	virtual void Translate(std::ofstream&,CTree*) throw(CPeterCompiler::CSemanticException)=0;
	virtual void Compile(std::ofstream&,CTree*) throw(CPeterCompiler::CSemanticException)=0;
	virtual void Clear()=0;
	virtual void PreTranslate()=0;
	virtual void PreCompile()=0;

protected:
	void AddKey(std::string,std::string,std::string,int=0);
	bool IsKey(std::string,std::string,int=0);
	std::string GetKey(std::string,std::string,int=0);
	void DeleteTag(std::string,int);
	void DeleteTag(std::string);
	void DeleteKey(std::string,std::string,int);
	void DeleteKey(std::string,std::string);
	void DeleteAll();
private:
	std::set<CKey,Key_less> m_stTable;
			
};

__PETER_COMPILER_END

#endif // !defined(AFX_COMPILER_H__C1B15580_FFBB_11D6_A1C2_CBA2EFABE888__INCLUDED_)
