// JavaC16XSmallAsm.cpp: implementation of the CJavaC16XSmallAsm class.
//
//////////////////////////////////////////////////////////////////////

#include "JavaC16XSmallAsm.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

extern int FORMAT;

__JAVA_C16X_BEGIN

#define new_line "\r\n"

CJavaC16XSmallAsm::CJavaC16XSmallAsm():
m_sOut(NULL),
m_iPrg_len(0xB000),
m_iRom_seg(0x0000),
m_iRam_seg(0x0010),
m_iHep_seg(0x0011)
{

}

CJavaC16XSmallAsm::~CJavaC16XSmallAsm()
{

}

void CJavaC16XSmallAsm::BeginCompile(std::ofstream &out)
{
	m_sOut=&out;
}

void CJavaC16XSmallAsm::EndCompile()
{
	m_opOut.m_iOutput_format=FORMAT;
	m_opOut.Compile(m_sOut);
}

void CJavaC16XSmallAsm::Prolog()
{
	m_opOut.Comment("JavaC16X Compiler auto generated.");
	m_opOut.Comment("RAM_seg  = 10h");
	m_opOut.Comment("ROM_seg  = 00h");
	m_opOut.Comment("PRG_len  = B000h");
	m_opOut.Comment("HEP_seg  = 11h");
	m_opOut.Org(0x0000);
	m_opOut.Jmpa(CC_UC,"system_start");
}

void CJavaC16XSmallAsm::Epilog()
{
	m_opOut.Org(0x0000);
	m_opOut.Directive("end");
}

void CJavaC16XSmallAsm::FlashLoader()
{
	m_opOut.Org(0x0200);
	m_opOut.Label("system_start");
	m_opOut.Movrd(REG_SYSCON,0x0084);
	m_opOut.Movrd(REG_BUSCON0,0x04BF);
	m_opOut.Movrd(REG_ADDRSEL1,0x1006);
	m_opOut.Movrd(REG_BUSCON1,0x04BF);
	m_opOut.Movrd(REG_BUSCON2,0x0000);
	m_opOut.Movrd(REG_BUSCON3,0x0000);
	m_opOut.Movrd(REG_BUSCON4,0x0000);
	m_opOut.Movrd(REG_ADDRSEL2,0x0000);
	m_opOut.Movrd(REG_ADDRSEL3,0x0000);
	m_opOut.Movrd(REG_ADDRSEL4,0x0000);
	m_opOut.Diswdt();
	m_opOut.Einit();
	m_opOut.Label("system_loader");
	m_opOut.Movrd(REG_R1,0x0000);
	m_opOut.Movrd(REG_R2,m_iPrg_len);
	m_opOut.Movrd(REG_R3,m_iRom_seg);
	m_opOut.Movrd(REG_R4,m_iRam_seg);
	m_opOut.Movrd(REG_R6,0x0002);
	m_opOut.Label("system_loop_loader");
	m_opOut.Exts(R3,0x01);
	m_opOut.Movri(R5,R1);
	m_opOut.Exts(R4,0x01);
	m_opOut.Movir(R1,R5);
	m_opOut.Add(R1,R6);
	m_opOut.Cmp(R1,R2);
	m_opOut.Jmpa(CC_ULE,"system_loop_loader");
	m_opOut.Jmps(m_iRam_seg,"system_initialization");
}

void CJavaC16XSmallAsm::Initialization()
{
	m_opOut.Label("system_initialization");
}

