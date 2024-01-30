// DataField.h: interface for the CDataField class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATAFIELD_H__404980A0_99DD_11D7_B7E0_99D3D1F2FAFE__INCLUDED_)
#define AFX_DATAFIELD_H__404980A0_99DD_11D7_B7E0_99D3D1F2FAFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JavaCompiler.h"

__JAVA_C16X_BEGIN

#define CI_ACCESS_NO_ACCESS	0
#define CI_ACCESS_PRIVATE	1
#define CI_ACCESS_PROTECTED	2
#define CI_ACCESS_PUBLIC	3

struct CDataField  
{
	CDataField();
	virtual ~CDataField();

	int m_iAccess;
	std::string m_sId;
	std::string m_sType;
	bool m_bStd_type;

	int m_iOffset;
	int m_iSize;
	int m_iId;

};

struct CMethod
{
	CMethod();
	virtual ~CMethod();

	void GenName();
	
	int m_iAccess;
	bool m_bStatic;
	std::string m_sId;
	CDataField m_dfReturn;
	std::string m_sName;
	std::vector<CDataField> m_vFormalParameters;
	int m_iId;

};

struct DataField_less : std::binary_function<CDataField,CDataField,bool> 
{
	bool operator()(const CDataField&,const CDataField&) const;
};

struct Method_less : std::binary_function<CMethod,CMethod,bool> 
{
	bool operator()(const CMethod&,const CMethod&) const;
};

class CClass
{
public:
	CClass();
	virtual ~CClass();

	std::string m_sId;
	std::set<CDataField,DataField_less> m_stStaticData;
	std::set<CDataField,DataField_less> m_stHeapData;
	std::set<CMethod,Method_less>		m_stMethod;
	std::string m_sExtends_class;
	bool m_bIs_extends;
	int m_icls_id;
	std::set<std::string>				m_stImplements;

	int	GetMaxMethodId();
	int GetMaxStaticId();
	int GetMaxHeapId();

	void EnumStaticData();
	void EnumHeapData();
};

struct Class_less : std::binary_function<CClass,CClass,bool> 
{
	bool operator()(const CClass&,const CClass&) const;
};

int SizeOfType(std::string);
bool IsStdType(std::string);

__JAVA_C16X_END

#endif // !defined(AFX_DATAFIELD_H__404980A0_99DD_11D7_B7E0_99D3D1F2FAFE__INCLUDED_)
