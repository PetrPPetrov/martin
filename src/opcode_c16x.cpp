// OpcodeC16X.cpp: implementation of the COpcodeC16X class.
//
//////////////////////////////////////////////////////////////////////

#include "OpcodeC16X.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__JAVA_C16X_BEGIN

#define new_line "\r\n"

///////////////////////////////////////
// CKeyLabel implementation

CKeyLabel::CKeyLabel()
{

}

CKeyLabel::CKeyLabel(std::string _name,int _value):
m_sLabel_name(_name),
m_iValue(_value)
{

}

CKeyLabel::~CKeyLabel()
{

}

bool KeyLabel_less::operator()(const CKeyLabel &a,const CKeyLabel &b) const
{
	if (a.m_sLabel_name<b.m_sLabel_name)
		return true;
	else
		return false;
	return false;
}

///////////////////////////////////////
// COpcodeRecord implementation

COpcodeRecord::COpcodeRecord():
m_iType(OPCODE_NONE),m_iOpcode(OPCODE_NONE),
m_iParam1(0),m_iParam2(0),m_iParam3(0)
{
	m_sString="";
}

//////////////////////////////////////
// COpcodeC16X implementation

void COpcodeC16X::Org(int _origin)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_ORG;
	opcode.m_iParam1=_origin;
	SetOrigin(_origin);
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Label(std::string _label)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_LABEL;
	opcode.m_sString=_label;
	opcode.m_iParam1=m_iCurrent_origin;
	m_vOut.push_back(opcode);
	m_stLabel.insert(CKeyLabel(_label,m_iCurrent_origin));
}

void COpcodeC16X::Comment(std::string _comment)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_COMMENT;
	opcode.m_sString=_comment;
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Directive(std::string _directive)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_DIRECTIVE;
	opcode.m_sString=_directive;
	m_vOut.push_back(opcode);
}

void COpcodeC16X::DB(int d1)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_DB;
	opcode.m_iParam1=d1;
	SetOrigin(m_iCurrent_origin+1);
	m_vOut.push_back(opcode);
}

void COpcodeC16X::DW(int d1)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_DW;
	opcode.m_iParam1=HiByte(d1);
	opcode.m_iParam2=LoByte(d1);
	SetOrigin(m_iCurrent_origin+2);
	m_vOut.push_back(opcode);
}

