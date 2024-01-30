// JavaC16X.cpp : Defines the entry point for the console application.
//

#include "PeterCompiler.h"
#include "JavaC16XCompiler.h"
#include "JavaC16XSmallAsm.h"
#include <windows.h>
#include <conio.h>

#define OUTPUT_FORMAT_ASM_KASKOD_ASM167		1
#define OUTPUT_FORMAT_BIN_KASKOD_FLASH168	2		

using namespace CPeterCompiler;
using namespace CJavaC16X;

int FORMAT=OUTPUT_FORMAT_ASM_KASKOD_ASM167;

int main(int argc, char* argv[])
{
	SYSTEMTIME s1,s2;
	
	GetLocalTime(&s1);
	CScanner			Scanner;
	CSyntax				Syntax(Scanner);
	CJavaC16XSmallAsm	SmallAsm;
	CJavaC16XCompiler	Compiler(&SmallAsm);
	std::string			file_name;
	std::string			file_name_full;
	std::string			file_name_output;

	std::cout<<"Java Compiler for C16X Family Version 1.00, By Peter."<<std::endl;
	if (argc<2)
	{
		std::cout<<"Use JavaC16X.exe filename format,"<<std::endl;
		std::cout<<"where filename is source JAVA code,"<<std::endl;
		std::cout<<"where format -"<<std::endl;
		std::cout<<"\t/1 - format ASM167 (default)"<<std::endl;
		std::cout<<"\t/2 - format BIN."<<std::endl;
		return 0;
	}else
	{
		file_name=argv[1];
		bool dot=false;
		int i,idot;
		for(i=0;i<file_name.size();i++)
			if (file_name[i]=='.')
			{
				dot=true;
				idot=i;
			}
		if (!dot)
			file_name_full=file_name+".java";
		else
		{
			file_name_full=file_name;
			file_name.erase(idot,file_name.size()-idot);
		}
		file_name_output=file_name+".asm";
		if (argc>=3)
		{
			if (!strcmp(argv[2],"/1"))
			{
				FORMAT=OUTPUT_FORMAT_ASM_KASKOD_ASM167;
				file_name_output=file_name+".asm";
			}
			if (!strcmp(argv[2],"/2"))
			{
				FORMAT=OUTPUT_FORMAT_BIN_KASKOD_FLASH168;
				file_name_output=file_name+".bin";
			}
		}
	}
	std::cout<<"Compiling ("+file_name_full+")..."<<std::endl;

	try{
		Scanner.CreateLexem("java_lex.syn");
		Scanner.Scan(file_name_full);
		Syntax.CreateLL1("java_syn.syn");
		Syntax.Syntax();
		std::cout<<"Outputing ("+file_name_output+")..."<<std::endl;
		Syntax.Compile(&Compiler,file_name_output);

	}
	catch(CReferenceException ex)
	{
		std::cout<<"***ERROR!!!***"<<std::endl;
		std::cout<<"reference error between "<<ex.m_sLexem1_name;
		std::cout<<" and "<<ex.m_sLexem2_name;
		std::cout<<std::endl;
		return 1;
	}
	catch(CUndeterminateException ex)
	{
		std::cout<<"***ERROR!!!***"<<std::endl;
		std::cout<<"undeterminate lexem: "<<ex.m_sLexem_name<<std::endl;
		std::cout<<"char_code: "<<(int)ex.m_cChar<<std::endl;
		std::cout<<std::endl;
		return 1;
	}
	catch(CLexemException ex)
	{
		std::cout<<"***ERROR!!!***"<<std::endl;
		if (ex.m_lLine!=-1)
		{
			std::cout<<"lexem error, file: "<<ex.m_sFile_name;
			std::cout<<" line: "<<ex.m_lLine<<" char_code: "<<(int)ex.m_cChar;
			std::cout<<" column: "<<ex.m_iColumn<<std::endl;
			std::cout<<std::endl;
		}else
		{
			std::cout<<"file: "+ex.m_sFile_name+" not found"<<std::endl;
		}
		return 1;
	}
	catch(CLexemNotFoundException ex)
	{
		std::cout<<"***ERROR!!!***"<<std::endl;
		std::cout<<"lexem not found: "<<ex.m_sLexem_name;
		std::cout<<std::endl;
		return 1;
	}
	catch(CNotLL1Exception ex)
	{
		std::cout<<"***ERROR!!!***"<<std::endl;
		std::cout<<"not LL1 gramar."<<std::endl;
		std::cout<<"rule1: "<<ex.m_sName1<<" -> "<<ex.m_sDesc1<<std::endl;
		std::cout<<"rule2: "<<ex.m_sName2<<" -> "<<ex.m_sDesc2<<std::endl;
		std::cout<<"symbol: "<<ex.m_sCommon<<std::endl;
		return 1;
	}
	catch(CMainNotFoundException ex)
	{
		std::cout<<"***ERROR!!!***"<<std::endl;
		std::cout<<"main not found"<<std::endl;
		return 1;
	}
	catch(CSyntaxException ex)
	{
		std::cout<<"***ERROR!!!***"<<std::endl;
		std::cout<<"syntax error"<<std::endl;
		std::cout<<"file: \""<<ex.m_sFile_name<<"\" ("<<ex.m_lLine<<")"<<std::endl;
		std::cout<<"wanted: "<<ex.m_sType_expected<<std::endl;
		std::cout<<"found: "<<ex.m_sValue_found<<"."<<ex.m_sType_found<<std::endl;
		return 1;
	}
	catch(CSemanticException ex)
	{
		std::cout<<"***ERROR!!!***"<<std::endl;
		std::cout<<"semantic error"<<std::endl;
		std::cout<<"file: \""<<ex.m_sFile_name<<"\" ("<<ex.m_lLine<<")"<<std::endl;
		std::cout<<ex.m_sDescription<<std::endl;
		return 1;
	}
	GetLocalTime(&s2);
	long time_sec;
	time_sec=((s2.wHour-s1.wHour)*60*60+(s2.wMinute-s1.wMinute)*60+s2.wSecond-s1.wSecond)*1000+s2.wMilliseconds-s1.wMilliseconds;
	std::cout<<"Translation complete: "<<time_sec/1000<<"."<<time_sec%1000<<" sec."<<std::endl;

	return 0;
}
