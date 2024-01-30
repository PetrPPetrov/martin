// This is a translator from Martin programming language to C language.
// Copyright (C) 2024 Petr Petrovich Petrov
//
// This file is part of Martin translator.
//
// Martin translator is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Martin translator is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Martin translator.  If not, see <http://www.gnu.org/licenses/>.

#include "scanner.h"

void CScanner::Scan(std::string file) throw(CPeterCompiler::CLexemException)
{
	std::ifstream outf;
	std::string s1,s2;

	char ch;
	bool error;
	long line=1;
	int id,option,column=0;

	outf.open(file.c_str(),std::ios::in|std::ios::binary);
	if (!outf.is_open())
	{
		throw CPeterCompiler::CLexemException(file,-1,' ',0);
	}

	m_sFile_source=file;
	m_rlsSet.Reset();
	m_smsSet.Prepare();
	m_smsSet.Prepare_LineTerminator();
	column++;
	outf.read(&ch,1);
	while(!outf.eof())
	{
		if (!m_smsSet.Scan_LineTerminator(ch,error))
		{
			if (!error)
			{
				line++;
				column=0;
			}
			m_smsSet.Prepare_LineTerminator();
		}
		if (!m_smsSet.Scan(ch,error))
		{
			if (error)
				throw CPeterCompiler::CLexemException(file,line,ch,column);
			else
			{
				m_smsSet.GetLastRightLexem(id,s1,s2,option);
				if (!(option&LEX_OPTION_COMMENT))
					m_rlsSet.AddLexem(id,s1,s2,line,m_sFile_source);
			}
			m_smsSet.Prepare();
			if (!m_smsSet.Scan(ch,error))
				throw CPeterCompiler::CLexemException(file,line,ch,column);
			
		}	
		column++;
		outf.read(&ch,1);
	}
	m_smsSet.GetLastRightLexem(id,s1,s2,option);
	if (!(option&LEX_OPTION_COMMENT))
		m_rlsSet.AddLexem(id,s1,s2,line,m_sFile_source);

#if defined(_DEBUG)
	m_rlsSet.Dump("tlexem");
#endif
}

void CScanner::CreateLexem(std::string lex)
{
	std::ifstream sFile(lex.c_str());
	sFile>>m_smsSet;
	sFile.close();	
	m_smsSet.Prepare();
}

void CScanner::Save(std::string file)
{
	std::ofstream outf(file.c_str());
	m_smsSet.Save(outf);
	outf.close();
}

void CScanner::Load(std::string file)
{
	std::ifstream outf(file.c_str());
	m_rlsSet.Reset();
	m_smsSet.Load(outf);
	outf.close();
}

void CScanner::Add(std::string _name,std::string _desc,int _option)
{
	m_smsSet.AddLexem(m_iCounterSM++,_name,_desc,_option);
}
		
void CScanner::EndInitialization()
{
	m_smsSet.Prepare();
}

__PETER_COMPILER_END