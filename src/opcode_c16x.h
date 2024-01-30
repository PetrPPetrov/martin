// OpcodeC16X.h: interface for the COpcodeC16X class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPCODEC16X_H__A3400DE0_9380_11D7_B7E0_AF572FFEC74F__INCLUDED_)
#define AFX_OPCODEC16X_H__A3400DE0_9380_11D7_B7E0_AF572FFEC74F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JavaCompiler.h"

__JAVA_C16X_BEGIN

#define MAX_BIN_SIZE		65535

#define OUTPUT_FORMAT_ASM_KASKOD_ASM167		1
#define OUTPUT_FORMAT_BIN_KASKOD_FLASH168	2		

#define CC_UC				0x00
#define CC_Z				0x02
#define CC_NZ				0x03
#define CC_V				0x04
#define CC_NV				0x05
#define CC_N				0x06
#define CC_NN				0x07
#define CC_C				0x08
#define CC_NC				0x09
#define CC_EQ				0x02
#define CC_NE				0x03
#define CC_ULT				0x08
#define CC_ULE				0x0F
#define CC_UGE				0x09
#define CC_UGT				0x0E
#define CC_SLT				0x0C
#define CC_SLE				0x0B
#define CC_SGE				0x0D
#define CC_SGT				0x0A
#define CC_NET				0x01

#define RL0		0x0
#define RH0		0x1
#define RL1		0x2
#define RH1		0x3
#define RL2		0x4
#define RH2		0x5
#define RL3		0x6
#define RH3		0x7
#define RL4		0x8
#define RH4		0x9
#define RL5		0xA
#define RH5		0xB
#define RL6		0xC
#define RH6		0xD
#define RL7		0xE
#define RH7		0xF

#define R0		0x0
#define R1		0x1
#define R2		0x2
#define R3		0x3
#define R4		0x4
#define R5		0x5
#define R6		0x6
#define R7		0x7
#define R8		0x8
#define R9		0x9
#define R10		0xA
#define R11		0xB
#define R12		0xC
#define R13		0xD
#define R14		0xE
#define R15		0xF

#define REG_SYSCON		0x89
#define REG_BUSCON0		0x86
#define REG_BUSCON1		0x8A
#define REG_BUSCON2		0x8B
#define REG_BUSCON3		0x8C
#define REG_BUSCON4		0x8D
#define REG_ADDRSEL1	0x0C
#define REG_ADDRSEL2	0x0D
#define REG_ADDRSEL3	0x0E
#define REG_ADDRSEL4	0x0F

#define REG_R0		0xF0
#define REG_R1		0xF1
#define REG_R2		0xF2
#define REG_R3		0xF3
#define REG_R4		0xF4
#define REG_R5		0xF5
#define REG_R6		0xF6
#define REG_R7		0xF7
#define REG_R8		0xF8
#define REG_R9		0xF9
#define REG_R10		0xFA
#define REG_R11		0xFB
#define REG_R12		0xFC
#define REG_R13		0xFD
#define REG_R14		0xFE
#define REG_R15		0xFF

#define REG_RL0		0xF0
#define REG_RH0		0xF1
#define REG_RL1		0xF2
#define REG_RH1		0xF3
#define REG_RL2		0xF4
#define REG_RH2		0xF5
#define REG_RL3		0xF6
#define REG_RH3		0xF7
#define REG_RL4		0xF8
#define REG_RH4		0xF9
#define REG_RL5		0xFA
#define REG_RH5		0xFB
#define REG_RL6		0xFC
#define REG_RH6		0xFD
#define REG_RL7		0xFE
#define REG_RH7		0xFF

#define OPCODE_NONE			0
#define OPCODE_ORG			1
#define OPCODE_INSTRUCTION	2
#define OPCODE_DB			3
#define OPCODE_DW			4
#define OPCODE_DQ			5
#define OPCODE_LABEL		6
#define OPCODE_COMMENT		7
#define OPCODE_DIRECTIVE	8

#define OPCODE_ADD			1
#define OPCODE_ADDB			2
#define OPCODE_ADDC			3
#define OPCODE_ADDCB		4
#define OPCODE_AND			5
#define OPCODE_ANDB			6
#define OPCODE_ATOMIC		7
#define OPCODE_CALLA		8
#define OPCODE_CALLI		9
#define OPCODE_CALLS		10
#define OPCODE_CMP			11
#define OPCODE_CMPB			12
#define OPCODE_DISWDT		13
#define OPCODE_DIV			14
#define OPCODE_DIVL			15
#define OPCODE_DIVLU		16
#define OPCODE_DIVU			17
#define OPCODE_EINIT		18
#define OPCODE_EXTR			19
#define OPCODE_EXTS			20
#define OPCODE_EXTP			21
#define OPCODE_IDLE			22
#define OPCODE_JMPI			23
#define OPCODE_JMPA			24
#define OPCODE_JMPS			25
#define OPCODE_MOVRR		26
#define OPCODE_MOVRD		27
#define OPCODE_MOVRI		28
#define OPCODE_MOVIR		29
#define OPCODE_MOVBRR		30
#define OPCODE_MOVBRD		31
#define OPCODE_MOVBRI		32
#define OPCODE_MOVBIR		33
#define OPCODE_MUL			34
#define OPCODE_MULU			35
#define OPCODE_NEG			36
#define OPCODE_NEGB			37
#define OPCODE_NOP			38
#define OPCODE_OR			39
#define OPCODE_ORB			40
#define OPCODE_POP			41
#define OPCODE_PUSH			42
#define OPCODE_RET			43
#define OPCODE_RETI			44
#define OPCODE_RETS			45
#define OPCODE_SHL			46
#define OPCODE_SHR			47
#define OPCODE_SRST			48
#define OPCODE_SUB			49
#define OPCODE_SUBB			50
#define OPCODE_SUBC			51
#define OPCODE_SUBCB		52
#define OPCODE_XOR			53
#define OPCODE_XORB			54		

