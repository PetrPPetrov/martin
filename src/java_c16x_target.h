// JavaC16XTarget.h: interface for the CJavaC16XTarget class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JAVAC16XTARGET_H__B09A9241_92A8_11D7_B7E0_C4B7A12F59BE__INCLUDED_)
#define AFX_JAVAC16XTARGET_H__B09A9241_92A8_11D7_B7E0_C4B7A12F59BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PeterCompiler.h"
#include "JavaCompiler.h"
#include "DataField.h"

using namespace CPeterCompiler;

__JAVA_C16X_BEGIN

class CJavaC16XTarget  
{
public:
	CJavaC16XTarget();
	virtual ~CJavaC16XTarget();

	virtual void BeginCompile(std::ofstream&)=0;
	virtual void EndCompile()=0;

	virtual void Prolog()=0;
	virtual void Epilog()=0;

	virtual void FlashLoader()=0;
	virtual void Initialization()=0;
	virtual void System_gc()=0;
	virtual void RTTI(std::set<CClass,Class_less>&,std::set<CClass,Class_less>&)=0;
	virtual void StaticData(std::set<CClass,Class_less>&)=0;
/*
	virtual void Pop()=0;
	virtual void Push()=0;
	virtual void MethodProlog(std::string)=0;
	virtual void MethodEpilog(std::string)=0;
	virtual void ReadVarTo1(std::string)=0;
	virtual void ReadVarTo2(std::string)=0;
	virtual void WriteVarFrom1(std::string)=0;
	virtual void WriteVarFrom2(std::string)=0;
	virtual void AddA()=0;
	virtual void SubA()=0;
	virtual void MulA()=0;
	virtual void DivA()=0;
	virtual void EquA()=0;
	virtual void GreA()=0;
	virtual void LesA()=0;
	virtual void GotoLabel(std::string)=0;
	virtual void CallLabel(std::string)=0;
	virtual void MakeVar(std::string)=0;
	virtual void ReleaseVar(std::string)=0;
*/
	virtual void Package(std::string)=0;

	virtual void Comment(std::string)=0;

};

__JAVA_C16X_END

#endif // !defined(AFX_JAVAC16XTARGET_H__B09A9241_92A8_11D7_B7E0_C4B7A12F59BE__INCLUDED_)
