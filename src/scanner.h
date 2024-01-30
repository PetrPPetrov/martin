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

#pragma once

#include <string>

#define LEX_OPTION_DISABLED         1
#define LEX_OPTION_COMMENT          2
#define LEX_OPTION_LINE_TERMINATOR  4
#define LEX_OPTION_NONE             0

class Scanner
{
public:
    CScanner();
    virtual ~CScanner();

    void CreateLexem(std::string);
    void Scan(std::string) throw(CPeterCompiler::CLexemException);
    void Save(std::string);
    void Load(std::string);

    void Add(std::string,std::string,int);
    void EndInitialization();

public:
    //StateMachineSet m_smsSet;
    //CResultLexemSet m_rlsSet;
    std::string source_file;

private:
    int counter = 1;
};
