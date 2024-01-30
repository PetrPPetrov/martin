// JavaC16XSmallAsm.h: interface for the CJavaC16XSmallAsm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JAVAC16XSMALLASM_H__E23D99E0_92DB_11D7_B7E0_C4B7A12F59BE__INCLUDED_)
#define AFX_JAVAC16XSMALLASM_H__E23D99E0_92DB_11D7_B7E0_C4B7A12F59BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DataField.h"
#include "JavaC16XTarget.h"
#include "OpcodeC16X.h"

using namespace CPeterCompiler;

__JAVA_C16X_BEGIN

class CJavaC16XSmallAsm : public CJavaC16XTarget  
{
public:
	CJavaC16XSmallAsm();
	virtual ~CJavaC16XSmallAsm();

	virtual void BeginCompile(std::ofstream&);
	virtual void EndCompile();

	virtual void Prolog();
	virtual void Epilog();

	virtual void FlashLoader();
	virtual void Initialization();
	virtual void System_gc();
	virtual void RTTI(std::set<CClass,Class_less>&,std::set<CClass,Class_less>&);
	virtual void StaticData(std::set<CClass,Class_less>&);

	virtual void Package(std::string);

	virtual void Comment(std::string);
/*
	virtual void Pop();
	virtual void Push();
	virtual void MethodProlog();
	virtual void MethodEpilog();
	virtual void ReadVarTo1(std::string);
	virtual void ReadVarTo2(std::string);
	virtual void WriteVarFrom1(std::string);
	virtual void WriteVarFrom2(std::string);
	virtual void AddA();
	virtual void SubA();
	virtual void MulA();
	virtual void DivA();
	virtual void EquA();
	virtual void GreA();
	virtual void LesA();
	virtual void GotoLabel(std::string);
	virtual void CallLabel(std::string);
	virtual void MakeVar(std::string);
	virtual void ReleaseVar(std::string);
*/
private:
	std::ofstream* m_sOut;
	COpcodeC16X	m_opOut;

	int m_iPrg_len;
	int m_iRam_seg;
	int m_iRom_seg;
	int m_iHep_seg;

};

__JAVA_C16X_END

#endif // !defined(AFX_JAVAC16XSMALLASM_H__E23D99E0_92DB_11D7_B7E0_C4B7A12F59BE__INCLUDED_)