#define OPCODE_MOVRDL		55

class CJavaC16XSmallAsm;

struct CKeyLabel 
{
	CKeyLabel();
	CKeyLabel(std::string,int);
	virtual ~CKeyLabel();

	std::string m_sLabel_name;
	int m_iValue;
};

struct KeyLabel_less : std::binary_function<CKeyLabel,CKeyLabel,bool> 
{
	bool operator()(const CKeyLabel&,const CKeyLabel&) const;
};

struct COpcodeRecord
{
	COpcodeRecord();

	int m_iType;
	std::string m_sString;
	int m_iOpcode;
	int m_iParam1;
	int m_iParam2;
	int m_iParam3;
	int m_iParam4;
};

class COpcodeC16X  
{
public:
	COpcodeC16X();
	virtual ~COpcodeC16X();

	////////////////////////////
	// set methods
	////////////////////////////
	void Org(int);
	void Label(std::string);
	void Comment(std::string);
	void Directive(std::string);
	void DB(int);
	void DW(int);
	void DQ(int,int);
	
	////////////////////////////
	// instruction methods
	////////////////////////////
	void Add(int rwn,int rwm);
	void Addb(int rbn,int rbm);
	void Addc(int rwn,int rwm);
	void Addcb(int rbn,int rbm);
	void And(int rwn,int rwm);
	void Andb(int rbn,int rbm);
	void Atomic(int irang2);
	void Calla(int cc,std::string _label);
	void Calli(int cc,int rwn);
	void Calls(int seg,std::string _label);
	void Cmp(int rwn,int rwm);
	void Cmpb(int rbn,int rbm);
	void Diswdt();
	void Div(int rwn);
	void Divl(int rwn);
	void Divlu(int rwn);
	void Divu(int rwn);
	void Einit();
	void Extr(int irang2);
	void Exts(int rwn,int irang2);
	void Extp(int rwn,int irang2);
	void Idle();
	void Jmpi(int cc,int rwn);
	void Jmpa(int cc,std::string _label);
	void Jmps(int seg,std::string _label);
	void Movrr(int rwn,int rwm);
	void Movrd(int reg,int data16);
	void Movrdl(int reg,std::string _label);
	void Movri(int rwn,int rwm);
	void Movir(int rwm,int rwn);
	void Movbrr(int rbn,int rbm);
	void Movbrd(int reg,int data16);
	void Movbri(int rbn,int rbm);
	void Movbir(int rbm,int rbn);
	void Mul(int rwn,int rwm);
	void Mulu(int rwn,int rwm);
	void Neg(int rwn);
	void Negb(int rbn);
	void Nop();
	void Or(int rwn,int rwm);
	void Orb(int rbn,int rbm);
	void Pop(int reg);
	void Push(int reg);
	void Ret();
	void Reti();
	void Rets();
	void Shl(int rwn,int rwm);
	void Shr(int rwn,int rwm);
	void Srst();
	void Sub(int rwn,int rwm);
	void Subb(int rbn,int rbm);
	void Subc(int rwn,int rwm);
	void Subcb(int rbn,int rbm);
	void Xor(int rwn,int rwm);
	void Xorb(int rbn,int rbm);

	////////////////////////////
	// compile methods
	////////////////////////////
	int SizeOfInstruction(int);
	void CompileStepAsm(std::ofstream*,COpcodeRecord&);
	void CompileStepBin(COpcodeRecord&);

	void Compile(std::ofstream*);
	void CompileAsm(std::ofstream*);
	void CompileBin(std::ofstream*);
	
	void SetOrigin(int);
	int  Next();
	int  GetLabel(std::string);
	std::string GetCC(int);
	std::string GetRW(int);
	std::string GetRB(int);
	std::string GetREG(int,bool);

	unsigned char LoByte(int);
	unsigned char HiByte(int);

private:
	std::vector<COpcodeRecord> m_vOut;
	std::set<CKeyLabel,KeyLabel_less> m_stLabel;

	int	m_iCurrent_origin;
	int m_iMax_origin;
	unsigned char m_cbBin_buffer[MAX_BIN_SIZE];
	unsigned char m_cFill;
	int m_iOutput_format;

	friend class CJavaC16XSmallAsm;
};

__JAVA_C16X_END

#endif // !defined(AFX_OPCODEC16X_H__A3400DE0_9380_11D7_B7E0_AF572FFEC74F__INCLUDED_)