void COpcodeC16X::DQ(int d1,int d2)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_DQ;
	opcode.m_iParam1=HiByte(d1);
	opcode.m_iParam2=LoByte(d1);
	opcode.m_iParam3=HiByte(d2);
	opcode.m_iParam4=LoByte(d2);
	SetOrigin(m_iCurrent_origin+4);
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Add(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_ADD;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Addb(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_ADDB;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Addc(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_ADDC;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Addcb(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_ADDCB;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::And(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_AND;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Andb(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_ANDB;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Atomic(int irang2)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_ATOMIC;
	opcode.m_iParam1=irang2-1;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Calla(int cc,std::string _label)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_CALLA;
	opcode.m_iParam1=cc;
	opcode.m_sString=_label;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Calli(int cc,int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_CALLI;
	opcode.m_iParam1=cc;
	opcode.m_iParam2=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Calls(int seg,std::string _label)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_CALLS;
	opcode.m_iParam1=seg;
	opcode.m_sString=_label;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Cmp(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_CMP;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Cmpb(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_CMPB;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Diswdt()
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_DISWDT;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Div(int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_DIV;
	opcode.m_iParam1=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Divl(int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_DIVL;
	opcode.m_iParam1=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Divlu(int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_DIVLU;
	opcode.m_iParam1=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Divu(int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_DIVU;
	opcode.m_iParam1=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Einit()
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_EINIT;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Extr(int irang2)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_EXTR;
	opcode.m_iParam1=irang2-1;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Exts(int rwn,int irang2)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_EXTS;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=irang2-1;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Extp(int rwn,int irang2)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_EXTP;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=irang2-1;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Idle()
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_IDLE;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Jmpi(int cc,int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_JMPI;
	opcode.m_iParam1=cc;
	opcode.m_iParam2=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Jmpa(int cc,std::string _label)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_JMPA;
	opcode.m_iParam1=cc;
	opcode.m_sString=_label;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Jmps(int seg,std::string _label)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_JMPS;
	opcode.m_iParam1=seg;
	opcode.m_sString=_label;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movrr(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVRR;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movrd(int reg,int data16)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVRD;
	opcode.m_iParam1=reg;
	opcode.m_iParam2=data16;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movrdl(int reg,std::string _label)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVRDL;
	opcode.m_iParam1=reg;
	opcode.m_sString=_label;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movri(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVRI;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movir(int rwm,int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVIR;
	opcode.m_iParam1=rwm;
	opcode.m_iParam2=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movbrr(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVBRR;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movbrd(int reg,int data16)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVBRD;
	opcode.m_iParam1=reg;
	opcode.m_iParam2=data16;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movbri(int rbn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVBRI;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Movbir(int rwm,int rbn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MOVBIR;
	opcode.m_iParam1=rwm;
	opcode.m_iParam2=rbn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Mul(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MUL;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Mulu(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_MULU;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Neg(int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_NEG;
	opcode.m_iParam1=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Negb(int rwn)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_NEGB;
	opcode.m_iParam1=rwn;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Nop()
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_NOP;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Or(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_OR;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Orb(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_ORB;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Pop(int reg)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_POP;
	opcode.m_iParam1=reg;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Push(int reg)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_PUSH;
	opcode.m_iParam1=reg;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Ret()
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_RET;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Reti()
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_RETI;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Rets()
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_RETS;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Shl(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_SHL;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Shr(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_SHR;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Srst()
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_SRST;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Sub(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_SUB;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Subb(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_SUBB;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Subc(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_SUBC;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Subcb(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_SUBCB;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Xor(int rwn,int rwm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_XOR;
	opcode.m_iParam1=rwn;
	opcode.m_iParam2=rwm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

void COpcodeC16X::Xorb(int rbn,int rbm)
{
	COpcodeRecord opcode;
	opcode.m_iType=OPCODE_INSTRUCTION;
	opcode.m_iOpcode=OPCODE_XORB;
	opcode.m_iParam1=rbn;
	opcode.m_iParam2=rbm;
	SetOrigin(m_iCurrent_origin+SizeOfInstruction(opcode.m_iOpcode));
	m_vOut.push_back(opcode);
}

COpcodeC16X::COpcodeC16X():
m_cFill(0xFF),
m_iCurrent_origin(0),
m_iOutput_format(OUTPUT_FORMAT_ASM_KASKOD_ASM167)
{
	for(int i=0;i<MAX_BIN_SIZE;i++)
		m_cbBin_buffer[i]=m_cFill;
	m_vOut.clear();
	m_stLabel.clear();
}

COpcodeC16X::~COpcodeC16X()
{
	m_vOut.clear();
	m_stLabel.clear();
}

int COpcodeC16X::SizeOfInstruction(int _instruction)
{
	switch(_instruction)
	{
	case OPCODE_ADD:
		return 2;
	case OPCODE_ADDB:
		return 2;
	case OPCODE_ADDC:
		return 2;
	case OPCODE_ADDCB:
		return 2; 
	case OPCODE_AND:
		return 2;
	case OPCODE_ANDB:
		return 2;
	case OPCODE_ATOMIC:
		return 2;
	case OPCODE_CALLA:
		return 4;
	case OPCODE_CALLI:
		return 2;
	case OPCODE_CALLS:
		return 4;
	case OPCODE_CMP:
		return 2;
	case OPCODE_CMPB:
		return 2;
	case OPCODE_DISWDT:
		return 4;
	case OPCODE_DIV:
		return 2;
	case OPCODE_DIVL:
		return 2;
	case OPCODE_DIVLU:
		return 2;
	case OPCODE_DIVU:
		return 2;
	case OPCODE_EINIT:
		return 4;
	case OPCODE_EXTR:
		return 2;
	case OPCODE_EXTS:
		return 2;
	case OPCODE_EXTP:
		return 2;
	case OPCODE_IDLE:
		return 4;
	case OPCODE_JMPI:
		return 2;
	case OPCODE_JMPA:
		return 4;
	case OPCODE_JMPS:
		return 4;
	case OPCODE_MOVRR:
		return 2;
	case OPCODE_MOVRD:
		return 4;
	case OPCODE_MOVRDL:
		return 4;
	case OPCODE_MOVRI:
		return 2;
	case OPCODE_MOVIR:
		return 2;
	case OPCODE_MOVBRR:
		return 2;
	case OPCODE_MOVBRD:
		return 4;
	case OPCODE_MOVBRI:
		return 2;
	case OPCODE_MOVBIR:
		return 2;
	case OPCODE_MUL:
		return 2;
	case OPCODE_MULU:
		return 2;
	case OPCODE_NEG:
		return 2;
	case OPCODE_NEGB:
		return 2;
	case OPCODE_NOP:
		return 2;
	case OPCODE_OR:
		return 2;
	case OPCODE_ORB:
		return 2;
	case OPCODE_POP:
		return 2;
	case OPCODE_PUSH:
		return 2;
	case OPCODE_RET:
		return 2;
	case OPCODE_RETI:
		return 2;
	case OPCODE_RETS:
		return 2;
	case OPCODE_SHL:
		return 2;
	case OPCODE_SHR:
		return 2;
	case OPCODE_SRST:
		return 4;
	case OPCODE_SUB:
		return 2;
	case OPCODE_SUBB:
		return 2;
	case OPCODE_SUBC:
		return 2;
	case OPCODE_SUBCB:
		return 2;
	case OPCODE_XOR:
		return 2;
	case OPCODE_XORB:
		return 2;
	}
#if defined(_DEBUG)
	std::cout<<"SizeOfInstruction() error"<<std::endl;
#endif
	return 0;
}

void COpcodeC16X::CompileStepAsm(std::ofstream* out,COpcodeRecord &op)
{
	int p1=op.m_iParam1;
	int p2=op.m_iParam2;
	int p3=op.m_iParam3;
	int p4=op.m_iParam4;
	std::string l=op.m_sString;
	if (op.m_iType==OPCODE_ORG)
	{
		*out<<"\torg "<<std::hex<<p1<<"h"<<new_line;
	}
	if (op.m_iType==OPCODE_DB)
	{
		*out<<"\tdb "<<std::hex<<p1<<"h"<<new_line;
	}
	if (op.m_iType==OPCODE_DW)
	{
		*out<<"\tdw "<<std::hex<<p1<<p2<<"h"<<new_line;
	}
	if (op.m_iType==OPCODE_DQ)
	{
		*out<<"\tdw "<<std::hex<<p3<<p4<<"h"<<new_line;
		*out<<"\tdw "<<std::hex<<p1<<p2<<"h"<<new_line;
	}
	if (op.m_iType==OPCODE_COMMENT)
	{
		*out<<"; "<<l<<new_line;
	}
	if (op.m_iType==OPCODE_DIRECTIVE)
	{
		*out<<l<<new_line;
	}
	if (op.m_iType==OPCODE_LABEL)
	{
		*out<<l<<":"<<new_line;
	}
	if (op.m_iType==OPCODE_INSTRUCTION)
		switch(op.m_iOpcode)
		{
		case OPCODE_ADD:
			*out<<"\tadd "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_ADDB:
			*out<<"\taddb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		case OPCODE_ADDC:
			*out<<"\taddc "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_ADDCB:
			*out<<"\taddcb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		case OPCODE_AND:
			*out<<"\tand "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_ANDB:
			*out<<"\tandb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		case OPCODE_ATOMIC:
			*out<<"\tatomic #"<<std::dec<<(p1+1)<<new_line;
			break;
		case OPCODE_CALLA:
			*out<<"\tcalla "<<GetCC(p1)<<","<<l<<new_line;
			break;
		case OPCODE_CALLI:
			*out<<"\tcalli "<<GetCC(p1)<<",["<<GetRW(p2)<<"]"<<new_line;
			break;
		case OPCODE_CALLS:
			*out<<"\tcalls "<<std::hex<<p1<<"h,"<<l<<new_line;
			break;
		case OPCODE_CMP:
			*out<<"\tcmp "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_CMPB:
			*out<<"\tcmpb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		case OPCODE_DISWDT:
			*out<<"\tdiswdt"<<new_line;
			break;
		case OPCODE_DIV:
			*out<<"\tdiv "<<GetRW(p1)<<new_line;
			break;
		case OPCODE_DIVL:
			*out<<"\tdivl "<<GetRW(p1)<<new_line;
			break;
		case OPCODE_DIVLU:
			*out<<"\tdivlu "<<GetRW(p1)<<new_line;
			break;
		case OPCODE_DIVU:
			*out<<"\tdivu "<<GetRW(p1)<<new_line;
			break;
		case OPCODE_EINIT:
			*out<<"\teinit"<<new_line;
			break;
		case OPCODE_EXTR:
			*out<<"\textr #"<<std::dec<<(p1+1)<<new_line;
			break;
		case OPCODE_EXTS:
			*out<<"\texts "<<GetRW(p1)<<",#"<<std::dec<<(p2+1)<<new_line;
			break;
		case OPCODE_EXTP:
			*out<<"\textp "<<GetRW(p1)<<",#"<<std::dec<<(p2+1)<<new_line;
			break;
		case OPCODE_IDLE:
			*out<<"\tidle"<<new_line;
			break;
		case OPCODE_JMPI:
			*out<<"\tjmpi "<<GetCC(p1)<<",["<<GetRW(p2)<<"]"<<new_line;
			break;
		case OPCODE_JMPA:
			*out<<"\tjmpa "<<GetCC(p1)<<","<<l<<new_line;
			break;
		case OPCODE_JMPS:
			*out<<"\tjmps "<<std::hex<<p1<<"h,"<<l<<new_line;
			break;
		case OPCODE_MOVRR:
			*out<<"\tmov "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_MOVRD:
			*out<<"\tmov "<<GetREG(p1,false)<<",#"<<std::hex<<p2<<"h"<<new_line;
			break;
		case OPCODE_MOVRDL:
			*out<<"\tmov "<<GetREG(p1,false)<<",#"<<l<<new_line;
			break;
		case OPCODE_MOVRI:
			*out<<"\tmov "<<GetRW(p1)<<",["<<GetRW(p2)<<"]"<<new_line;
			break;
		case OPCODE_MOVIR:
			*out<<"\tmov ["<<GetRW(p1)<<"],"<<GetRW(p2)<<new_line;
			break;
		case OPCODE_MOVBRR:
			*out<<"\tmovb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		case OPCODE_MOVBRD:
			*out<<"\tmovb "<<GetREG(p1,true)<<",#"<<std::hex<<p2<<"h"<<new_line;
			break;
		case OPCODE_MOVBRI:
			*out<<"\tmovb "<<GetRB(p1)<<",["<<GetRW(p2)<<"]"<<new_line;
			break;
		case OPCODE_MOVBIR:
			*out<<"\tmovb ["<<GetRW(p1)<<"],"<<GetRB(p2)<<new_line;
			break;
		case OPCODE_MUL:
			*out<<"\tmul "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_MULU:
			*out<<"\tmulu "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_NEG:
			*out<<"\tneg "<<GetRW(p1)<<new_line;
			break;
		case OPCODE_NEGB:
			*out<<"\tnegb "<<GetRB(p1)<<new_line;
			break;
		case OPCODE_NOP:
			*out<<"\tnop"<<new_line;
			break;
		case OPCODE_OR:
			*out<<"\tor "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_ORB:
			*out<<"\torb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		case OPCODE_POP:
			*out<<"\tpop "<<GetREG(p1,false)<<new_line;
			break;
		case OPCODE_PUSH:
			*out<<"\tpush "<<GetREG(p1,false)<<new_line;
			break;
		case OPCODE_RET:
			*out<<"\tret"<<new_line;
			break;
		case OPCODE_RETI:
			*out<<"\treti"<<new_line;
			break;
		case OPCODE_RETS:
			*out<<"\trets"<<new_line;
			break;
		case OPCODE_SHL:
			*out<<"\tshl "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_SHR:
			*out<<"\tshr "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_SRST:
			*out<<"\tsrst"<<new_line;
			break;
		case OPCODE_SUB:
			*out<<"\tsub "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_SUBB:
			*out<<"\tsubb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		case OPCODE_SUBC:
			*out<<"\tsubc "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_SUBCB:
			*out<<"\tsubcb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		case OPCODE_XOR:
			*out<<"\txor "<<GetRW(p1)<<","<<GetRW(p2)<<new_line;
			break;
		case OPCODE_XORB:
			*out<<"\txorb "<<GetRB(p1)<<","<<GetRB(p2)<<new_line;
			break;
		}
}

void COpcodeC16X::CompileStepBin(COpcodeRecord &op)
{
	int p1=op.m_iParam1;
	int p2=op.m_iParam2;
	int p3=op.m_iParam3;
	int p4=op.m_iParam4;
	std::string l=op.m_sString;
	if (op.m_iType==OPCODE_ORG)
	{
		SetOrigin(p1);
	}
	if (op.m_iType==OPCODE_DB)
	{
		m_cbBin_buffer[m_iCurrent_origin]=p1;
		SetOrigin(m_iCurrent_origin+1);
	}
	if (op.m_iType==OPCODE_DW)
	{
		m_cbBin_buffer[m_iCurrent_origin]=p2;
		SetOrigin(m_iCurrent_origin+1);
		m_cbBin_buffer[m_iCurrent_origin]=p1;
		SetOrigin(m_iCurrent_origin+1);
	}
	if (op.m_iType==OPCODE_DQ)
	{
		m_cbBin_buffer[m_iCurrent_origin]=p4;
		SetOrigin(m_iCurrent_origin+1);
		m_cbBin_buffer[m_iCurrent_origin]=p3;
		SetOrigin(m_iCurrent_origin+1);
		m_cbBin_buffer[m_iCurrent_origin]=p2;
		SetOrigin(m_iCurrent_origin+1);
		m_cbBin_buffer[m_iCurrent_origin]=p1;
		SetOrigin(m_iCurrent_origin+1);
	}
	if (op.m_iType==OPCODE_COMMENT)
	{
	}
	if (op.m_iType==OPCODE_DIRECTIVE)
	{
	}
	if (op.m_iType==OPCODE_LABEL)
	{
	}
	if (op.m_iType==OPCODE_INSTRUCTION)
		switch(op.m_iOpcode)
		{
		case OPCODE_ADD:
			m_cbBin_buffer[Next()]=0x00;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_ADDB:
			m_cbBin_buffer[Next()]=0x01;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_ADDC:
			m_cbBin_buffer[Next()]=0x10;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_ADDCB:
			m_cbBin_buffer[Next()]=0x11;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_AND:
			m_cbBin_buffer[Next()]=0x60;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_ANDB:
			m_cbBin_buffer[Next()]=0x61;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_ATOMIC:
			m_cbBin_buffer[Next()]=0xD1;
			m_cbBin_buffer[Next()]=0x00+(p1<<4);
			break;
		case OPCODE_CALLA:
			m_cbBin_buffer[Next()]=0xCA;
			m_cbBin_buffer[Next()]=0x00+(p1<<4);
			m_cbBin_buffer[Next()]=LoByte(GetLabel(l));
			m_cbBin_buffer[Next()]=HiByte(GetLabel(l));
			break;
		case OPCODE_CALLI:
			m_cbBin_buffer[Next()]=0xAB;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_CALLS:
			m_cbBin_buffer[Next()]=0xDA;
			m_cbBin_buffer[Next()]=0x00+p1;
			m_cbBin_buffer[Next()]=LoByte(GetLabel(l));
			m_cbBin_buffer[Next()]=HiByte(GetLabel(l));
			break;
		case OPCODE_CMP:
			m_cbBin_buffer[Next()]=0x40;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_CMPB:
			m_cbBin_buffer[Next()]=0x41;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_DISWDT:
			m_cbBin_buffer[Next()]=0xA5;
			m_cbBin_buffer[Next()]=0x5A;
			m_cbBin_buffer[Next()]=0xA5;
			m_cbBin_buffer[Next()]=0xA5;
			break;
		case OPCODE_DIV:
			m_cbBin_buffer[Next()]=0x4B;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p1;
			break;
		case OPCODE_DIVL:
			m_cbBin_buffer[Next()]=0x6B;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p1;
			break;
		case OPCODE_DIVLU:
			m_cbBin_buffer[Next()]=0x7B;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p1;
			break;
		case OPCODE_DIVU:
			m_cbBin_buffer[Next()]=0x5B;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p1;
			break;
		case OPCODE_EINIT:
			m_cbBin_buffer[Next()]=0xB5;
			m_cbBin_buffer[Next()]=0x4A;
			m_cbBin_buffer[Next()]=0xB5;
			m_cbBin_buffer[Next()]=0xB5;
			break;
		case OPCODE_EXTR:
			m_cbBin_buffer[Next()]=0xD1;
			m_cbBin_buffer[Next()]=0x80+(p1<<4);
			break;
		case OPCODE_EXTS:
			m_cbBin_buffer[Next()]=0xDC;
			m_cbBin_buffer[Next()]=0x00+(p2<<4)+p1;
			break;
		case OPCODE_EXTP:
			m_cbBin_buffer[Next()]=0xDC;
			m_cbBin_buffer[Next()]=0x40+(p2<<4)+p1;
			break;
		case OPCODE_IDLE:
			m_cbBin_buffer[Next()]=0x87;
			m_cbBin_buffer[Next()]=0x78;
			m_cbBin_buffer[Next()]=0x87;
			m_cbBin_buffer[Next()]=0x87;
			break;
		case OPCODE_JMPI:
			m_cbBin_buffer[Next()]=0x9C;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_JMPA:
			m_cbBin_buffer[Next()]=0xEA;
			m_cbBin_buffer[Next()]=0x00+(p1<<4);
			m_cbBin_buffer[Next()]=LoByte(GetLabel(l));
			m_cbBin_buffer[Next()]=HiByte(GetLabel(l));
			break;
		case OPCODE_JMPS:
			m_cbBin_buffer[Next()]=0xFA;
			m_cbBin_buffer[Next()]=0x00+p1;
			m_cbBin_buffer[Next()]=LoByte(GetLabel(l));
			m_cbBin_buffer[Next()]=HiByte(GetLabel(l));
			break;
		case OPCODE_MOVRR:
			m_cbBin_buffer[Next()]=0xF0;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_MOVRD:
			m_cbBin_buffer[Next()]=0xE6;
			m_cbBin_buffer[Next()]=0x00+p1;
			m_cbBin_buffer[Next()]=LoByte(p2);
			m_cbBin_buffer[Next()]=HiByte(p2);
			break;
		case OPCODE_MOVRDL:
			m_cbBin_buffer[Next()]=0xE6;
			m_cbBin_buffer[Next()]=0x00+p1;
			m_cbBin_buffer[Next()]=LoByte(GetLabel(l));
			m_cbBin_buffer[Next()]=HiByte(GetLabel(l));
			break;
		case OPCODE_MOVRI:
			m_cbBin_buffer[Next()]=0xA8;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_MOVIR:
			m_cbBin_buffer[Next()]=0xB8;
			m_cbBin_buffer[Next()]=0x00+(p2<<4)+p1;
			break;
		case OPCODE_MOVBRR:
			m_cbBin_buffer[Next()]=0xF1;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_MOVBRD:
			m_cbBin_buffer[Next()]=0xE7;
			m_cbBin_buffer[Next()]=0x00+p1;
			m_cbBin_buffer[Next()]=LoByte(p2);
			m_cbBin_buffer[Next()]=HiByte(p2);
			break;
		case OPCODE_MOVBRI:
			m_cbBin_buffer[Next()]=0xA9;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_MOVBIR:
			m_cbBin_buffer[Next()]=0xB9;
			m_cbBin_buffer[Next()]=0x00+(p2<<4)+p1;
			break;
		case OPCODE_MUL:
			m_cbBin_buffer[Next()]=0x0B;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_MULU:
			m_cbBin_buffer[Next()]=0x1B;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_NEG:
			m_cbBin_buffer[Next()]=0x81;
			m_cbBin_buffer[Next()]=0x00+(p1<<4);
			break;
		case OPCODE_NEGB:
			m_cbBin_buffer[Next()]=0xA1;
			m_cbBin_buffer[Next()]=0x00+(p1<<4);
			break;
		case OPCODE_NOP:
			m_cbBin_buffer[Next()]=0xCC;
			m_cbBin_buffer[Next()]=0x00;
			break;
		case OPCODE_OR:
			m_cbBin_buffer[Next()]=0x70;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_ORB:
			m_cbBin_buffer[Next()]=0x71;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_POP:
			m_cbBin_buffer[Next()]=0xFC;
			m_cbBin_buffer[Next()]=0x00+p1;
			break;
		case OPCODE_PUSH:
			m_cbBin_buffer[Next()]=0xEC;
			m_cbBin_buffer[Next()]=0x00+p1;
			break;
		case OPCODE_RET:
			m_cbBin_buffer[Next()]=0xCB;
			m_cbBin_buffer[Next()]=0x00;
			break;
		case OPCODE_RETI:
			m_cbBin_buffer[Next()]=0xFB;
			m_cbBin_buffer[Next()]=0x88;
			break;
		case OPCODE_RETS:
			m_cbBin_buffer[Next()]=0xDB;
			m_cbBin_buffer[Next()]=0x00;
			break;
		case OPCODE_SHL:
			m_cbBin_buffer[Next()]=0x4C;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_SHR:
			m_cbBin_buffer[Next()]=0x6C;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_SRST:
			m_cbBin_buffer[Next()]=0xB7;
			m_cbBin_buffer[Next()]=0x48;
			m_cbBin_buffer[Next()]=0xB7;
			m_cbBin_buffer[Next()]=0xB7;
			break;
		case OPCODE_SUB:
			m_cbBin_buffer[Next()]=0x20;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_SUBB:
			m_cbBin_buffer[Next()]=0x21;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_SUBC:
			m_cbBin_buffer[Next()]=0x30;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_SUBCB:
			m_cbBin_buffer[Next()]=0x31;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_XOR:
			m_cbBin_buffer[Next()]=0x50;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		case OPCODE_XORB:
			m_cbBin_buffer[Next()]=0x51;
			m_cbBin_buffer[Next()]=0x00+(p1<<4)+p2;
			break;
		}
}

void COpcodeC16X::Compile(std::ofstream* out)
{
	if (m_iOutput_format==OUTPUT_FORMAT_ASM_KASKOD_ASM167)
		CompileAsm(out);
	if (m_iOutput_format==OUTPUT_FORMAT_BIN_KASKOD_FLASH168)
		CompileBin(out);
}

void COpcodeC16X::CompileBin(std::ofstream* out)
{
	int i=0;
	for(i=0;i<MAX_BIN_SIZE;i++)
		m_cbBin_buffer[i]=m_cFill;
	m_iCurrent_origin=0;
	m_iMax_origin=0;
	std::vector<COpcodeRecord>::iterator b,e,j;
	b=m_vOut.begin();
	e=m_vOut.end();
	for(j=b;j!=e;j++)
		CompileStepBin(*j);
	for(i=0;i<(m_iMax_origin);i++)
		*out<<m_cbBin_buffer[i];
}
	
void COpcodeC16X::CompileAsm(std::ofstream* out)
{
	std::vector<COpcodeRecord>::iterator b,e,i;
	b=m_vOut.begin();
	e=m_vOut.end();
	for(i=b;i!=e;i++)
		CompileStepAsm(out,*i);
}

void COpcodeC16X::SetOrigin(int _origin)
{
#if defined(_DEBUG)
	if (_origin>65530)
		std::cout<<"SetOrigin() overflow"<<std::endl;
#endif
	_origin=_origin%65530;
	if (_origin>m_iMax_origin)
		m_iMax_origin=_origin;
	m_iCurrent_origin=_origin;
}

int  COpcodeC16X::Next()
{
	int result=m_iCurrent_origin;
	SetOrigin(result+1);
	return result;
}

int  COpcodeC16X::GetLabel(std::string _label)
{
	CKeyLabel key(_label,0);
	std::set<CKeyLabel,KeyLabel_less>::iterator i;
	i=m_stLabel.find(key);
	if (i!=m_stLabel.end())
		return (*i).m_iValue;
#if defined(_DEBUG)
	std::cout<<"GetLabel(\""+_label+"\") error"<<std::endl;
#endif
	return 0;
}

std::string COpcodeC16X::GetCC(int cc)
{
	switch(cc)
	{
	case CC_UC:
		return "cc_uc";
	case CC_V:
		return "cc_v";
	case CC_NV:
		return "cc_nv";
	case CC_N:
		return "cc_n";
	case CC_NN:
		return "cc_nn";
	case CC_EQ:
		return "cc_eq";
	case CC_NE:
		return "cc_ne";
	case CC_ULT:
		return "cc_ult";
	case CC_ULE:
		return "cc_ule";
	case CC_UGE:
		return "cc_uge";
	case CC_UGT:
		return "cc_ugt";
	case CC_SLT:
		return "cc_slt";
	case CC_SLE:
		return "cc_sle";
	case CC_SGE:
		return "cc_sge";
	case CC_SGT:
		return "cc_sgt";
	case CC_NET:
		return "cc_net";
	}
#if defined(_DEBUG)
	std::cout<<"GetCC() error"<<std::endl;
#endif
	return "cc_uc";
}

std::string COpcodeC16X::GetRW(int rwn)
{
	switch(rwn)
	{
	case R0:
		return "r0";
	case R1:
		return "r1";
	case R2:
		return "r2";
	case R3:
		return "r3";
	case R4:
		return "r4";
	case R5:
		return "r5";
	case R6:
		return "r6";
	case R7:
		return "r7";
	case R8:
		return "r8";
	case R9:
		return "r9";
	case R10:
		return "r10";
	case R11:
		return "r11";
	case R12:
		return "r12";
	case R13:
		return "r13";
	case R14:
		return "r14";
	case R15:
		return "r15";
	}
#if defined(_DEBUG)
	std::cout<<"GetRW() error"<<std::endl;
#endif
	return "r0";
}

std::string COpcodeC16X::GetRB(int rbn)
{
	switch(rbn)
	{
	case RL0:
		return "rl0";
	case RH0:
		return "rh0";
	case RL1:
		return "rl1";
	case RH1:
		return "rh1";
	case RL2:
		return "rl2";
	case RH2:
		return "rh2";
	case RL3:
		return "rl3";
	case RH3:
		return "rh3";
	case RL4:
		return "rl4";
	case RH4:
		return "rh4";
	case RL5:
		return "rl5";
	case RH5:
		return "rh5";
	case RL6:
		return "rl6";
	case RH6:
		return "rh6";
	case RL7:
		return "rl7";
	case RH7:
		return "rh7";
	}
#if defined(_DEBUG)
	std::cout<<"GetRB() error"<<std::endl;
#endif
	return "rl0";
}

std::string COpcodeC16X::GetREG(int reg,bool b)
{
	if (b)
	switch(reg)
	{
	case REG_RL0:
		return "rl0";
	case REG_RH0:
		return "rh0";
	case REG_RL1:
		return "rl1";
	case REG_RH1:
		return "rh1";
	case REG_RL2:
		return "rl2";
	case REG_RH2:
		return "rh2";
	case REG_RL3:
		return "rl3";
	case REG_RH3:
		return "rh3";
	case REG_RL4:
		return "rl4";
	case REG_RH4:
		return "rh4";
	case REG_RL5:
		return "rl5";
	case REG_RH5:
		return "rh5";
	case REG_RL6:
		return "rl6";
	case REG_RH6:
		return "rh6";
	case REG_RL7:
		return "rl7";
	case REG_RH7:
		return "rh7";
	}
	else
	switch(reg)
	{
	case REG_R0:
		return "r0";
	case REG_R1:
		return "r1";
	case REG_R2:
		return "r2";
	case REG_R3:
		return "r3";
	case REG_R4:
		return "r4";
	case REG_R5:
		return "r5";
	case REG_R6:
		return "r6";
	case REG_R7:
		return "r7";
	case REG_R8:
		return "r8";
	case REG_R9:
		return "r9";
	case REG_R10:
		return "r10";
	case REG_R11:
		return "r11";
	case REG_R12:
		return "r12";
	case REG_R13:
		return "r13";
	case REG_R14:
		return "r14";
	case REG_R15:
		return "r15";
	}
	switch(reg)
	{
	case REG_SYSCON:
		return "syscon";
	case REG_BUSCON0:
		return "buscon0";
	case REG_BUSCON1:
		return "buscon1";
	case REG_BUSCON2:
		return "buscon2";
	case REG_BUSCON3:
		return "buscon3";
	case REG_BUSCON4:
		return "buscon4";
	case REG_ADDRSEL1:
		return "addrsel1";
	case REG_ADDRSEL2:
		return "addrsel2";
	case REG_ADDRSEL3:
		return "addrsel3";
	case REG_ADDRSEL4:
		return "addrsel4";
	}
#if defined(_DEBUG)
	std::cout<<"GetREG() error"<<std::endl;
#endif
	return "r0";
}

unsigned char COpcodeC16X::LoByte(int w)
{
	return (unsigned char)w;
}

unsigned char COpcodeC16X::HiByte(int w)
{
	return (unsigned char)(w>>8);
}

__JAVA_C16X_END