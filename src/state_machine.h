// StateMachine.h: interface for the CStateMachine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATEMACHINE_H__DB611904_16EE_440E_9197_189953F5C7E9__INCLUDED_)
#define AFX_STATEMACHINE_H__DB611904_16EE_440E_9197_189953F5C7E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

class CStateMachineSet;
	
class CStateMachine  
{
public:
	CStateMachine();
	CStateMachine(int,std::string,std::string,int);
	virtual ~CStateMachine();

	void CreateLexem();
	void Prepare();
	void Prepare_LineTerminator();
	bool Scan(char);
	bool Scan_LineTerminator(char);
	bool IsEndState();
	void Save(std::ofstream&);
	void Load(std::ifstream&);
protected:
	void CreateLexemSub(std::string,CState*,CState*);
	void DeleteEJumps();
	void OptimizeStates();
	void CheckDeterminate() throw(CPeterCompiler::CUndeterminateException);
	void CreateStateData();
	void DeleteExtraData();
	void DeScob(std::string&,std::string&);
public:
	void DumpStates(std::string);
	void DumpJumps(std::string);

	friend std::ifstream& operator>>(std::ifstream& sFile,CStateMachineSet&);
	friend class CStateMachineSet;

private:
	std::vector<CState*> m_vStates;
	std::vector<CJump*> m_vJumps;
	std::string m_sLexem_name;
	std::string m_sLexem_description;
	int *m_pStateData;
	int m_iNumStates;
	bool *m_pStateEnd;
	bool m_bError;
	int m_iState;
	int m_iNameID;
	int m_iOption;
};

__PETER_COMPILER_END

#endif // !defined(AFX_STATEMACHINE_H__DB611904_16EE_440E_9197_189953F5C7E9__INCLUDED_)
