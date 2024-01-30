 
/////////////////////////////////////////////
// Rule semantic analisys
/////////////////////////////////////////////

#include <windows.h>
#include <winuser.h>
#include <winbase.h>

bool CJavaC16XCompiler::SemanticItem1(CTree* root)
//:QualifiedIdentifiers
//(dot_lex)(identifier_lex)(QualifiedIdentifiers)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem2(CTree* root)
//:QualifiedIdentifiers
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem3(CTree* root)
//:QualifiedIdentifier
//(identifier_lex)(QualifiedIdentifiers)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem4(CTree* root)
//:Modifier
//(public_key_lex)
{
	m_sModifier="public";
	return true;
}

bool CJavaC16XCompiler::SemanticItem5(CTree* root)
//:Modifier
//(protected_key_lex)
{
	m_sModifier="protected";
	return true;
}

bool CJavaC16XCompiler::SemanticItem6(CTree* root)
//:Modifier
//(private_key_lex)
{
	m_sModifier="private";
	return true;
}

bool CJavaC16XCompiler::SemanticItem7(CTree* root)
//:Modifier
//(static_key_lex)
{
	m_sModifier="static";
	return true;
}

bool CJavaC16XCompiler::SemanticItem8(CTree* root)
//:Modifier
//(abstract_key_lex)
{
	m_sModifier="abstract";
	return true;
}

bool CJavaC16XCompiler::SemanticItem9(CTree* root)
//:Modifier
//(final_key_lex)
{
	m_sModifier="final";
	return true;
}

bool CJavaC16XCompiler::SemanticItem10(CTree* root)
//:Modifier
//(native_key_lex)
{
	m_sModifier="native";
	return true;
}

bool CJavaC16XCompiler::SemanticItem11(CTree* root)
//:Modifier
//(synchronized_key_lex)
{
	m_sModifier="synchronized";
	return true;
}

bool CJavaC16XCompiler::SemanticItem12(CTree* root)
//:Modifier
//(transient_key_lex)
{
	m_sModifier="transient";
	return true;
}

bool CJavaC16XCompiler::SemanticItem13(CTree* root)
//:Modifier
//(volatile_key_lex)
{
	m_sModifier="volatile";
	return true;
}

bool CJavaC16XCompiler::SemanticItem14(CTree* root)
//:Modifier
//(strictfp_key_lex)
{
	m_sModifier="strictfp";
	return true;
}