void CJavaC16XSmallAsm::System_gc()
{
	m_opOut.Label("system_heap_initialization");
	m_opOut.Comment("IN:  NONE");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Push(REG_R6);
	m_opOut.Push(REG_R7);
	m_opOut.Push(REG_R8);
	m_opOut.Push(REG_R9);
	m_opOut.Push(REG_R10);
	m_opOut.Movrd(REG_R6,m_iHep_seg);
	m_opOut.Movrd(REG_R7,0x0000);
	m_opOut.Movrd(REG_R8,0x0800);
	m_opOut.Movrd(REG_R9,0x0002);
	m_opOut.Movrd(REG_R10,0x0000);
	m_opOut.Label("system_heap_initialization_loop");
	m_opOut.Exts(R6,0x01);
	m_opOut.Movir(R7,R10);
	m_opOut.Add(R7,R9);
	m_opOut.Cmp(R7,R8);
	m_opOut.Jmpa(CC_ULE,"system_heap_initialization_loop");
	m_opOut.Pop(REG_R10);
	m_opOut.Pop(REG_R9);
	m_opOut.Pop(REG_R8);
	m_opOut.Pop(REG_R7);
	m_opOut.Pop(REG_R6);
	m_opOut.Ret();

	m_opOut.Label("system_heap_set_word");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - offset, R2 - word");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Calla(CC_UC,"system_null_check");
	m_opOut.Push(REG_R0);
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R6);
	m_opOut.Push(REG_R7);
	m_opOut.Push(REG_R8);
	m_opOut.Movrd(REG_R6,m_iHep_seg);
	m_opOut.Movrd(REG_R7,64);
	m_opOut.Label("system_heap_set_loop");
	m_opOut.Cmp(R1,R7);
	m_opOut.Jmpa(CC_ULT,"system_heap_set_ok");
	m_opOut.Sub(R1,R7);
	m_opOut.Exts(R6,0x01);
	m_opOut.Movri(R8,R0);
	m_opOut.Movrr(R0,R8);
	m_opOut.Calla(CC_UC,"system_null_check");
	m_opOut.Jmpa(CC_UC,"system_heap_set_loop");
	m_opOut.Label("system_heap_set_ok");
	m_opOut.Movrd(REG_R8,05);
	m_opOut.Shl(R0,R8);
	m_opOut.Add(R0,R1);
	m_opOut.Exts(R6,0x01);
	m_opOut.Movir(R0,R2);
	m_opOut.Pop(REG_R8);
	m_opOut.Pop(REG_R7);
	m_opOut.Pop(REG_R6);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Pop(REG_R0);
	m_opOut.Ret();

	m_opOut.Label("system_heap_get_word");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - offset");
	m_opOut.Comment("OUT: R0 - get`s word");
	m_opOut.Calla(CC_UC,"system_null_check");
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R6);
	m_opOut.Push(REG_R7);
	m_opOut.Push(REG_R8);
	m_opOut.Movrd(REG_R6,m_iHep_seg);
	m_opOut.Movrd(REG_R7,64);
	m_opOut.Label("system_heap_set_loop");
	m_opOut.Cmp(R1,R7);
	m_opOut.Jmpa(CC_ULT,"system_heap_set_ok");
	m_opOut.Sub(R1,R7);
	m_opOut.Exts(R6,0x01);
	m_opOut.Movri(R8,R0);
	m_opOut.Movrr(R0,R8);
	m_opOut.Calla(CC_UC,"system_null_check");
	m_opOut.Jmpa(CC_UC,"system_heap_set_loop");
	m_opOut.Label("system_heap_set_ok");
	m_opOut.Movrd(REG_R8,05);
	m_opOut.Shl(R0,R8);
	m_opOut.Add(R0,R1);
	m_opOut.Exts(R6,0x01);
	m_opOut.Movri(R1,R0);
	m_opOut.Movrr(R0,R1);
	m_opOut.Pop(REG_R8);
	m_opOut.Pop(REG_R7);
	m_opOut.Pop(REG_R6);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_heap_new_obj");
	m_opOut.Comment("IN:  R0 - cls_obj");
	m_opOut.Comment("OUT: R0 - ref_obj");
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Push(REG_R4);
	m_opOut.Push(REG_R5);
	m_opOut.Push(REG_R6);
	m_opOut.Push(REG_R7);
	m_opOut.Movrr(R4,R0);
	m_opOut.Calla(CC_UC,"system_get_heap_template_addr");
	m_opOut.Movri(R1,R0);
	m_opOut.Movrd(REG_R2,0x0003);
	m_opOut.Shl(R1,R2);
	// R4 cls_id R1 - count bytes R0 - pointer
	m_opOut.Movrr(R5,R1);
	m_opOut.Movrr(R3,R0);
	// R5 cb R4 cls_id R3 pt R1 - cb 
	m_opOut.Movrr(R0,R1);
	// R5 cb R4 cls_id R3 pt R0 - cb  
	m_opOut.Calla(CC_UC,"system_heap_get_mem");
	// R5 cb R4 cls_id R3 pt R0 ref_mem
	m_opOut.Movrd(REG_R1,0x0000);
	// R6=2 R5 cb R4 cls_id R3 pt R1 ph R0 ref_mem	
	m_opOut.Movrd(REG_R6,0x0002);
	m_opOut.Movrr(R2,R4);
	m_opOut.Calla(CC_UC,"system_heap_set_word");
	m_opOut.Label("system_heap_new_obj_loop");
	m_opOut.Add(R1,R6);
	m_opOut.Add(R3,R6);
	m_opOut.Movrd(REG_R7,0x0000);
	m_opOut.Cmp(R5,R7);
	m_opOut.Jmpa(CC_EQ,"system_heap_new_obj_ret");
	m_opOut.Sub(R5,R6);
	m_opOut.Movri(R2,R3);
	m_opOut.Calla(CC_UC,"system_heap_set_word");
	m_opOut.Jmpa(CC_UC,"system_heap_new_obj_loop");
	m_opOut.Label("system_heap_new_obj_ret");
	m_opOut.Pop(REG_R7);
	m_opOut.Pop(REG_R6);
	m_opOut.Pop(REG_R5);
	m_opOut.Pop(REG_R4);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_heap_delete_obj");
	m_opOut.Comment("IN:  R0 - ref_obj");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Ret();
	m_opOut.Label("system_heap_gc");
	m_opOut.Comment("IN:  NONE");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Comment("NOTE:SYSTEM G COLLECTOR");
	m_opOut.Ret();
	m_opOut.Label("system_gc_initialization");
	m_opOut.Comment("IN:  NONE");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Ret();

	m_opOut.Label("system_set_static");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - static_id, R2(lo),R3(hi) - value");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Push(REG_R0);
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Calla(CC_UC,"system_get_ref_cls");
	m_opOut.Calla(CC_UC,"system_get_cls_addr_static");
	m_opOut.Movir(R0,R2);
	m_opOut.Movrd(REG_R2,0x0002);
	m_opOut.Add(R0,R2);
	m_opOut.Movir(R0,R3);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Pop(REG_R0);
	m_opOut.Ret();

	m_opOut.Label("system_get_static");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - static_id");
	m_opOut.Comment("OUT: R0(lo),R1(hi) - value");
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Calla(CC_UC,"system_get_ref_cls");
	m_opOut.Calla(CC_UC,"system_get_cls_addr_static");
	m_opOut.Movrr(R2,R0);
	m_opOut.Movri(R0,R2);
	m_opOut.Movrd(REG_R3,0x0002);
	m_opOut.Add(R2,R3);
	m_opOut.Movri(R1,R2);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Ret();

	m_opOut.Label("system_set_heap");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - heap_id, R2(lo),R3(hi) - value");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Push(REG_R0);
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Push(REG_R4);
	m_opOut.Movrr(R4,R0);
	m_opOut.Calla(CC_UC,"system_get_ref_addr_heap");
	m_opOut.Movrr(R1,R0);
	m_opOut.Movrr(R0,R4);
	m_opOut.Calla(CC_UC,"system_heap_set_word");
	m_opOut.Movrr(R2,R3);
	m_opOut.Movrd(REG_R3,0x0002);
	m_opOut.Add(R1,R3);
	m_opOut.Calla(CC_UC,"system_heap_set_word");
	m_opOut.Pop(REG_R4);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Pop(REG_R0);
	m_opOut.Ret();

	m_opOut.Label("system_get_heap");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - heap_id");
	m_opOut.Comment("OUT: R0(lo),R1(hi) - value");
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Push(REG_R4);
	m_opOut.Movrr(R2,R0);
	m_opOut.Calla(CC_UC,"system_get_ref_addr_heap");
	m_opOut.Movrr(R1,R0);
	m_opOut.Movrr(R0,R2);
	m_opOut.Calla(CC_UC,"system_heap_get_word");
	m_opOut.Movrr(R3,R0);
	m_opOut.Movrd(REG_R0,0x0002);
	m_opOut.Add(R1,R0);
	m_opOut.Movrr(R0,R2);
	m_opOut.Calla(CC_UC,"system_heap_get_word");
	m_opOut.Movrr(R1,R0);
	m_opOut.Movrr(R0,R3);
	m_opOut.Pop(REG_R4);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Ret();

	m_opOut.Label("system_vcall");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - method_id");
	m_opOut.Comment("OUT: R0 - addr method");
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Push(REG_R4);
	m_opOut.Push(REG_R5);
	m_opOut.Calla(CC_UC,"system_get_ref_cls");
	m_opOut.Calla(CC_UC,"system_get_cls_rtti");
	m_opOut.Movrd(REG_R2,0x0006);
	m_opOut.Add(R0,R2);
	m_opOut.Movri(R2,R0);//r2 vtable
	m_opOut.Movri(R3,R2);
	m_opOut.Movrd(REG_R4,0x0002);
	m_opOut.Add(R2,R4);
	m_opOut.Movrd(REG_R4,0x0000);
	m_opOut.Label("system_vcall_loop");
	m_opOut.Cmp(R3,R4);
	m_opOut.Jmpa(CC_EQ,"system_vcall_ret");
	m_opOut.Movri(R5,R2);
	m_opOut.Cmp(R1,R5);
	m_opOut.Jmpa(CC_EQ,"system_vcall_ok");
	m_opOut.Movrd(REG_R5,0x0001);
	m_opOut.Sub(R3,R5);
	m_opOut.Movrd(REG_R5,6);
	m_opOut.Add(R2,R5);
	m_opOut.Jmpa(CC_UC,"system_vcall_loop");
	m_opOut.Label("system_vcall_ok");
	m_opOut.Movrd(REG_R5,0x0004);
	m_opOut.Add(R2,R5);
	m_opOut.Movri(R0,R2);
	m_opOut.Label("system_vcall_ret");
	m_opOut.Pop(REG_R5);
	m_opOut.Pop(REG_R4);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_get_ref_cls");
	m_opOut.Comment("IN:  R0 - ref_obj");
	m_opOut.Comment("OUT: R0 - cls_id");
	m_opOut.Push(REG_R1);
	m_opOut.Movrd(REG_R1,0x0000);
	m_opOut.Calla(CC_UC,"system_heap_get_word");
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_get_cls_rtti");
	m_opOut.Comment("IN:  R0 - cls_id");
	m_opOut.Comment("OUT: R0 - addr rtti");
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Push(REG_R4);
	m_opOut.Push(REG_R5);
	m_opOut.Push(REG_R6);
	m_opOut.Push(REG_R7);
	m_opOut.Push(REG_R8);
	m_opOut.Push(REG_R9);
	m_opOut.Push(REG_R10);
	m_opOut.Movrd(REG_R5,0x0002);
	m_opOut.Movrd(REG_R6,0x0000);
	m_opOut.Movrd(REG_R7,0x0001);
	m_opOut.Movrd(REG_R9,18);
	m_opOut.Movrdl(REG_R3,"system_rtti");
	m_opOut.Movri(R4,R3);
	m_opOut.Add(R3,R5);
	m_opOut.Label("system_get_cls_rtti_loop");
	m_opOut.Cmp(R4,R6);
	m_opOut.Jmpa(CC_EQ,"system_get_cls_rtti_ret");
	m_opOut.Movri(R8,R3);
	m_opOut.Cmp(R8,R0);
	m_opOut.Jmpa(CC_EQ,"system_get_cls_rtti_ok");
	m_opOut.Sub(R4,R7);
	m_opOut.Add(R3,R9);
	m_opOut.Movri(R10,R3);
	m_opOut.Shl(R10,R5);
	m_opOut.Add(R3,R10);
	m_opOut.Jmpa(CC_UC,"system_get_cls_rtti_loop");
	m_opOut.Label("system_get_cls_rtti_ok");
	m_opOut.Movrr(R0,R3);
	m_opOut.Label("system_get_cls_rtti_ret");
	m_opOut.Pop(REG_R10);
	m_opOut.Pop(REG_R9);
	m_opOut.Pop(REG_R8);
	m_opOut.Pop(REG_R7);
	m_opOut.Pop(REG_R6);
	m_opOut.Pop(REG_R5);
	m_opOut.Pop(REG_R4);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_get_cls_addr_static");
	m_opOut.Comment("IN:  R0 - cls_id, R1 - static_id");
	m_opOut.Comment("OUT: R0 - addr static");
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Push(REG_R4);
	m_opOut.Push(REG_R5);
	m_opOut.Calla(CC_UC,"system_get_cls_rtti");
	m_opOut.Movrd(REG_R2,10);
	m_opOut.Add(R0,R2);
	m_opOut.Movri(R2,R0);
	m_opOut.Movri(R3,R2);
	m_opOut.Movrd(REG_R4,0x0002);
	m_opOut.Add(R2,R4);
	m_opOut.Movrd(REG_R4,0x0000);
	m_opOut.Label("system_get_cls_addr_static_loop");
	m_opOut.Cmp(R3,R4);
	m_opOut.Jmpa(CC_EQ,"system_get_cls_addr_static_ret");
	m_opOut.Movri(R5,R2);
	m_opOut.Cmp(R5,R1);
	m_opOut.Jmpa(CC_EQ,"system_get_cls_addr_static_ok");
	m_opOut.Movrd(REG_R5,1);
	m_opOut.Sub(R3,R5);
	m_opOut.Movrd(REG_R5,8);
	m_opOut.Add(R2,R5);
	m_opOut.Jmpa(CC_UC,"system_get_cls_addr_static_loop");
	m_opOut.Label("system_get_cls_addr_static_ok");
	m_opOut.Movrd(REG_R5,2);
	m_opOut.Add(R2,R5);
	m_opOut.Movrr(R0,R2);
	m_opOut.Label("system_get_cls_addr_static_ret");
	m_opOut.Pop(REG_R5);
	m_opOut.Pop(REG_R4);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_null_check");
	m_opOut.Comment("IN:  R0 - ref_obj");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Push(REG_R1);
	m_opOut.Movrd(REG_R1,0x0040);
	m_opOut.Cmp(R0,R1);
	m_opOut.Jmpa(CC_UGT,"system_null_check_ret");
	m_opOut.Label("system_null");
	m_opOut.Movrd(REG_R0,0x0002);
	m_opOut.Jmpa(CC_UC,"system_null");
	m_opOut.Label("system_null_check_ret");
	m_opOut.Movrd(REG_R1,0x0FFF);
	m_opOut.And(R0,R1);
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_get_ref_addr_heap");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - heap_id");
	m_opOut.Comment("OUT: R0 - addr heap");
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Push(REG_R4);
	m_opOut.Push(REG_R5);
	m_opOut.Push(REG_R6);
	m_opOut.Movrr(R2,R1);
	m_opOut.Movrr(R3,R0);
	m_opOut.Movrd(REG_R1,0x0002);
	m_opOut.Calla(CC_UC,"system_heap_get_word");
	m_opOut.Movrr(R4,R0);
	m_opOut.Movrd(REG_R6,0x0004);
	m_opOut.Label("system_get_ref_addr_heap_loop");
	m_opOut.Movrd(REG_R5,0x0000);
	m_opOut.Cmp(R4,R5);
	m_opOut.Jmpa(CC_EQ,"system_get_ref_addr_heap_ret");
	m_opOut.Movrr(R0,R3);
	m_opOut.Movrr(R1,R6);
	m_opOut.Calla(CC_UC,"system_heap_get_word");
	m_opOut.Cmp(R0,R2);
	m_opOut.Jmpa(CC_EQ,"system_get_ref_addr_heap_ok");
	m_opOut.Movrd(REG_R0,0x0008);
	m_opOut.Add(R6,R0);
	m_opOut.Movrd(REG_R0,0x0001);
	m_opOut.Sub(R4,R0);
	m_opOut.Jmpa(CC_UC,"system_get_ref_addr_heap_loop");
	m_opOut.Label("system_get_ref_addr_heap_ok");
	m_opOut.Movrd(REG_R0,0x0002);
	m_opOut.Add(R0,R6);
	m_opOut.Label("system_get_ref_addr_heap_ret");
	m_opOut.Pop(REG_R6);
	m_opOut.Pop(REG_R5);
	m_opOut.Pop(REG_R4);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_get_heap_template_addr");
	m_opOut.Comment("IN:  R0 - cls_id");
	m_opOut.Comment("OUT: R0 - heap template addr");
	m_opOut.Push(REG_R1);
	m_opOut.Push(REG_R2);
	m_opOut.Push(REG_R3);
	m_opOut.Push(REG_R4);
	m_opOut.Calla(CC_UC,"system_get_cls_rtti");
	m_opOut.Movrd(REG_R1,14);
	m_opOut.Add(R1,R0);
	m_opOut.Movri(R0,R1);
	m_opOut.Pop(REG_R4);
	m_opOut.Pop(REG_R3);
	m_opOut.Pop(REG_R2);
	m_opOut.Pop(REG_R1);
	m_opOut.Ret();

	m_opOut.Label("system_heap_get_mem");
	m_opOut.Comment("IN:  R0 - count bytes");
	m_opOut.Comment("OUT: R0 - ref_mem");
	m_opOut.Ret();
	m_opOut.Label("system_instanceof");
	m_opOut.Comment("IN:  R0 - ref_obj, R1 - cls_id");
	m_opOut.Comment("OUT: R0 - bool if ref_obj instanceof cls_id");
	m_opOut.Ret();
	m_opOut.Label("system_lpvs_initialization");
	m_opOut.Comment("IN:  NONE");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Ret();
	m_opOut.Label("system_lrvs_initialization");
	m_opOut.Comment("IN:  NONE");
	m_opOut.Comment("OUT: NONE");
	m_opOut.Ret();

	m_opOut.Label("system_exception_abstract_method_call");
	m_opOut.Movrd(REG_R0,0x0001);
	m_opOut.Jmpa(CC_UC,"system_exception_abstract_method_call");
}

