// DataField.cpp: implementation of the CDataField class.
//
//////////////////////////////////////////////////////////////////////

#include "DataField.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__JAVA_C16X_BEGIN

CDataField::CDataField():
m_bStd_type(false),m_iOffset(0),m_iSize(0),
m_iAccess(CI_ACCESS_NO_ACCESS),m_iId(0)
{
	m_sId="";
	m_sType="";
}

CDataField::~CDataField()
{

}

CMethod::CMethod():
m_iId(0),m_iAccess(CI_ACCESS_NO_ACCESS),m_bStatic(false)
{
	m_sName="";
	m_vFormalParameters.clear();
}

CMethod::~CMethod()
{
	m_vFormalParameters.clear();
}

void CMethod::GenName()
{
	std::vector<CDataField>::iterator b,e,i;
	m_sId=m_dfReturn.m_sType+"_";
	m_sId=m_sId+m_sName+"_";
	b=m_vFormalParameters.begin();
	e=m_vFormalParameters.end();
	for(i=b;i!=e;i++)
		m_sId=m_sId+(*i).m_sType+"_";
//	m_sId=m_sId+")";
}

bool DataField_less::operator()(const CDataField &a,const CDataField &b) const
{
	if (a.m_sId<b.m_sId)
		return true;
	else
		return false;
	return false;
}

bool Method_less::operator()(const CMethod &a,const CMethod &b) const
{
	if (a.m_sId<b.m_sId)
		return true;
	else
		return false;
	return false;
}

CClass::CClass():
m_bIs_extends(false),m_icls_id(0)
{
	m_sId="";
	m_sExtends_class="";
	m_stStaticData.clear();
	m_stHeapData.clear();
	m_stImplements.clear();
	m_stMethod.clear();
}

CClass::~CClass()
{
	m_stStaticData.clear();
	m_stHeapData.clear();
	m_stImplements.clear();
	m_stMethod.clear();
}

int	CClass::GetMaxMethodId()
{
	int nmax=0;
	std::set<CMethod,Method_less>::iterator b,e,i;
	b=m_stMethod.begin();
	e=m_stMethod.end();
	for(i=b;i!=e;i++)
	{
		CMethod &method=*i;
		if (method.m_iId>nmax)
			nmax=method.m_iId;
	}
	return nmax;
}

int	CClass::GetMaxStaticId()
{
	int nmax=0;
	std::set<CDataField,DataField_less>::iterator b,e,i;
	b=m_stStaticData.begin();
	e=m_stStaticData.end();
	for(i=b;i!=e;i++)
	{
		CDataField &data=*i;
		if (data.m_iId>nmax)
			nmax=data.m_iId;
	}
	return nmax;
}

int	CClass::GetMaxHeapId()
{
	int nmax=0;
	std::set<CDataField,DataField_less>::iterator b,e,i;
	b=m_stHeapData.begin();
	e=m_stHeapData.end();
	for(i=b;i!=e;i++)
	{
		CDataField &data=*i;
		if (data.m_iId>nmax)
			nmax=data.m_iId;
	}
	return nmax;
}

void CClass::EnumStaticData()
{
	int offset=0;
	std::set<CDataField,DataField_less>::iterator b,e,i;
	b=m_stStaticData.begin();
	e=m_stStaticData.end();
	for(i=b;i!=e;i++)
	{
		CDataField &data=*i;
		data.m_iOffset=offset;
		data.m_iSize=SizeOfType(data.m_sType);
		offset+=data.m_iSize;
	}
}

void CClass::EnumHeapData()
{
	int offset=0;
	std::set<CDataField,DataField_less>::iterator b,e,i;
	b=m_stHeapData.begin();
	e=m_stHeapData.end();
	for(i=b;i!=e;i++)
	{
		CDataField &data=*i;
		data.m_iOffset=offset;
		data.m_iSize=SizeOfType(data.m_sType);
		offset+=data.m_iSize;
	}
}

bool Class_less::operator()(const CClass &a,const CClass &b) const
{
	if (a.m_sId<b.m_sId)
		return true;
	else
		return false;
	return false;
}

int SizeOfType(std::string type)
{
	if (type=="boolean") return 2;
	if (type=="double") return 4;
	if (type=="float") return 4;
	if (type=="long") return 4;
	if (type=="int") return 4;
	if (type=="char") return 2;
	if (type=="short") return 2;
	if (type=="byte") return 2;
	return 2;
}

bool IsStdType(std::string type)
{
	if (type=="boolean") return true;
	if (type=="double") return true;
	if (type=="float") return true;
	if (type=="long") return true;
	if (type=="int") return true;
	if (type=="char") return true;
	if (type=="short") return true;
	if (type=="byte") return true;
	return false;
}

__JAVA_C16X_END
