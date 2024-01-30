//////////////////////////////////////////////////
//
// Проект: библиотека классов С++ для создания 
// трансляторов
//
// Имя: PeterCompiler
//
// Автор: Петров Петя 
//
// 
// Заголовочний файл
// 
//
// Дата начала проекта: 06.11.2002
// Дата последней модификации: 27.03.2003
//
//////////////////////////////////////////////////
#if !defined(__PETER_COMPILER_INCLUDED__)
#define __PETER_COMPILER_INCLUDED__

#define __PETER_COMPILER_BEGIN namespace CPeterCompiler{
#define __PETER_COMPILER_END }

#pragma warning( disable: 4786 )
//////////////////////////////////////////////////
// STL include
#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>
//////////////////////////////////////////////////

#include "State.h"
#include "Jump.h"
#include "Event.h"
#include "Tree.h"
#include "Exception.h"
#include "LexemException.h"
#include "LexemNotFoundException.h"
#include "MainNotFoundException.h"
#include "NotLL1Exception.h"
#include "ReferenceException.h"
#include "SemanticException.h"
#include "SyntaxException.h"
#include "UndeterminateException.h"
#include "Key.h"
#include "LevelMachine.h"
#include "TableMItem.h"
#include "Unterminal.h"
#include "ResultLexem.h"
#include "ResultLexemSet.h"
#include "StateMachine.h"
#include "StateMachineSet.h"
#include "Scanner.h"
#include "Compiler.h"
#include "Syntax.h"

#endif