void CJavaC16XSmallAsm::RTTI(std::set<CClass,Class_less>& cl,std::set<CClass,Class_less>& in)
// RTTI & vtable
{
	CClass a;
	m_opOut.Label("system_rtti");
	std::set<CClass,Class_less>::iterator b,e,i;
	b=cl.begin();
	e=cl.end();
	m_opOut.DW(cl.size()+in.size());
	for(i=b;i!=e;i++)
	{
		CClass& clas=*i;
		m_opOut.Label("system_rtti_"+clas.m_sId);
		m_opOut.DW(clas.m_icls_id);
		m_opOut.DW(0);
		m_opOut.Jmpa(CC_UC,"system_vtable_"+clas.m_sId);
		m_opOut.Jmpa(CC_UC,"system_static_"+clas.m_sId);
		m_opOut.Jmpa(CC_UC,"system_heap_template_"+clas.m_sId);
		int s;
		if (clas.m_bIs_extends)
			m_opOut.DW(s=1);
		else
			m_opOut.DW(s=0);
		s+=clas.m_stImplements.size();
		m_opOut.DW(s);
		if (clas.m_bIs_extends)
		{
			std::set<CClass,Class_less>::iterator g;
			CClass tmp;
			tmp.m_sId=clas.m_sExtends_class;
			g=cl.find(tmp);
			m_opOut.DW((*g).m_icls_id);
		}
		std::set<std::string>::iterator b1,e1,i1;
		b1=clas.m_stImplements.begin();
		e1=clas.m_stImplements.end();
		for(i1=b1;i1!=e1;i1++)
		{
			std::string ic=*i1;
			std::set<CClass,Class_less>::iterator g;
			CClass tmp;
			tmp.m_sId=ic;
			g=in.find(tmp);
			m_opOut.DW((*g).m_icls_id);
		}
	}

	b=in.begin();
	e=in.end();
	for(i=b;i!=e;i++)
	{
		CClass &clas=*i;
		m_opOut.Label("system_rtti_"+clas.m_sId);
		m_opOut.DW(clas.m_icls_id);
		m_opOut.DW(1);
		m_opOut.Jmpa(CC_UC,"system_exception_abstract_method_call");
		m_opOut.DW(0);
		m_opOut.DW(0);
		m_opOut.DW(0);
		m_opOut.DW(0);
		int s=0;
		m_opOut.DW(s);
		s+=clas.m_stImplements.size();
		m_opOut.DW(s);
		std::set<std::string>::iterator b1,e1,i1;
		b1=clas.m_stImplements.begin();
		e1=clas.m_stImplements.end();
		for(i1=b1;i1!=e1;i1++)
		{
			std::string ic=*i1;
			std::set<CClass,Class_less>::iterator g;
			CClass tmp;
			tmp.m_sId=ic;
			g=in.find(tmp);
			m_opOut.DW((*g).m_icls_id);
		}
	}
	b=cl.begin();
	e=cl.end();
	m_opOut.Label("system_vtable");
	for(i=b;i!=e;i++)
	{
		CClass &clas=*i;
		m_opOut.Label("system_vtable_"+clas.m_sId);
		int sz=clas.m_stMethod.size();
		m_opOut.DW(sz);
		std::set<CMethod,Method_less>::iterator b2,e2,i2;
		b2=clas.m_stMethod.begin();
		e2=clas.m_stMethod.end();
		for(i2=b2;i2!=e2;i2++)
		{
			CMethod &method=*i2;
			m_opOut.DW(method.m_iId);
			m_opOut.Jmpa(CC_UC,"method_"+clas.m_sId+"_"+method.m_sId);
		}
	}
}