bool CJavaC16XCompiler::SemanticItem15(CTree* root)
//:ModifiersOpt
//(Modifier)(ModifiersOpt)
{
	Analisys(root->m_vComponents[0]);
	m_stModifiers.insert(m_sModifier);
	Analisys(root->m_vComponents[1]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem16(CTree* root)
//:ModifiersOpt
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem17(CTree* root)
//:BracketsOpt
//(sco1k_lex)(sco2k_lex)
{
	m_sBracket="[]";
	return true;
}

bool CJavaC16XCompiler::SemanticItem18(CTree* root)
//:BracketsOpt
{
	m_sBracket="";
	return true;
}

bool CJavaC16XCompiler::SemanticItem19(CTree* root)
//:BasicType
//(byte_key_lex)
{
	m_sType="byte";
	return true;
}

bool CJavaC16XCompiler::SemanticItem20(CTree* root)
//:BasicType
//(short_key_lex)
{
	m_sType="short";
	return true;
}

bool CJavaC16XCompiler::SemanticItem21(CTree* root)
//:BasicType
//(char_key_lex)
{
	m_sType="char";
	return true;
}

bool CJavaC16XCompiler::SemanticItem22(CTree* root)
//:BasicType
//(int_key_lex)
{
	m_sType="int";
	return true;
}

bool CJavaC16XCompiler::SemanticItem23(CTree* root)
//:BasicType
//(long_key_lex)
{
	m_sType="long";
	return true;
}

bool CJavaC16XCompiler::SemanticItem24(CTree* root)
//:BasicType
//(float_key_lex)
{
	m_sType="float";
	return true;
}

bool CJavaC16XCompiler::SemanticItem25(CTree* root)
//:BasicType
//(double_key_lex)
{
	m_sType="double";
	return true;
}

bool CJavaC16XCompiler::SemanticItem26(CTree* root)
//:BasicType
//(boolean_key_lex)
{
	m_sType="boolean";
	return true;
}

bool CJavaC16XCompiler::SemanticItem27(CTree* root)
//:Type_ids
//(dot_lex)(identifier_lex)(Type_ids)
{
	m_sType=m_sType+"."+root->m_vComponents[1]->m_sLexem_value;
	return true;
}

bool CJavaC16XCompiler::SemanticItem28(CTree* root)
//:Type_ids
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem29(CTree* root)
//:Type
//(identifier_lex)(Type_ids)(BracketsOpt)
{
	m_sType=root->m_vComponents[0]->m_sLexem_value;
	return true;
}

bool CJavaC16XCompiler::SemanticItem30(CTree* root)
//:Type
//(BasicType)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem31(CTree* root)
//:TypeLists
//(z_lex)(Type)(TypeLists)
{
	std::string type_name=m_sType;
	Analisys(root->m_vComponents[1]);
	m_stTypeList.insert(m_sType);
	m_sType=type_name;
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem32(CTree* root)
//:TypeLists
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem33(CTree* root)
//:TypeList
//(Type)(TypeLists)
{
	std::string type_name=m_sType;
	Analisys(root->m_vComponents[0]);
	m_stTypeList.insert(m_sType);
	m_sType=type_name;
	Analisys(root->m_vComponents[1]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem34(CTree* root)
//:AssigmentOperator
//(operator20_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem35(CTree* root)
//:AssigmentOperator
//(operator2_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem36(CTree* root)
//:AssigmentOperator
//(operator4_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem37(CTree* root)
//:AssigmentOperator
//(operator6_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem38(CTree* root)
//:AssigmentOperator
//(operator8_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem39(CTree* root)
//:AssigmentOperator
//(operator10_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem40(CTree* root)
//:AssigmentOperator
//(operator12_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem41(CTree* root)
//:AssigmentOperator
//(operator14_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem42(CTree* root)
//:AssigmentOperator
//(operator16_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem43(CTree* root)
//:AssigmentOperator
//(operator17_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem44(CTree* root)
//:AssigmentOperator
//(operator18_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem45(CTree* root)
//:AssigmentOperator
//(operator19_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem46(CTree* root)
//:PrefixOp
//(operator13_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem47(CTree* root)
//:PrefixOp
//(operator15_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem48(CTree* root)
//:PrefixOp
//(operator26_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem49(CTree* root)
//:PrefixOp
//(operator28_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem50(CTree* root)
//:PrefixOp
//(operator21_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem51(CTree* root)
//:PrefixOp
//(operator23_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem52(CTree* root)
//:PostfixOp
//(operator13_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem53(CTree* root)
//:PostfixOp
//(operator15_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem54(CTree* root)
//:Infixop
//(operator11_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem55(CTree* root)
//:Infixop
//(operator9_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem56(CTree* root)
//:Infixop
//(operator31_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem57(CTree* root)
//:Infixop
//(operator33_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem58(CTree* root)
//:Infixop
//(operator29_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem59(CTree* root)
//:Infixop
//(operator1_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem60(CTree* root)
//:Infixop
//(operator7_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem61(CTree* root)
//:Infixop
//(operator24_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem62(CTree* root)
//:Infixop
//(operator22_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem63(CTree* root)
//:Infixop
//(operator3_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem64(CTree* root)
//:Infixop
//(operator5_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem65(CTree* root)
//:Infixop
//(operator35_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem66(CTree* root)
//:Infixop
//(operator36_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem67(CTree* root)
//:Infixop
//(operator37_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem68(CTree* root)
//:Infixop
//(operator21_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem69(CTree* root)
//:Infixop
//(operator23_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem70(CTree* root)
//:Infixop
//(operator25_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem71(CTree* root)
//:Infixop
//(operator27_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem72(CTree* root)
//:Infixop
//(operator34_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem73(CTree* root)
//:IntegerLiteral
//(decimal_integer_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem74(CTree* root)
//:IntegerLiteral
//(hex_integer_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem75(CTree* root)
//:IntegerLiteral
//(octal_integer_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem76(CTree* root)
//:FloatingPointLiteral
//(floating_point_literal1_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem77(CTree* root)
//:FloatingPointLiteral
//(floating_point_literal2_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem78(CTree* root)
//:FloatingPointLiteral
//(floating_point_literal3_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem79(CTree* root)
//:FloatingPointLiteral
//(floating_point_literal4_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem80(CTree* root)
//:CharacterLiteral
//(char_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem81(CTree* root)
//:StringLiteral
//(string_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem82(CTree* root)
//:BooleanLiteral
//(boolean_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem83(CTree* root)
//:NullLiteral
//(null_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem84(CTree* root)
//:Literal
//(IntegerLiteral)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem85(CTree* root)
//:Literal
//(FloatingPointLiteral)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem86(CTree* root)
//:Literal
//(CharacterLiteral)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem87(CTree* root)
//:Literal
//(StringLiteral)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem88(CTree* root)
//:Literal
//(BooleanLiteral)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem89(CTree* root)
//:Literal
//(NullLiteral)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem90(CTree* root)
//:StatementExpression
//(Expression)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem91(CTree* root)
//:ConstantExpression
//(Expression)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem92(CTree* root)
//:ArgumentsOpt
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem93(CTree* root)
//:ArgumentsOpt
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem94(CTree* root)
//:ParExpression
//(sco1_lex)(Expression)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem95(CTree* root)
//:Block
//(sco1f_lex)(BlockStatements)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem96(CTree* root)
//:BlockStatements
//(BlockStatement)(BlockStatements)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem97(CTree* root)
//:BlockStatements
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem98(CTree* root)
//:BlockStatement
//(LocalVariableDeclarationStatement)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem99(CTree* root)
//:BlockStatement
//(ClassOrInterfaceDeclaration)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem100(CTree* root)
//:BlockStatement
//(Statement)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem101(CTree* root)
//:LocalVariableDeclarationStatement_ab
//(Type)(VariableDeclarators)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem102(CTree* root)
//:LocalVariableDeclarationStatement_ab
//(final_key_lex)(Type)(VariableDeclarators)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem103(CTree* root)
//:LocalVariableDeclarationStatement
//(local_key_lex)(LocalVariableDeclarationStatement_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem104(CTree* root)
//:Statement
//(Block)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem105(CTree* root)
//:Statement_else
//(else_key_lex)(Statement)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem106(CTree* root)
//:!else_key_lex!Statement_else
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem107(CTree* root)
//:Statement
//(if_key_lex)(ParExpression)(Statement)(Statement_else)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem108(CTree* root)
//:Statement_expr
//(Expression)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem109(CTree* root)
//:Statement_expr
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem110(CTree* root)
//:Statement
//(for_key_lex)(sco1_lex)(ForInitOpt)(dot_z_lex)(Statement_expr)(dot_z_lex)(ForUpdateOpt)(sco2_lex)(Statement)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem111(CTree* root)
//:Statement
//(while_key_lex)(ParExpression)(Statement)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem112(CTree* root)
//:Statement
//(do_key_lex)(Statement)(while_key_lex)(ParExpression)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem113(CTree* root)
//:Statement_catches
//(Catches)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem114(CTree* root)
//:Statement_catches
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem115(CTree* root)
//:Statement_finally
//(finally_key_lex)(Block)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem116(CTree* root)
//:Statement_finally
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem117(CTree* root)
//:Statement
//(try_key_lex)(Block)(Statement_catches)(Statement_finally)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem118(CTree* root)
//:Statement
//(switch_key_lex)(ParExpression)(sco1f_lex)(SwitchBlockStatementGroups)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem119(CTree* root)
//:Statement
//(synchexec_key_lex)(ParExpression)(Block)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem120(CTree* root)
//:Statement
//(return_key_lex)(Statement_expr)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem121(CTree* root)
//:Statement
//(throw_key_lex)(Expression)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem122(CTree* root)
//:Statement_id
//(identifier_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem123(CTree* root)
//:Statement_id
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem124(CTree* root)
//:Statement
//(break_key_lex)(Statement_id)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem125(CTree* root)
//:Statement
//(continue_key_lex)(Statement_id)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem126(CTree* root)
//:Statement
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem127(CTree* root)
//:Statement
//(StatementExpression)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem128(CTree* root)
//:Statement
//(label_key_lex)(identifier_lex)(operator32_lex)(Statement)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem129(CTree* root)
//:CatchClauses
//(CatchClause)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem130(CTree* root)
//:CatchClauses
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem131(CTree* root)
//:Catches
//(CatchClause)(CatchClauses)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem132(CTree* root)
//:CatchClause
//(catch_key_lex)(sco1_lex)(FormalParameter)(sco2_lex)(Block)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem133(CTree* root)
//:SwitchBlockStatementGroups
//(SwitchBlockStatementGroup)(SwitchBlockStatementGroups)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem134(CTree* root)
//:SwitchBlockStatementGroups
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem135(CTree* root)
//:SwitchBlockStatementGroup
//(SwitchLabel)(BlockStatements)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem136(CTree* root)
//:SwitchLabel
//(case_key_lex)(ConstantExpression)(operator32_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem137(CTree* root)
//:SwitchLabel
//(default_key_lex)(operator32_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem138(CTree* root)
//:MoreStatementExpressions
//(z_lex)(StatementExpression)(MoreStatementExpressions)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem139(CTree* root)
//:MoreStatementExpressions
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem140(CTree* root)
//:ForInitOpt
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem141(CTree* root)
//:ForInitOpt
//(ForInit)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem142(CTree* root)
//:ForUpdateOpt
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem143(CTree* root)
//:ForUpdateOpt
//(ForUpdate)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem144(CTree* root)
//:ForInit
//(StatementExpression)(MoreStatementExpressions)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem145(CTree* root)
//:ForInit
//(local_key_lex)(ForInit_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem146(CTree* root)
//:ForInit_ab
//(final_key_lex)(Type)(VariableDeclarators)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem147(CTree* root)
//:ForInit_ab
//(Type)(VariableDeclarators)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem148(CTree* root)
//:ForUpdate
//(StatementExpression)(MoreStatementExpressions)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem149(CTree* root)
//:VariableDeclaratorss
//(z_lex)(VariableDeclarator)(VariableDeclaratorss)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem150(CTree* root)
//:VariableDeclaratorss
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem151(CTree* root)
//:VariableDeclarators
//(VariableDeclarator)(VariableDeclaratorss)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem152(CTree* root)
//:VariableDeclaratorRests
//(z_lex)(VariableDeclaratorRest)(VariableDeclaratorRests)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem153(CTree* root)
//:VariableDeclaratorRests
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem154(CTree* root)
//:VariableDeclaratorsRest
//(VariableDeclaratorRest)(VariableDeclaratorRests)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem155(CTree* root)
//:ConstantDeclaratorRests
//(z_lex)(ConstantDeclaratorRest)(ConstantDeclaratorRests)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem156(CTree* root)
//:ConstantDeclaratorRests
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem157(CTree* root)
//:ConstantDeclaratorsRest
//(ConstantDeclaratorRest)(ConstantDeclaratorRests)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem158(CTree* root)
//:VariableDeclarator
//(identifier_lex)(VariableDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem159(CTree* root)
//:ConstantDeclarator1
//(identifier_lex)(ConstantDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem160(CTree* root)
//:VariableDeclaratorRest_equ
//(operator20_lex)(VariableInitializer)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem161(CTree* root)
//:VariableDeclaratorRest_equ
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem162(CTree* root)
//:VariableDeclaratorRest
//(BracketsOpt)(VariableDeclaratorRest_equ)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem163(CTree* root)
//:ClassBodyDeclaration
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem164(CTree* root)
//:ClassBodyDeclaration
//(ModifiersOpt)(MemberDecl)
{
	//TODO:
	m_stModifiers.clear();
	Analisys(root->m_vComponents[0]);
	m_bData=false;
	m_bMethod=false;
	Analisys(root->m_vComponents[1]);
	if (m_bData)
	{
		if ((*m_itCurClass).m_stStaticData.find(m_dfData)!=(*m_itCurClass).m_stStaticData.end())
			throw CSemanticException("variable always declared:"+m_dfData.m_sId,root->m_sFile_source,root->m_lLine);
		if ((*m_itCurClass).m_stHeapData.find(m_dfData)!=(*m_itCurClass).m_stHeapData.end())
			throw CSemanticException("variable always declared:"+m_dfData.m_sId,root->m_sFile_source,root->m_lLine);
		std::string st;
		st="private";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_dfData.m_iAccess=CI_ACCESS_PRIVATE;
		st="protected";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_dfData.m_iAccess=CI_ACCESS_PROTECTED;
		st="public";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_dfData.m_iAccess=CI_ACCESS_PUBLIC;
		st="static";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
		{//static data
			m_dfData.m_iId=GetMaxStaticId()+1;
			(*m_itCurClass).m_stStaticData.insert(m_dfData);
		}else
		{//heap data
			m_dfData.m_iId=GetMaxHeapId()+1;
			(*m_itCurClass).m_stHeapData.insert(m_dfData);
		}
	}else
	{//method
		std::string st;
		st="private";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_meMethod.m_iAccess=CI_ACCESS_PRIVATE;
		st="protected";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_meMethod.m_iAccess=CI_ACCESS_PROTECTED;
		st="public";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_meMethod.m_iAccess=CI_ACCESS_PUBLIC;
		st="static";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_meMethod.m_bStatic=true;
		else
			m_meMethod.m_bStatic=false;
		m_meMethod.GenName();
		m_meMethod.m_iId=GetMaxMethodId()+1;
		(*m_itCurClass).m_stMethod.insert(m_meMethod);
	}
	return false;
}

bool CJavaC16XCompiler::SemanticItem165(CTree* root)
//:MemberDecl
//(MethodOrFieldDecl)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem166(CTree* root)
//:MemberDecl
//(void_key_lex)(identifier_lex)(MethodDeclaratorRest)
{
	m_bMethod=true;
	m_bData=false;
	m_meMethod.m_sName=root->m_vComponents[1]->m_sLexem_value;
	m_meMethod.m_dfReturn.m_bStd_type=true;
	m_meMethod.m_dfReturn.m_sType="void";
	m_meMethod.m_vFormalParameters.clear();
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem167(CTree* root)
//:MemberDecl
//(constructor_key_lex)(identifier_lex)(ConstructorDeclaratorRest)
{
	m_bMethod=true;
	m_bData=false;
	m_meMethod.m_sName=root->m_vComponents[1]->m_sLexem_value;
	m_meMethod.m_dfReturn.m_bStd_type=true;
	m_meMethod.m_dfReturn.m_sType="constructor";
	m_meMethod.m_vFormalParameters.clear();
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem168(CTree* root)
//:MemberDecl
//(ClassOrInterfaceDeclaration_ab)
{
	throw CSemanticException("nested classes not supported",root->m_sFile_source,root->m_lLine);
	return true;
}

bool CJavaC16XCompiler::SemanticItem169(CTree* root)
//:MemberDecl
//(Block)
{
	throw CSemanticException("block not supported",root->m_sFile_source,root->m_lLine);
	return true;
}

bool CJavaC16XCompiler::SemanticItem170(CTree* root)
//:MethodOrFieldDecl
//(Type)(identifier_lex)(MethodOrFieldRest)
{
	m_sType="";
	Analisys(root->m_vComponents[0]);
	{
		m_dfData.m_bStd_type=IsStdType(m_sType);
		m_dfData.m_sType=m_sType;
		m_dfData.m_sId=root->m_vComponents[1]->m_sLexem_value;
	}
	{
		m_meMethod.m_dfReturn.m_bStd_type=IsStdType(m_sType);
		m_meMethod.m_dfReturn.m_sType=m_sType;
		m_meMethod.m_sName=root->m_vComponents[1]->m_sLexem_value;
	}
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem171(CTree* root)
//:MethodOrFieldRest
//(VariableDeclaratorRest)
{
	m_bData=true;
	m_bMethod=false;
	return false;
}

bool CJavaC16XCompiler::SemanticItem172(CTree* root)
//:MethodOrFieldRest
//(MethodDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem173(CTree* root)
//:MethodDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem174(CTree* root)
//:MethodDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem175(CTree* root)
//:MethodDeclaratorRest_ab
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem176(CTree* root)
//:MethodDeclaratorRest_ab
//(MethodBody)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem177(CTree* root)
//:MethodDeclaratorRest
//(FormalParameters)(BracketsOpt)(MethodDeclaratorRest_throws)(MethodDeclaratorRest_ab)
{
	m_vFormalParameters.clear();
	Analisys(root->m_vComponents[0]);
	std::vector<CDataField>::iterator b,e,i;
	b=m_vFormalParameters.begin();
	e=m_vFormalParameters.end();
	m_meMethod.m_vFormalParameters.clear();
	for(i=b;i!=e;i++)
		m_meMethod.m_vFormalParameters.push_back(*i);
	m_bMethod=true;
	m_bData=false;
	Analisys(root->m_vComponents[3]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem178(CTree* root)
//:VoidMethodDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem179(CTree* root)
//:VoidMethodDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem180(CTree* root)
//:VoidMethodDeclaratorRest_ab
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem181(CTree* root)
//:VoidMethodDeclaratorRest_ab
//(MethodBody)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem182(CTree* root)
//:VoidMethodDeclaratorRest
//(FormalParameters)(VoidMethodDeclaratorRest_throws)(VoidMethodDeclaratorRest_ab)
{
	m_vFormalParameters.clear();
	Analisys(root->m_vComponents[0]);
	std::vector<CDataField>::iterator b,e,i;
	b=m_vFormalParameters.begin();
	e=m_vFormalParameters.end();
	m_meMethod.m_vFormalParameters.clear();
	for(i=b;i!=e;i++)
		m_meMethod.m_vFormalParameters.push_back(*i);
	m_bMethod=true;
	m_bData=false;
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem183(CTree* root)
//:ConstructorDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem184(CTree* root)
//:ConstructorDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem185(CTree* root)
//:ConstructorDeclaratorRest_ab
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem186(CTree* root)
//:ConstructorDeclaratorRest_ab
//(MethodBody)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem187(CTree* root)
//:ConstructorDeclaratorRest
//(FormalParameters)(ConstructorDeclaratorRest_throws)(ConstructorDeclaratorRest_ab)
{
	m_vFormalParameters.clear();
	Analisys(root->m_vComponents[0]);
	std::vector<CDataField>::iterator b,e,i;
	b=m_vFormalParameters.begin();
	e=m_vFormalParameters.end();
	m_meMethod.m_vFormalParameters.clear();
	for(i=b;i!=e;i++)
		m_meMethod.m_vFormalParameters.push_back(*i);
	m_bMethod=true;
	m_bData=false;
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem188(CTree* root)
//:MethodBody
//(Block)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem189(CTree* root)
//:Selector_ab
//(identifier_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem190(CTree* root)
//:Selector_ab
//(this_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem191(CTree* root)
//:Selector_ab
//(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem192(CTree* root)
//:Selector_ab
//(super_key_lex)(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem193(CTree* root)
//:Selector_ab
//(new_key_lex)(InnerCreator)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem194(CTree* root)
//:Selector
//(dot_lex)(Selector_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem195(CTree* root)
//:Selector_bc
//(Expression)(sco2k_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem196(CTree* root)
//:Selector_bc
//(sco2k_lex)(BracketsOpt)(dot_lex)(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem197(CTree* root)
//:Selector
//(sco1k_lex)(Selector_bc)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem198(CTree* root)
//:Selector
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem199(CTree* root)
//:InnerCreator
//(identifier_lex)(ClassCreatorRest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem200(CTree* root)
//:IdentifierSuffix2_ab
//(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem201(CTree* root)
//:IdentifierSuffix2_ab
//(this_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem202(CTree* root)
//:IdentifierSuffix2_ab
//(super_key_lex)(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem203(CTree* root)
//:IdentifierSuffix2_ab
//(new_key_lex)(InnerCreator)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem204(CTree* root)
//:IdentifierSuffix1_ab
//(sco2k_lex)(BracketsOpt)(dot_lex)(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem205(CTree* root)
//:IdentifierSuffix1_ab
//(Expression)(sco2k_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem206(CTree* root)
//:IdentifierSuffix
//(sco1k_lex)(IdentifierSuffix1_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem207(CTree* root)
//:IdentifierSuffix
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem208(CTree* root)
//:IdentifierSuffix
//(dot_lex)(IdentifierSuffix2_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem209(CTree* root)
//:ClassCreatorRest_classbody
//(local_key_lex)(ClassBody)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem210(CTree* root)
//:ClassCreatorRest_classbody
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem211(CTree* root)
//:ClassCreatorRest
//(Arguments)(ClassCreatorRest_classbody)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem212(CTree* root)
//:ArrayCreatorRest_abss
//(Expression)(sco2k_lex)(ArrayCreatorRest_abs)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem213(CTree* root)
//:ArrayCreatorRest_abss
//(sco2k_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem214(CTree* root)
//:ArrayCreatorRest_abs
//(sco1k_lex)(ArrayCreatorRest_abss)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem215(CTree* root)
//:ArrayCreatorRest_abs
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem216(CTree* root)
//:ArrayCreatorRest_ab
//(sco2k_lex)(BracketsOpt)(ArrayInitializer)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem217(CTree* root)
//:ArrayCreatorRest_ab
//(Expression)(sco2k_lex)(ArrayCreatorRest_abs)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem218(CTree* root)
//:ArrayCreatorRest
//(sco1k_lex)(ArrayCreatorRest_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem219(CTree* root)
//:Creator_ab
//(ArrayCreatorRest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem220(CTree* root)
//:Creator_ab
//(ClassCreatorRest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem221(CTree* root)
//:Creator
//(QualifiedIdentifier)(Creator_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem222(CTree* root)
//:SuperSuffix_arguments
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem223(CTree* root)
//:SuperSuffix_arguments
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem224(CTree* root)
//:SuperSuffix
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem225(CTree* root)
//:SuperSuffix
//(dot_lex)(identifier_lex)(SuperSuffix_arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem226(CTree* root)
//:Arguments2
//(z_lex)(Expression)(Arguments2)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem227(CTree* root)
//:Arguments2
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem228(CTree* root)
//:Arguments1
//(Expression)(Arguments2)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem229(CTree* root)
//:Arguments1
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem230(CTree* root)
//:Arguments
//(sco1_lex)(Arguments1)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem231(CTree* root)
//:Primary2
//(new_key_lex)(Creator)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem232(CTree* root)
//:Primary1
//(this_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem233(CTree* root)
//:Primary1
//(super_key_lex)(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem234(CTree* root)
//:Primary1
//(Literal)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem235(CTree* root)
//:Primary1
//(identifier_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem236(CTree* root)
//:Primary1
//(BasicType)(BracketsOpt)(dot_lex)(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem237(CTree* root)
//:Primary1
//(void_key_lex)(dot_lex)(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem238(CTree* root)
//:Primary
//(sco1_lex)(Expression)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem239(CTree* root)
//:Primary
//(Primary1)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem240(CTree* root)
//:Expression3_ab
//(Expression)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem241(CTree* root)
//:Expression3_ab
//(cast_key_lex)(Type)(sco2_lex)(Expression3)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem242(CTree* root)
//:Expression3
//(PrefixOp)(Expression3)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem243(CTree* root)
//:Expression3
//(sco1_lex)(Expression3_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem244(CTree* root)
//:PostfixOps
//(PostfixOp)(PostfixOps)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem245(CTree* root)
//:PostfixOps
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem246(CTree* root)
//:Selectors
//(Selector)(Selectors)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem247(CTree* root)
//:Selectors
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem248(CTree* root)
//:Expression3
//(Primary1)(Selectors)(PostfixOps)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem249(CTree* root)
//:Expression3
//(Primary2)(PostfixOps)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem250(CTree* root)
//:Expression2Rest_s
//(Infixop)(Expression3)(Expression2Rest_s)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem251(CTree* root)
//:Expression2Rest_s
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem252(CTree* root)
//:Expression2Rest
//(Infixop)(Expression3)(Expression2Rest_s)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem253(CTree* root)
//:Expression2Rest
//(instanceof_key_lex)(Type)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem254(CTree* root)
//:Expression2Rest
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem255(CTree* root)
//:Expression2
//(Expression3)(Expression2Rest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem256(CTree* root)
//:Expression1Rest
//(operator30_lex)(Expression)(operator32_lex)(Expression1)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem257(CTree* root)
//:Expression1Rest
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem258(CTree* root)
//:Expression1
//(Expression2)(Expression1Rest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem259(CTree* root)
//:Expression_s
//(AssigmentOperator)(Expression1)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem260(CTree* root)
//:Expression_s
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem261(CTree* root)
//:Expression
//(Expression1)(Expression_s)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem262(CTree* root)
//:ArrayInitializer3
//(VariableInitializer)(ArrayInitializer2)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem263(CTree* root)
//:ArrayInitializer3
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem264(CTree* root)
//:ArrayInitializer2
//(z_lex)(ArrayInitializer3)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem265(CTree* root)
//:ArrayInitializer2
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem266(CTree* root)
//:ArrayInitializer1
//(VariableInitializer)(ArrayInitializer2)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem267(CTree* root)
//:ArrayInitializer1
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem268(CTree* root)
//:ArrayInitializer
//(sco1f_lex)(ArrayInitializer1)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem269(CTree* root)
//:VariableInitializer
//(ArrayInitializer)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem270(CTree* root)
//:VariableInitializer
//(Expression)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem271(CTree* root)
//:ConstantDeclaratorRest
//(BracketsOpt)(operator20_lex)(VariableInitializer)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem272(CTree* root)
//:VariableDeclaratorId
//(identifier_lex)(BracketsOpt)
{
	m_sVariableId=root->m_vComponents[0]->m_sLexem_value;
	return false;
}

bool CJavaC16XCompiler::SemanticItem273(CTree* root)
//:FormalParameter_final
//(final_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem274(CTree* root)
//:FormalParameter_final
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem275(CTree* root)
//:FormalParameter
//(FormalParameter_final)(Type)(VariableDeclaratorId)
{
	Analisys(root->m_vComponents[1]);
	m_dfFormalParameter.m_bStd_type=IsStdType(m_sType);
	m_dfFormalParameter.m_sType=m_sType;
	Analisys(root->m_vComponents[2]);
	m_dfFormalParameter.m_sId=m_sVariableId;
	return false;
}

bool CJavaC16XCompiler::SemanticItem276(CTree* root)
//:FormalParameters1s
//(z_lex)(FormalParameter)(FormalParameters1s)
{
	Analisys(root->m_vComponents[1]);
	m_vFormalParameters.push_back(m_dfFormalParameter);
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem277(CTree* root)
//:FormalParameters1s
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem278(CTree* root)
//:FormalParameters1
//(FormalParameter)(FormalParameters1s)
{
	Analisys(root->m_vComponents[0]);
	m_vFormalParameters.push_back(m_dfFormalParameter);
	Analisys(root->m_vComponents[1]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem279(CTree* root)
//:FormalParameters1
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem280(CTree* root)
//:FormalParameters
//(sco1_lex)(FormalParameters1)(sco2_lex)
{
	m_vFormalParameters.clear();
	return true;
}

bool CJavaC16XCompiler::SemanticItem281(CTree* root)
//:QualifiedIdentifierList1s
//(z_lex)(QualifiedIdentifier)(QualifiedIdentifierList1s)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem282(CTree* root)
//:QualifiedIdentifierList1s
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem283(CTree* root)
//:QualifiedIdentifierList
//(QualifiedIdentifier)(QualifiedIdentifierList1s)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem284(CTree* root)
//:InterfaceMethodDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem285(CTree* root)
//:InterfaceMethodDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem286(CTree* root)
//:InterfaceMethodDeclaratorRest
//(FormalParameters)(BracketsOpt)(InterfaceMethodDeclaratorRest_throws)(dot_z_lex)
{
	m_vFormalParameters.clear();
	Analisys(root->m_vComponents[0]);
	std::vector<CDataField>::iterator b,e,i;
	b=m_vFormalParameters.begin();
	e=m_vFormalParameters.end();
	m_meMethod.m_vFormalParameters.clear();
	for(i=b;i!=e;i++)
		m_meMethod.m_vFormalParameters.push_back(*i);
	m_bMethod=true;
	m_bData=false;
	return false;
}

bool CJavaC16XCompiler::SemanticItem287(CTree* root)
//:InterfaceMethodOrFieldRest
//(ConstantDeclaratorsRest)(dot_z_lex)
{
	throw CSemanticException("constant declaration not supported in interface",root->m_sFile_source,root->m_lLine);
	return true;
}

bool CJavaC16XCompiler::SemanticItem288(CTree* root)
//:InterfaceMethodOrFieldRest
//(InterfaceMethodDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem289(CTree* root)
//:InterfaceMethodOrFieldDecl
//(Type)(identifier_lex)(InterfaceMethodOrFieldRest)
{
	m_sType="";
	Analisys(root->m_vComponents[0]);
	{
		m_dfData.m_bStd_type=IsStdType(m_sType);
		m_dfData.m_sType=m_sType;
		m_dfData.m_sId=root->m_vComponents[1]->m_sLexem_value;
	}
	{
		m_meMethod.m_dfReturn.m_bStd_type=IsStdType(m_sType);
		m_meMethod.m_dfReturn.m_sType=m_sType;
		m_meMethod.m_sName=root->m_vComponents[1]->m_sLexem_value;
	}
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem290(CTree* root)
//:VoidInterfaceMethodDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem291(CTree* root)
//:VoidInterfaceMethodDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem292(CTree* root)
//:VoidInterfaceMethodDeclaratorRest
//(FormalParameters)(VoidInterfaceMethodDeclaratorRest_throws)(dot_z_lex)
{
	m_vFormalParameters.clear();
	Analisys(root->m_vComponents[0]);
	std::vector<CDataField>::iterator b,e,i;
	b=m_vFormalParameters.begin();
	e=m_vFormalParameters.end();
	m_meMethod.m_vFormalParameters.clear();
	for(i=b;i!=e;i++)
		m_meMethod.m_vFormalParameters.push_back(*i);
	return false;
}

bool CJavaC16XCompiler::SemanticItem293(CTree* root)
//:InterfaceMemberDecl
//(InterfaceMethodOrFieldDecl)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem294(CTree* root)
//:InterfaceMemberDecl
//(void_key_lex)(identifier_lex)(VoidInterfaceMethodDeclaratorRest)
{
	m_bMethod=true;
	m_bData=false;
	m_meMethod.m_sName=root->m_vComponents[1]->m_sLexem_value;
	m_meMethod.m_dfReturn.m_bStd_type=true;
	m_meMethod.m_dfReturn.m_sType="void";
	m_meMethod.m_vFormalParameters.clear();
	Analisys(root->m_vComponents[2]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem295(CTree* root)
//:InterfaceMemberDecl
//(ClassOrInterfaceDeclaration_ab)
{
	throw CSemanticException("nested interface or class not supported",root->m_sFile_source,root->m_lLine);
	return true;
}

bool CJavaC16XCompiler::SemanticItem296(CTree* root)
//:InterfaceBodyDeclaration
//(ModifiersOpt)(InterfaceMemberDecl)
{
	//TODO:
	m_stModifiers.clear();
	Analisys(root->m_vComponents[0]);
	m_bData=false;
	m_bMethod=false;
	Analisys(root->m_vComponents[1]);
	if (m_bData)
	{
		if ((*m_itCurInterface).m_stStaticData.find(m_dfData)!=(*m_itCurInterface).m_stStaticData.end())
			throw CSemanticException("variable always declared:"+m_dfData.m_sId,root->m_sFile_source,root->m_lLine);
		if ((*m_itCurInterface).m_stHeapData.find(m_dfData)!=(*m_itCurInterface).m_stHeapData.end())
			throw CSemanticException("variable always declared:"+m_dfData.m_sId,root->m_sFile_source,root->m_lLine);
		std::string st;
		st="private";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_dfData.m_iAccess=CI_ACCESS_PRIVATE;
		st="protected";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_dfData.m_iAccess=CI_ACCESS_PROTECTED;
		st="public";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_dfData.m_iAccess=CI_ACCESS_PUBLIC;
		st="static";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
		{//static data
			m_dfData.m_iId=GetMaxStaticId()+1;
			(*m_itCurInterface).m_stStaticData.insert(m_dfData);
		}else
		{//heap data
			m_dfData.m_iId=GetMaxHeapId()+1;
			(*m_itCurInterface).m_stHeapData.insert(m_dfData);
		}
	}else
	{//method
		std::string st;
		st="private";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_meMethod.m_iAccess=CI_ACCESS_PRIVATE;
		st="protected";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_meMethod.m_iAccess=CI_ACCESS_PROTECTED;
		st="public";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_meMethod.m_iAccess=CI_ACCESS_PUBLIC;
		st="static";
		if (m_stModifiers.find(st)!=m_stModifiers.end())
			m_meMethod.m_bStatic=true;
		else
			m_meMethod.m_bStatic=false;
		m_meMethod.GenName();
		m_meMethod.m_iId=GetMaxMethodId()+1;
		(*m_itCurInterface).m_stMethod.insert(m_meMethod);
	}
	return false;
}

bool CJavaC16XCompiler::SemanticItem297(CTree* root)
//:InterfaceBodyDeclaration
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem298(CTree* root)
//:ClassBodyDeclarations
//(ClassBodyDeclaration)(ClassBodyDeclarations)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem299(CTree* root)
//:ClassBodyDeclarations
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem300(CTree* root)
//:ClassBody
//(sco1f_lex)(ClassBodyDeclarations)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem301(CTree* root)
//:InterfaceBodyDeclarations
//(InterfaceBodyDeclaration)(InterfaceBodyDeclarations)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem302(CTree* root)
//:InterfaceBodyDeclarations
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem303(CTree* root)
//:InterfaceBody
//(sco1f_lex)(InterfaceBodyDeclarations)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem304(CTree* root)
//:ClassDeclaration_extends
//(extends_key_lex)(Type)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem305(CTree* root)
//:ClassDeclaration_extends
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem306(CTree* root)
//:ClassDeclaration_implements
//(implements_key_lex)(TypeList)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem307(CTree* root)
//:ClassDeclaration_implements
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem308(CTree* root)
//:ClassDeclaration
//(class_key_lex)(identifier_lex)(ClassDeclaration_extends)(ClassDeclaration_implements)(ClassBody)
{
	std::string class_name;
	class_name=root->m_vComponents[1]->m_sLexem_value;
	CClass new_class;
	new_class.m_sId=class_name;
	std::set<CClass,Class_less>::iterator i;
	i=m_stClasses.find(new_class);
	if (i!=m_stClasses.end())
		throw CSemanticException("class:"+class_name+" always declared",root->m_sFile_source,root->m_lLine);
	i=m_stInterfaces.find(new_class);
	if (i!=m_stInterfaces.end())
		throw CSemanticException("interface:"+class_name+" always declared",root->m_sFile_source,root->m_lLine);

//	m_stTempExtends.clear();
//	m_stTempImplements.clear();
	m_stTypeList.clear();
	Analisys(root->m_vComponents[3]);
	std::set<std::string>::iterator j,b,e;
	b=m_stTypeList.begin();
	e=m_stTypeList.end();
	new_class.m_stHeapData.clear();
	new_class.m_stStaticData.clear();
	new_class.m_stMethod.clear();
	new_class.m_stImplements.clear();
	for(j=b;j!=e;j++)
	{
		CClass tmp_class;
		tmp_class.m_sId=(*j);
		i=m_stInterfaces.find(tmp_class);
		if (i==m_stInterfaces.end())
			throw CSemanticException("interface:"+tmp_class.m_sId+" not defined",root->m_sFile_source,root->m_lLine);
		new_class.m_stImplements.insert(tmp_class.m_sId);
		CClass& tmp_class1=(*i);

		std::set<CDataField,DataField_less>::iterator i1,b1,e1;
		b1=tmp_class1.m_stStaticData.begin();
		e1=tmp_class1.m_stStaticData.end();
		for(i1=b1;i1!=e1;i1++)
			new_class.m_stStaticData.insert(*i1);

		std::set<CMethod,Method_less>::iterator i2,b2,e2;
		b2=tmp_class1.m_stMethod.begin();
		e2=tmp_class1.m_stMethod.end();
		for(i2=b2;i2!=e2;i2++)
			new_class.m_stMethod.insert(*i2);
		
	}
	m_sType="";
	Analisys(root->m_vComponents[2]);
	if (m_sType=="") 
	{
		new_class.m_bIs_extends=false;
		new_class.m_sExtends_class="";
	}
	else
	{
		new_class.m_bIs_extends=true;
		new_class.m_sExtends_class=m_sType;
		CClass tmp_class;
		tmp_class.m_sId=m_sType;
		i=m_stClasses.find(tmp_class);
		if (i==m_stClasses.end())
			throw CSemanticException("class:"+m_sType+" not defined",root->m_sFile_source,root->m_lLine);
	}

	m_itCurClass=m_stClasses.insert(new_class).first;
	Analisys(root->m_vComponents[4]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem309(CTree* root)
//:InterfaceDeclaration_extends
//(extends_key_lex)(TypeList)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem310(CTree* root)
//:InterfaceDeclaration_extends
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem311(CTree* root)
//:InterfaceDeclaration
//(interface_key_lex)(identifier_lex)(InterfaceDeclaration_extends)(InterfaceBody)
{
	std::string interface_name;
	interface_name=root->m_vComponents[1]->m_sLexem_value;
	CClass new_interface;
	new_interface.m_sId=interface_name;
	std::set<CClass,Class_less>::iterator i;
	i=m_stClasses.find(new_interface);
	if (i!=m_stClasses.end())
		throw CSemanticException("class:"+interface_name+" always declared",root->m_sFile_source,root->m_lLine);
	i=m_stInterfaces.find(new_interface);
	if (i!=m_stInterfaces.end())
		throw CSemanticException("interface:"+interface_name+" always declared",root->m_sFile_source,root->m_lLine);
//	m_stTempExtends.clear();
//	m_stTempImplements.clear();
	m_stTypeList.clear();
	Analisys(root->m_vComponents[2]);
	std::set<std::string>::iterator j,b,e;
	b=m_stTypeList.begin();
	e=m_stTypeList.end();
	new_interface.m_bIs_extends=false;
	new_interface.m_sExtends_class="";
	new_interface.m_stHeapData.clear();
	new_interface.m_stStaticData.clear();
	new_interface.m_stMethod.clear();
	new_interface.m_stImplements.clear();
	for(j=b;j!=e;j++)
	{
		CClass tmp_class;
		tmp_class.m_sId=(*j);
		i=m_stInterfaces.find(tmp_class);
		if (i==m_stInterfaces.end())
			throw CSemanticException("interface:"+tmp_class.m_sId+" not defined",root->m_sFile_source,root->m_lLine);
		new_interface.m_stImplements.insert(tmp_class.m_sId);
		CClass& tmp_class1=(*i);

		std::set<CDataField,DataField_less>::iterator i1,b1,e1;
		b1=tmp_class1.m_stStaticData.begin();
		e1=tmp_class1.m_stStaticData.end();
		for(i1=b1;i1!=e1;i1++)
			new_interface.m_stStaticData.insert(*i1);

		std::set<CMethod,Method_less>::iterator i2,b2,e2;
		b2=tmp_class1.m_stMethod.begin();
		e2=tmp_class1.m_stMethod.end();
		for(i2=b2;i2!=e2;i2++)
			new_interface.m_stMethod.insert(*i2);
		
	}
	m_itCurInterface=m_stInterfaces.insert(new_interface).first;
	Analisys(root->m_vComponents[3]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem312(CTree* root)
//:ClassOrInterfaceDeclaration_ab
//(ClassDeclaration)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem313(CTree* root)
//:ClassOrInterfaceDeclaration_ab
//(InterfaceDeclaration)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem314(CTree* root)
//:ClassOrInterfaceDeclaration
//(ModifiersOpt)(ClassOrInterfaceDeclaration_ab)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem315(CTree* root)
//:TypeDeclaration
//(ClassOrInterfaceDeclaration)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem316(CTree* root)
//:TypeDeclaration
//(dot_z_lex)
{
	return true;
}

std::string Import_path;

bool CJavaC16XCompiler::SemanticItem317(CTree* root)
//:ImportDeclaration_identifiers_ab
//(identifier_lex)(ImportDeclaration_identifiers)
{
	Import_path=Import_path+root->m_vComponents[0]->m_sLexem_value;
	Analisys(root->m_vComponents[1]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem318(CTree* root)
//:ImportDeclaration_identifiers_ab
//(operator25_lex)
{
	throw CSemanticException("mask * not support, import package: "+Import_path,root->m_sFile_source,root->m_lLine);
	return false;
}

bool CJavaC16XCompiler::SemanticItem319(CTree* root)
//:ImportDeclaration_identifiers
//(dot_lex)(ImportDeclaration_identifiers_ab)
{
	Import_path=Import_path+"\\";
	Analisys(root->m_vComponents[1]);
	return false;
}

bool CJavaC16XCompiler::SemanticItem320(CTree* root)
//:ImportDeclaration_identifiers
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem321(CTree* root)
//:ImportDeclaration
//(import_key_lex)(identifier_lex)(ImportDeclaration_identifiers)(dot_z_lex)
{
	Import_path=root->m_vComponents[1]->m_sLexem_value;
	Analisys(root->m_vComponents[2]);

	CScanner*			Scanner=new CScanner();
	CSyntax*			Syntax=new CSyntax(*Scanner);
	std::string			file_name;
	std::string			file_name_full;

	file_name=Import_path;
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

	std::cout<<"SubCompiling ("+file_name_full+")..."<<std::endl;
	char clspath[10000]="\0";
	std::string clsp="";
	GetEnvironmentVariable("CLASS_PATH",clspath,10000);
	if (clspath[0]=='\0')
	{
		throw CSemanticException("system variable CLASS_PATH not set",root->m_sFile_source,root->m_lLine);
	}
	if (clspath[strlen(clspath)-1]=='\\')
		clsp=std::string(clspath);
	else
		clsp=std::string(clspath)+'\\';
	Scanner->CreateLexem("java_lex.syn");
	Scanner->Scan(clsp+file_name_full);
	Syntax->CreateLL1("java_syn.syn");
	Syntax->Syntax();
	Analisys(Syntax->m_pRoot);
	delete root->m_vComponents[0];
	root->m_vComponents[0]=Syntax->m_pRoot->m_vComponents[0];	

	return false;
}

bool CJavaC16XCompiler::SemanticItem322(CTree* root)
//:ImportDeclarations
//(ImportDeclaration)(ImportDeclarations)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem323(CTree* root)
//:ImportDeclarations
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem324(CTree* root)
//:TypeDeclarations
//(TypeDeclaration)(TypeDeclarations)
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem325(CTree* root)
//:TypeDeclarations
{
	return true;
}

bool CJavaC16XCompiler::SemanticItem326(CTree* root)
//:CompilationUnit
//(package_key_lex)(QualifiedIdentifier)(dot_z_lex)(ImportDeclarations)(TypeDeclarations)
{
	m_sPackage_name=GetQualifiedIdentifier(root->m_vComponents[1]);
	return true;
}

bool CJavaC16XCompiler::SemanticItem327(CTree* root)
//:CompilationUnit
//(ImportDeclarations)(TypeDeclarations)
{
	m_sPackage_name="";
	return true;
}

int global_id=0;

void EnumData(CClass& cl)
{
	cl.EnumHeapData();
	cl.EnumStaticData();
	cl.m_icls_id=++global_id;
}

bool CJavaC16XCompiler::SemanticItem328(CTree* root)
//:main
//(CompilationUnit)
{
	Analisys(root->m_vComponents[0]);
	global_id=0;
	std::for_each(m_stClasses.begin(),m_stClasses.end(),EnumData);
	std::for_each(m_stInterfaces.begin(),m_stInterfaces.end(),EnumData);
#if defined(_DEBUG)
	std::set<CClass,Class_less>::iterator b,e,i;
	b=m_stClasses.begin();
	e=m_stClasses.end();
	for(i=b;i!=e;i++)
	{
		CClass &tmp_class=*i;
		m_ptTarget->Comment("class "+tmp_class.m_sId);
		if (tmp_class.m_bIs_extends) m_ptTarget->Comment("extends "+tmp_class.m_sExtends_class);
		m_ptTarget->Comment("implements");
		std::set<std::string>::iterator b1,e1,i1;
		b1=tmp_class.m_stImplements.begin();
		e1=tmp_class.m_stImplements.end();
		for(i1=b1;i1!=e1;i1++)
		{
			m_ptTarget->Comment("\t"+*i1);
		}
		std::set<CMethod,Method_less>::iterator b2,e2,i2;
		b2=tmp_class.m_stMethod.begin();
		e2=tmp_class.m_stMethod.end();
		for(i2=b2;i2!=e2;i2++)
		{
			std::string c="";
			CMethod &tmp_method=*i2;
			if (tmp_method.m_bStatic)
				c="static\t";
			if (tmp_method.m_iAccess==CI_ACCESS_NO_ACCESS)
				c=c+"no access\t";
			if (tmp_method.m_iAccess==CI_ACCESS_PRIVATE)
				c=c+"private\t";
			if (tmp_method.m_iAccess==CI_ACCESS_PROTECTED)
				c=c+"protected\t";
			if (tmp_method.m_iAccess==CI_ACCESS_PUBLIC)
				c=c+"public\t";
			c=c+tmp_method.m_sId;
			m_ptTarget->Comment(c);
		}

		std::set<CDataField,DataField_less>::iterator b3,e3,i3;
		b3=tmp_class.m_stHeapData.begin();
		e3=tmp_class.m_stHeapData.end();
		for(i3=b3;i3!=e3;i3++)
		{
			std::string c="";
			CDataField &tmp_data=*i3;
			if (tmp_data.m_iAccess==CI_ACCESS_NO_ACCESS)
				c="heap no access\t";
			if (tmp_data.m_iAccess==CI_ACCESS_PRIVATE)
				c="heap private\t";
			if (tmp_data.m_iAccess==CI_ACCESS_PROTECTED)
				c="heap protected\t";
			if (tmp_data.m_iAccess==CI_ACCESS_PUBLIC)
				c="heap public\t";
			c=c+tmp_data.m_sType+" "+tmp_data.m_sId;
			m_ptTarget->Comment(c);
		}
		b3=tmp_class.m_stStaticData.begin();
		e3=tmp_class.m_stStaticData.end();
		for(i3=b3;i3!=e3;i3++)
		{
			std::string c="";
			CDataField &tmp_data=*i3;
			if (tmp_data.m_iAccess==CI_ACCESS_NO_ACCESS)
				c="static no access\t";
			if (tmp_data.m_iAccess==CI_ACCESS_PRIVATE)
				c="static private\t";
			if (tmp_data.m_iAccess==CI_ACCESS_PROTECTED)
				c="static protected\t";
			if (tmp_data.m_iAccess==CI_ACCESS_PUBLIC)
				c="static public\t";
			c=c+tmp_data.m_sType+" "+tmp_data.m_sId;
			m_ptTarget->Comment(c);
		}

	}
	b=m_stInterfaces.begin();
	e=m_stInterfaces.end();
	for(i=b;i!=e;i++)
	{
		CClass &tmp_class=*i;
		m_ptTarget->Comment("interface "+tmp_class.m_sId);
		m_ptTarget->Comment("implements");
		std::set<std::string>::iterator b1,e1,i1;
		b1=tmp_class.m_stImplements.begin();
		e1=tmp_class.m_stImplements.end();
		for(i1=b1;i1!=e1;i1++)
		{
			m_ptTarget->Comment("\t"+*i1);
		}
		std::set<CMethod,Method_less>::iterator b2,e2,i2;
		b2=tmp_class.m_stMethod.begin();
		e2=tmp_class.m_stMethod.end();
		for(i2=b2;i2!=e2;i2++)
		{
			std::string c="";
			CMethod &tmp_method=*i2;
			if (tmp_method.m_bStatic)
				c="static\t";
			if (tmp_method.m_iAccess==CI_ACCESS_NO_ACCESS)
				c=c+"no access\t";
			if (tmp_method.m_iAccess==CI_ACCESS_PRIVATE)
				c=c+"private\t";
			if (tmp_method.m_iAccess==CI_ACCESS_PROTECTED)
				c=c+"protected\t";
			if (tmp_method.m_iAccess==CI_ACCESS_PUBLIC)
				c=c+"public\t";
			c=c+tmp_method.m_sId;
			m_ptTarget->Comment(c);
		}

	}
#endif
	return false;
}

