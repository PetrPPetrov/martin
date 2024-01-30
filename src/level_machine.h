// LevelMachine.h: interface for the CLevelMachine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEVELMACHINE_H__18C03553_A80B_4295_884C_CD2029537443__INCLUDED_)
#define AFX_LEVELMACHINE_H__18C03553_A80B_4295_884C_CD2029537443__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN
	
class CLevelMachine  
{
public:
	CLevelMachine();
	CLevelMachine(int);
	virtual ~CLevelMachine();

	void Put(char);

	int m_iLevel;

};	

__PETER_COMPILER_END

#endif // !defined(AFX_LEVELMACHINE_H__18C03553_A80B_4295_884C_CD2029537443__INCLUDED_)