void CJavaC16XSmallAsm::StaticData(std::set<CClass,Class_less>& cl)
// static & heap template 
{
	m_opOut.Label("system_static");
	std::set<CClass,Class_less>::iterator b,e,i;
	b=cl.begin();
	e=cl.end();
	for(i=b;i!=e;i++)
	{
		CClass &clas=*i;
		m_opOut.Label("system_static_"+clas.m_sId);
		m_opOut.DW(clas.m_stStaticData.size());
		std::set<CDataField,DataField_less>::iterator b1,e1,i1;
		b1=clas.m_stStaticData.begin();
		e1=clas.m_stStaticData.end();
		for(i1=b1;i1!=e1;i1++)
		{
			m_opOut.Label("static_data_"+clas.m_sId+"_"+(*i1).m_sId);
			m_opOut.DW((*i1).m_iId);
			m_opOut.DW(0);
			m_opOut.DW(0);
			int s=0;
			if (IsStdType((*i1).m_sType)) s=0; else s=1;
			m_opOut.DW(s);
		}
	}

	m_opOut.Label("system_heap_template");
	b=cl.begin();
	e=cl.end();
	for(i=b;i!=e;i++)
	{
		CClass &clas=*i;
		m_opOut.Label("system_heap_template_"+clas.m_sId);
		m_opOut.DW(clas.m_stHeapData.size());
		std::set<CDataField,DataField_less>::iterator b1,e1,i1;
		b1=clas.m_stHeapData.begin();
		e1=clas.m_stHeapData.end();
		for(i1=b1;i1!=e1;i1++)
		{
			m_opOut.Label("heap_template_"+clas.m_sId+"_"+(*i1).m_sId);
			m_opOut.DW((*i1).m_iId);
			m_opOut.DW(0);
			m_opOut.DW(0);
			int s=0;
			if (IsStdType((*i1).m_sType)) s=0; else s=1;
			m_opOut.DW(s);
		}
	}
}

void CJavaC16XSmallAsm::Package(std::string _package)
{
	m_opOut.Comment("PACKAGE: "+_package);
}

void CJavaC16XSmallAsm::Comment(std::string _comment)
{
	m_opOut.Comment(_comment);
}

__JAVA_C16X_END
