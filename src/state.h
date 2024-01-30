// State.h: interface for the CState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATE_H__67A6EF61_69AF_4C30_BE41_B4C89F502726__INCLUDED_)
#define AFX_STATE_H__67A6EF61_69AF_4C30_BE41_B4C89F502726__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CState  
{
	CState();
	CState(int);
	virtual ~CState();

	int m_iState;
	bool m_bOk;
	bool m_bEnd;
	
};

__PETER_COMPILER_END

#endif // !defined(AFX_STATE_H__67A6EF61_69AF_4C30_BE41_B4C89F502726__INCLUDED_)
