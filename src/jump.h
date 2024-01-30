// Jump.h: interface for the CJump class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUMP_H__1FC4349C_8DDC_4F5E_A77E_1C0379CC8B5B__INCLUDED_)
#define AFX_JUMP_H__1FC4349C_8DDC_4F5E_A77E_1C0379CC8B5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

__PETER_COMPILER_BEGIN

struct CJump  
{
	CJump();
	virtual ~CJump();

	char m_cChar;
	bool m_bE;
	CState *m_pFrom,*m_pTo;

};

__PETER_COMPILER_END

#endif // !defined(AFX_JUMP_H__1FC4349C_8DDC_4F5E_A77E_1C0379CC8B5B__INCLUDED_)
