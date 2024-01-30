// StateMachineSet.h: interface for the CStateMachineSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATEMACHINESET_H__29CEDC38_6EB8_477D_88F8_C5AF2FE6A0E7__INCLUDED_)
#define AFX_STATEMACHINESET_H__29CEDC38_6EB8_477D_88F8_C5AF2FE6A0E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

int ParseLexOption(std::string&);

class CStateMachineSet  
{
public:
	CStateMachineSet();
	virtual ~CStateMachineSet();

	void Prepare();
	void Prepare_LineTerminator();
	bool Scan(char,bool&);
	bool Scan_LineTerminator(char,bool&);
	void GetLastRightLexem(int&,std::string&,std::string&,int&);
	int GetNumStateMachines();

	bool IsLexem(std::string);
	int GetID(std::string) throw(CPeterCompiler::CLexemNotFoundException);
	void GetName(int,std::string&);

	void Save(std::ofstream&);
	void Load(std::ifstream&);

	friend std::ifstream& operator>>(std::ifstream& sFile,CStateMachineSet&);
	
	void AddLexem(int,std::string,std::string,int) throw(CPeterCompiler::CReferenceException);

private:
	std::vector<CStateMachine*> m_vStateMachines;
	std::vector<CStateMachine*>::iterator m_itLastRight;
	std::string m_sRightValue;
	bool m_bWasRight;

	std::vector<CStateMachine*>::iterator m_itLastRight_LineTerminator;
	bool m_bWasRight_LineTerminator;
	
};

__PETER_COMPILER_END

#endif // !defined(AFX_STATEMACHINESET_H__29CEDC38_6EB8_477D_88F8_C5AF2FE6A0E7__INCLUDED_)
