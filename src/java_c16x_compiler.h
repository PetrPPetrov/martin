// JavaC16XCompiler.h: interface for the CJavaC16XCompiler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JAVAC16XCOMPILER_H__B09A9240_92A8_11D7_B7E0_C4B7A12F59BE__INCLUDED_)
#define AFX_JAVAC16XCOMPILER_H__B09A9240_92A8_11D7_B7E0_C4B7A12F59BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PeterCompiler.h"
#include "JavaCompiler.h"
#include "JavaC16XTarget.h"
#include "DataField.h"

using namespace CPeterCompiler;

__JAVA_C16X_BEGIN

class CJavaC16XCompiler : public CCompiler  
{
public:
	CJavaC16XCompiler(CJavaC16XTarget*);
	virtual ~CJavaC16XCompiler();

	virtual void Analisys(CTree*) throw(CPeterCompiler::CSemanticException);
	virtual void Translate(std::ofstream&,CTree*) throw(CPeterCompiler::CSemanticException);
	virtual void Compile(std::ofstream&,CTree*) throw(CPeterCompiler::CSemanticException);
	virtual void Clear();
	virtual void PreTranslate();
	virtual void PreCompile();

protected:
	void CompileSub(CTree*) throw(CPeterCompiler::CSemanticException);

/////////////////////////////////////////////
// Rule semantic analisys
/////////////////////////////////////////////

#include "SemanticMethods.h"

/////////////////////////////////////////////
// Rule compilations
/////////////////////////////////////////////

#include "CompileMethods.h"

/////////////////////////////////////////////
// GetTreeComponents
/////////////////////////////////////////////	
		
	std::string GetQualifiedIdentifiers(CTree*);
	std::string GetQualifiedIdentifier(CTree*);

	int GetMaxMethodId();
	int GetMaxStaticId();
	int GetMaxHeapId();

private:
	CJavaC16XTarget* m_ptTarget;
	std::set<CClass,Class_less> m_stClasses;
	std::set<CClass,Class_less> m_stInterfaces;
	std::set<CClass,Class_less>::iterator m_itCurClass;
	std::set<CClass,Class_less>::iterator m_itCurInterface;

//	std::set<std::string> m_stTempImplements;
//	std::set<std::string> m_stTempExtends;

	std::set<std::string> m_stModifiers;
	std::string m_sModifier;
	std::set<std::string> m_stTypeList;
	std::string m_sType;
	std::string m_sBracket;
	std::string m_sVariableId;
	std::vector<CDataField> m_vFormalParameters;
	CDataField m_dfFormalParameter;

	bool m_bData;
	bool m_bMethod;

	CDataField m_dfData;
	CMethod m_meMethod;

	std::string m_sPackage_name;

};

__JAVA_C16X_END

#endif // !defined(AFX_JAVAC16XCOMPILER_H__B09A9240_92A8_11D7_B7E0_C4B7A12F59BE__INCLUDED_)
