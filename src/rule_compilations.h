 
/////////////////////////////////////////////
// Rule compilations
/////////////////////////////////////////////

bool CJavaC16XCompiler::CompileItem1(CTree* root)
//:QualifiedIdentifiers
//(dot_lex)(identifier_lex)(QualifiedIdentifiers)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem2(CTree* root)
//:QualifiedIdentifiers
{
	return true;
}

bool CJavaC16XCompiler::CompileItem3(CTree* root)
//:QualifiedIdentifier
//(identifier_lex)(QualifiedIdentifiers)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem4(CTree* root)
//:Modifier
//(public_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem5(CTree* root)
//:Modifier
//(protected_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem6(CTree* root)
//:Modifier
//(private_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem7(CTree* root)
//:Modifier
//(static_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem8(CTree* root)
//:Modifier
//(abstract_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem9(CTree* root)
//:Modifier
//(final_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem10(CTree* root)
//:Modifier
//(native_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem11(CTree* root)
//:Modifier
//(synchronized_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem12(CTree* root)
//:Modifier
//(transient_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem13(CTree* root)
//:Modifier
//(volatile_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem14(CTree* root)
//:Modifier
//(strictfp_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem15(CTree* root)
//:ModifiersOpt
//(Modifier)(ModifiersOpt)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem16(CTree* root)
//:ModifiersOpt
{
	return true;
}

bool CJavaC16XCompiler::CompileItem17(CTree* root)
//:BracketsOpt
//(sco1k_lex)(sco2k_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem18(CTree* root)
//:BracketsOpt
{
	return true;
}

bool CJavaC16XCompiler::CompileItem19(CTree* root)
//:BasicType
//(byte_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem20(CTree* root)
//:BasicType
//(short_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem21(CTree* root)
//:BasicType
//(char_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem22(CTree* root)
//:BasicType
//(int_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem23(CTree* root)
//:BasicType
//(long_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem24(CTree* root)
//:BasicType
//(float_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem25(CTree* root)
//:BasicType
//(double_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem26(CTree* root)
//:BasicType
//(boolean_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem27(CTree* root)
//:Type_ids
//(dot_lex)(identifier_lex)(Type_ids)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem28(CTree* root)
//:Type_ids
{
	return true;
}

bool CJavaC16XCompiler::CompileItem29(CTree* root)
//:Type
//(identifier_lex)(Type_ids)(BracketsOpt)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem30(CTree* root)
//:Type
//(BasicType)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem31(CTree* root)
//:TypeLists
//(z_lex)(Type)(TypeLists)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem32(CTree* root)
//:TypeLists
{
	return true;
}

bool CJavaC16XCompiler::CompileItem33(CTree* root)
//:TypeList
//(Type)(TypeLists)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem34(CTree* root)
//:AssigmentOperator
//(operator20_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem35(CTree* root)
//:AssigmentOperator
//(operator2_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem36(CTree* root)
//:AssigmentOperator
//(operator4_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem37(CTree* root)
//:AssigmentOperator
//(operator6_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem38(CTree* root)
//:AssigmentOperator
//(operator8_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem39(CTree* root)
//:AssigmentOperator
//(operator10_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem40(CTree* root)
//:AssigmentOperator
//(operator12_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem41(CTree* root)
//:AssigmentOperator
//(operator14_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem42(CTree* root)
//:AssigmentOperator
//(operator16_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem43(CTree* root)
//:AssigmentOperator
//(operator17_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem44(CTree* root)
//:AssigmentOperator
//(operator18_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem45(CTree* root)
//:AssigmentOperator
//(operator19_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem46(CTree* root)
//:PrefixOp
//(operator13_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem47(CTree* root)
//:PrefixOp
//(operator15_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem48(CTree* root)
//:PrefixOp
//(operator26_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem49(CTree* root)
//:PrefixOp
//(operator28_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem50(CTree* root)
//:PrefixOp
//(operator21_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem51(CTree* root)
//:PrefixOp
//(operator23_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem52(CTree* root)
//:PostfixOp
//(operator13_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem53(CTree* root)
//:PostfixOp
//(operator15_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem54(CTree* root)
//:Infixop
//(operator11_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem55(CTree* root)
//:Infixop
//(operator9_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem56(CTree* root)
//:Infixop
//(operator31_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem57(CTree* root)
//:Infixop
//(operator33_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem58(CTree* root)
//:Infixop
//(operator29_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem59(CTree* root)
//:Infixop
//(operator1_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem60(CTree* root)
//:Infixop
//(operator7_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem61(CTree* root)
//:Infixop
//(operator24_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem62(CTree* root)
//:Infixop
//(operator22_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem63(CTree* root)
//:Infixop
//(operator3_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem64(CTree* root)
//:Infixop
//(operator5_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem65(CTree* root)
//:Infixop
//(operator35_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem66(CTree* root)
//:Infixop
//(operator36_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem67(CTree* root)
//:Infixop
//(operator37_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem68(CTree* root)
//:Infixop
//(operator21_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem69(CTree* root)
//:Infixop
//(operator23_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem70(CTree* root)
//:Infixop
//(operator25_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem71(CTree* root)
//:Infixop
//(operator27_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem72(CTree* root)
//:Infixop
//(operator34_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem73(CTree* root)
//:IntegerLiteral
//(decimal_integer_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem74(CTree* root)
//:IntegerLiteral
//(hex_integer_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem75(CTree* root)
//:IntegerLiteral
//(octal_integer_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem76(CTree* root)
//:FloatingPointLiteral
//(floating_point_literal1_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem77(CTree* root)
//:FloatingPointLiteral
//(floating_point_literal2_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem78(CTree* root)
//:FloatingPointLiteral
//(floating_point_literal3_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem79(CTree* root)
//:FloatingPointLiteral
//(floating_point_literal4_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem80(CTree* root)
//:CharacterLiteral
//(char_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem81(CTree* root)
//:StringLiteral
//(string_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem82(CTree* root)
//:BooleanLiteral
//(boolean_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem83(CTree* root)
//:NullLiteral
//(null_literal_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem84(CTree* root)
//:Literal
//(IntegerLiteral)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem85(CTree* root)
//:Literal
//(FloatingPointLiteral)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem86(CTree* root)
//:Literal
//(CharacterLiteral)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem87(CTree* root)
//:Literal
//(StringLiteral)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem88(CTree* root)
//:Literal
//(BooleanLiteral)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem89(CTree* root)
//:Literal
//(NullLiteral)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem90(CTree* root)
//:StatementExpression
//(Expression)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem91(CTree* root)
//:ConstantExpression
//(Expression)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem92(CTree* root)
//:ArgumentsOpt
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem93(CTree* root)
//:ArgumentsOpt
{
	return true;
}

bool CJavaC16XCompiler::CompileItem94(CTree* root)
//:ParExpression
//(sco1_lex)(Expression)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem95(CTree* root)
//:Block
//(sco1f_lex)(BlockStatements)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem96(CTree* root)
//:BlockStatements
//(BlockStatement)(BlockStatements)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem97(CTree* root)
//:BlockStatements
{
	return true;
}

bool CJavaC16XCompiler::CompileItem98(CTree* root)
//:BlockStatement
//(LocalVariableDeclarationStatement)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem99(CTree* root)
//:BlockStatement
//(ClassOrInterfaceDeclaration)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem100(CTree* root)
//:BlockStatement
//(Statement)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem101(CTree* root)
//:LocalVariableDeclarationStatement_ab
//(Type)(VariableDeclarators)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem102(CTree* root)
//:LocalVariableDeclarationStatement_ab
//(final_key_lex)(Type)(VariableDeclarators)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem103(CTree* root)
//:LocalVariableDeclarationStatement
//(local_key_lex)(LocalVariableDeclarationStatement_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem104(CTree* root)
//:Statement
//(Block)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem105(CTree* root)
//:Statement_else
//(else_key_lex)(Statement)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem106(CTree* root)
//:!else_key_lex!Statement_else
{
	return true;
}

bool CJavaC16XCompiler::CompileItem107(CTree* root)
//:Statement
//(if_key_lex)(ParExpression)(Statement)(Statement_else)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem108(CTree* root)
//:Statement_expr
//(Expression)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem109(CTree* root)
//:Statement_expr
{
	return true;
}

bool CJavaC16XCompiler::CompileItem110(CTree* root)
//:Statement
//(for_key_lex)(sco1_lex)(ForInitOpt)(dot_z_lex)(Statement_expr)(dot_z_lex)(ForUpdateOpt)(sco2_lex)(Statement)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem111(CTree* root)
//:Statement
//(while_key_lex)(ParExpression)(Statement)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem112(CTree* root)
//:Statement
//(do_key_lex)(Statement)(while_key_lex)(ParExpression)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem113(CTree* root)
//:Statement_catches
//(Catches)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem114(CTree* root)
//:Statement_catches
{
	return true;
}

bool CJavaC16XCompiler::CompileItem115(CTree* root)
//:Statement_finally
//(finally_key_lex)(Block)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem116(CTree* root)
//:Statement_finally
{
	return true;
}

bool CJavaC16XCompiler::CompileItem117(CTree* root)
//:Statement
//(try_key_lex)(Block)(Statement_catches)(Statement_finally)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem118(CTree* root)
//:Statement
//(switch_key_lex)(ParExpression)(sco1f_lex)(SwitchBlockStatementGroups)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem119(CTree* root)
//:Statement
//(synchexec_key_lex)(ParExpression)(Block)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem120(CTree* root)
//:Statement
//(return_key_lex)(Statement_expr)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem121(CTree* root)
//:Statement
//(throw_key_lex)(Expression)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem122(CTree* root)
//:Statement_id
//(identifier_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem123(CTree* root)
//:Statement_id
{
	return true;
}

bool CJavaC16XCompiler::CompileItem124(CTree* root)
//:Statement
//(break_key_lex)(Statement_id)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem125(CTree* root)
//:Statement
//(continue_key_lex)(Statement_id)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem126(CTree* root)
//:Statement
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem127(CTree* root)
//:Statement
//(StatementExpression)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem128(CTree* root)
//:Statement
//(label_key_lex)(identifier_lex)(operator32_lex)(Statement)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem129(CTree* root)
//:CatchClauses
//(CatchClause)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem130(CTree* root)
//:CatchClauses
{
	return true;
}

bool CJavaC16XCompiler::CompileItem131(CTree* root)
//:Catches
//(CatchClause)(CatchClauses)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem132(CTree* root)
//:CatchClause
//(catch_key_lex)(sco1_lex)(FormalParameter)(sco2_lex)(Block)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem133(CTree* root)
//:SwitchBlockStatementGroups
//(SwitchBlockStatementGroup)(SwitchBlockStatementGroups)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem134(CTree* root)
//:SwitchBlockStatementGroups
{
	return true;
}

bool CJavaC16XCompiler::CompileItem135(CTree* root)
//:SwitchBlockStatementGroup
//(SwitchLabel)(BlockStatements)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem136(CTree* root)
//:SwitchLabel
//(case_key_lex)(ConstantExpression)(operator32_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem137(CTree* root)
//:SwitchLabel
//(default_key_lex)(operator32_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem138(CTree* root)
//:MoreStatementExpressions
//(z_lex)(StatementExpression)(MoreStatementExpressions)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem139(CTree* root)
//:MoreStatementExpressions
{
	return true;
}

bool CJavaC16XCompiler::CompileItem140(CTree* root)
//:ForInitOpt
{
	return true;
}

bool CJavaC16XCompiler::CompileItem141(CTree* root)
//:ForInitOpt
//(ForInit)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem142(CTree* root)
//:ForUpdateOpt
{
	return true;
}

bool CJavaC16XCompiler::CompileItem143(CTree* root)
//:ForUpdateOpt
//(ForUpdate)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem144(CTree* root)
//:ForInit
//(StatementExpression)(MoreStatementExpressions)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem145(CTree* root)
//:ForInit
//(local_key_lex)(ForInit_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem146(CTree* root)
//:ForInit_ab
//(final_key_lex)(Type)(VariableDeclarators)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem147(CTree* root)
//:ForInit_ab
//(Type)(VariableDeclarators)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem148(CTree* root)
//:ForUpdate
//(StatementExpression)(MoreStatementExpressions)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem149(CTree* root)
//:VariableDeclaratorss
//(z_lex)(VariableDeclarator)(VariableDeclaratorss)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem150(CTree* root)
//:VariableDeclaratorss
{
	return true;
}

bool CJavaC16XCompiler::CompileItem151(CTree* root)
//:VariableDeclarators
//(VariableDeclarator)(VariableDeclaratorss)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem152(CTree* root)
//:VariableDeclaratorRests
//(z_lex)(VariableDeclaratorRest)(VariableDeclaratorRests)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem153(CTree* root)
//:VariableDeclaratorRests
{
	return true;
}

bool CJavaC16XCompiler::CompileItem154(CTree* root)
//:VariableDeclaratorsRest
//(VariableDeclaratorRest)(VariableDeclaratorRests)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem155(CTree* root)
//:ConstantDeclaratorRests
//(z_lex)(ConstantDeclaratorRest)(ConstantDeclaratorRests)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem156(CTree* root)
//:ConstantDeclaratorRests
{
	return true;
}

bool CJavaC16XCompiler::CompileItem157(CTree* root)
//:ConstantDeclaratorsRest
//(ConstantDeclaratorRest)(ConstantDeclaratorRests)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem158(CTree* root)
//:VariableDeclarator
//(identifier_lex)(VariableDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem159(CTree* root)
//:ConstantDeclarator1
//(identifier_lex)(ConstantDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem160(CTree* root)
//:VariableDeclaratorRest_equ
//(operator20_lex)(VariableInitializer)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem161(CTree* root)
//:VariableDeclaratorRest_equ
{
	return true;
}

bool CJavaC16XCompiler::CompileItem162(CTree* root)
//:VariableDeclaratorRest
//(BracketsOpt)(VariableDeclaratorRest_equ)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem163(CTree* root)
//:ClassBodyDeclaration
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem164(CTree* root)
//:ClassBodyDeclaration
//(ModifiersOpt)(MemberDecl)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem165(CTree* root)
//:MemberDecl
//(MethodOrFieldDecl)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem166(CTree* root)
//:MemberDecl
//(void_key_lex)(identifier_lex)(MethodDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem167(CTree* root)
//:MemberDecl
//(constructor_key_lex)(identifier_lex)(ConstructorDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem168(CTree* root)
//:MemberDecl
//(ClassOrInterfaceDeclaration_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem169(CTree* root)
//:MemberDecl
//(Block)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem170(CTree* root)
//:MethodOrFieldDecl
//(Type)(identifier_lex)(MethodOrFieldRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem171(CTree* root)
//:MethodOrFieldRest
//(VariableDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem172(CTree* root)
//:MethodOrFieldRest
//(MethodDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem173(CTree* root)
//:MethodDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem174(CTree* root)
//:MethodDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::CompileItem175(CTree* root)
//:MethodDeclaratorRest_ab
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem176(CTree* root)
//:MethodDeclaratorRest_ab
//(MethodBody)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem177(CTree* root)
//:MethodDeclaratorRest
//(FormalParameters)(BracketsOpt)(MethodDeclaratorRest_throws)(MethodDeclaratorRest_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem178(CTree* root)
//:VoidMethodDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem179(CTree* root)
//:VoidMethodDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::CompileItem180(CTree* root)
//:VoidMethodDeclaratorRest_ab
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem181(CTree* root)
//:VoidMethodDeclaratorRest_ab
//(MethodBody)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem182(CTree* root)
//:VoidMethodDeclaratorRest
//(FormalParameters)(VoidMethodDeclaratorRest_throws)(VoidMethodDeclaratorRest_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem183(CTree* root)
//:ConstructorDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem184(CTree* root)
//:ConstructorDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::CompileItem185(CTree* root)
//:ConstructorDeclaratorRest_ab
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem186(CTree* root)
//:ConstructorDeclaratorRest_ab
//(MethodBody)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem187(CTree* root)
//:ConstructorDeclaratorRest
//(FormalParameters)(ConstructorDeclaratorRest_throws)(ConstructorDeclaratorRest_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem188(CTree* root)
//:MethodBody
//(Block)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem189(CTree* root)
//:Selector_ab
//(identifier_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem190(CTree* root)
//:Selector_ab
//(this_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem191(CTree* root)
//:Selector_ab
//(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem192(CTree* root)
//:Selector_ab
//(super_key_lex)(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem193(CTree* root)
//:Selector_ab
//(new_key_lex)(InnerCreator)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem194(CTree* root)
//:Selector
//(dot_lex)(Selector_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem195(CTree* root)
//:Selector_bc
//(Expression)(sco2k_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem196(CTree* root)
//:Selector_bc
//(sco2k_lex)(BracketsOpt)(dot_lex)(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem197(CTree* root)
//:Selector
//(sco1k_lex)(Selector_bc)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem198(CTree* root)
//:Selector
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem199(CTree* root)
//:InnerCreator
//(identifier_lex)(ClassCreatorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem200(CTree* root)
//:IdentifierSuffix2_ab
//(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem201(CTree* root)
//:IdentifierSuffix2_ab
//(this_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem202(CTree* root)
//:IdentifierSuffix2_ab
//(super_key_lex)(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem203(CTree* root)
//:IdentifierSuffix2_ab
//(new_key_lex)(InnerCreator)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem204(CTree* root)
//:IdentifierSuffix1_ab
//(sco2k_lex)(BracketsOpt)(dot_lex)(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem205(CTree* root)
//:IdentifierSuffix1_ab
//(Expression)(sco2k_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem206(CTree* root)
//:IdentifierSuffix
//(sco1k_lex)(IdentifierSuffix1_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem207(CTree* root)
//:IdentifierSuffix
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem208(CTree* root)
//:IdentifierSuffix
//(dot_lex)(IdentifierSuffix2_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem209(CTree* root)
//:ClassCreatorRest_classbody
//(local_key_lex)(ClassBody)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem210(CTree* root)
//:ClassCreatorRest_classbody
{
	return true;
}

bool CJavaC16XCompiler::CompileItem211(CTree* root)
//:ClassCreatorRest
//(Arguments)(ClassCreatorRest_classbody)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem212(CTree* root)
//:ArrayCreatorRest_abss
//(Expression)(sco2k_lex)(ArrayCreatorRest_abs)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem213(CTree* root)
//:ArrayCreatorRest_abss
//(sco2k_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem214(CTree* root)
//:ArrayCreatorRest_abs
//(sco1k_lex)(ArrayCreatorRest_abss)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem215(CTree* root)
//:ArrayCreatorRest_abs
{
	return true;
}

bool CJavaC16XCompiler::CompileItem216(CTree* root)
//:ArrayCreatorRest_ab
//(sco2k_lex)(BracketsOpt)(ArrayInitializer)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem217(CTree* root)
//:ArrayCreatorRest_ab
//(Expression)(sco2k_lex)(ArrayCreatorRest_abs)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem218(CTree* root)
//:ArrayCreatorRest
//(sco1k_lex)(ArrayCreatorRest_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem219(CTree* root)
//:Creator_ab
//(ArrayCreatorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem220(CTree* root)
//:Creator_ab
//(ClassCreatorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem221(CTree* root)
//:Creator
//(QualifiedIdentifier)(Creator_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem222(CTree* root)
//:SuperSuffix_arguments
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem223(CTree* root)
//:SuperSuffix_arguments
{
	return true;
}

bool CJavaC16XCompiler::CompileItem224(CTree* root)
//:SuperSuffix
//(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem225(CTree* root)
//:SuperSuffix
//(dot_lex)(identifier_lex)(SuperSuffix_arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem226(CTree* root)
//:Arguments2
//(z_lex)(Expression)(Arguments2)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem227(CTree* root)
//:Arguments2
{
	return true;
}

bool CJavaC16XCompiler::CompileItem228(CTree* root)
//:Arguments1
//(Expression)(Arguments2)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem229(CTree* root)
//:Arguments1
{
	return true;
}

bool CJavaC16XCompiler::CompileItem230(CTree* root)
//:Arguments
//(sco1_lex)(Arguments1)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem231(CTree* root)
//:Primary2
//(new_key_lex)(Creator)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem232(CTree* root)
//:Primary1
//(this_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem233(CTree* root)
//:Primary1
//(super_key_lex)(Arguments)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem234(CTree* root)
//:Primary1
//(Literal)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem235(CTree* root)
//:Primary1
//(identifier_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem236(CTree* root)
//:Primary1
//(BasicType)(BracketsOpt)(dot_lex)(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem237(CTree* root)
//:Primary1
//(void_key_lex)(dot_lex)(class_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem238(CTree* root)
//:Primary
//(sco1_lex)(Expression)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem239(CTree* root)
//:Primary
//(Primary1)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem240(CTree* root)
//:Expression3_ab
//(Expression)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem241(CTree* root)
//:Expression3_ab
//(cast_key_lex)(Type)(sco2_lex)(Expression3)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem242(CTree* root)
//:Expression3
//(PrefixOp)(Expression3)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem243(CTree* root)
//:Expression3
//(sco1_lex)(Expression3_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem244(CTree* root)
//:PostfixOps
//(PostfixOp)(PostfixOps)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem245(CTree* root)
//:PostfixOps
{
	return true;
}

bool CJavaC16XCompiler::CompileItem246(CTree* root)
//:Selectors
//(Selector)(Selectors)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem247(CTree* root)
//:Selectors
{
	return true;
}

bool CJavaC16XCompiler::CompileItem248(CTree* root)
//:Expression3
//(Primary1)(Selectors)(PostfixOps)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem249(CTree* root)
//:Expression3
//(Primary2)(PostfixOps)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem250(CTree* root)
//:Expression2Rest_s
//(Infixop)(Expression3)(Expression2Rest_s)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem251(CTree* root)
//:Expression2Rest_s
{
	return true;
}

bool CJavaC16XCompiler::CompileItem252(CTree* root)
//:Expression2Rest
//(Infixop)(Expression3)(Expression2Rest_s)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem253(CTree* root)
//:Expression2Rest
//(instanceof_key_lex)(Type)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem254(CTree* root)
//:Expression2Rest
{
	return true;
}

bool CJavaC16XCompiler::CompileItem255(CTree* root)
//:Expression2
//(Expression3)(Expression2Rest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem256(CTree* root)
//:Expression1Rest
//(operator30_lex)(Expression)(operator32_lex)(Expression1)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem257(CTree* root)
//:Expression1Rest
{
	return true;
}

bool CJavaC16XCompiler::CompileItem258(CTree* root)
//:Expression1
//(Expression2)(Expression1Rest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem259(CTree* root)
//:Expression_s
//(AssigmentOperator)(Expression1)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem260(CTree* root)
//:Expression_s
{
	return true;
}

bool CJavaC16XCompiler::CompileItem261(CTree* root)
//:Expression
//(Expression1)(Expression_s)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem262(CTree* root)
//:ArrayInitializer3
//(VariableInitializer)(ArrayInitializer2)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem263(CTree* root)
//:ArrayInitializer3
{
	return true;
}

bool CJavaC16XCompiler::CompileItem264(CTree* root)
//:ArrayInitializer2
//(z_lex)(ArrayInitializer3)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem265(CTree* root)
//:ArrayInitializer2
{
	return true;
}

bool CJavaC16XCompiler::CompileItem266(CTree* root)
//:ArrayInitializer1
//(VariableInitializer)(ArrayInitializer2)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem267(CTree* root)
//:ArrayInitializer1
{
	return true;
}

bool CJavaC16XCompiler::CompileItem268(CTree* root)
//:ArrayInitializer
//(sco1f_lex)(ArrayInitializer1)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem269(CTree* root)
//:VariableInitializer
//(ArrayInitializer)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem270(CTree* root)
//:VariableInitializer
//(Expression)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem271(CTree* root)
//:ConstantDeclaratorRest
//(BracketsOpt)(operator20_lex)(VariableInitializer)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem272(CTree* root)
//:VariableDeclaratorId
//(identifier_lex)(BracketsOpt)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem273(CTree* root)
//:FormalParameter_final
//(final_key_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem274(CTree* root)
//:FormalParameter_final
{
	return true;
}

bool CJavaC16XCompiler::CompileItem275(CTree* root)
//:FormalParameter
//(FormalParameter_final)(Type)(VariableDeclaratorId)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem276(CTree* root)
//:FormalParameters1s
//(z_lex)(FormalParameter)(FormalParameters1s)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem277(CTree* root)
//:FormalParameters1s
{
	return true;
}

bool CJavaC16XCompiler::CompileItem278(CTree* root)
//:FormalParameters1
//(FormalParameter)(FormalParameters1s)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem279(CTree* root)
//:FormalParameters1
{
	return true;
}

bool CJavaC16XCompiler::CompileItem280(CTree* root)
//:FormalParameters
//(sco1_lex)(FormalParameters1)(sco2_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem281(CTree* root)
//:QualifiedIdentifierList1s
//(z_lex)(QualifiedIdentifier)(QualifiedIdentifierList1s)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem282(CTree* root)
//:QualifiedIdentifierList1s
{
	return true;
}

bool CJavaC16XCompiler::CompileItem283(CTree* root)
//:QualifiedIdentifierList
//(QualifiedIdentifier)(QualifiedIdentifierList1s)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem284(CTree* root)
//:InterfaceMethodDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem285(CTree* root)
//:InterfaceMethodDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::CompileItem286(CTree* root)
//:InterfaceMethodDeclaratorRest
//(FormalParameters)(BracketsOpt)(InterfaceMethodDeclaratorRest_throws)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem287(CTree* root)
//:InterfaceMethodOrFieldRest
//(ConstantDeclaratorsRest)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem288(CTree* root)
//:InterfaceMethodOrFieldRest
//(InterfaceMethodDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem289(CTree* root)
//:InterfaceMethodOrFieldDecl
//(Type)(identifier_lex)(InterfaceMethodOrFieldRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem290(CTree* root)
//:VoidInterfaceMethodDeclaratorRest_throws
//(throws_key_lex)(QualifiedIdentifierList)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem291(CTree* root)
//:VoidInterfaceMethodDeclaratorRest_throws
{
	return true;
}

bool CJavaC16XCompiler::CompileItem292(CTree* root)
//:VoidInterfaceMethodDeclaratorRest
//(FormalParameters)(VoidInterfaceMethodDeclaratorRest_throws)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem293(CTree* root)
//:InterfaceMemberDecl
//(InterfaceMethodOrFieldDecl)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem294(CTree* root)
//:InterfaceMemberDecl
//(void_key_lex)(identifier_lex)(VoidInterfaceMethodDeclaratorRest)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem295(CTree* root)
//:InterfaceMemberDecl
//(ClassOrInterfaceDeclaration_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem296(CTree* root)
//:InterfaceBodyDeclaration
//(ModifiersOpt)(InterfaceMemberDecl)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem297(CTree* root)
//:InterfaceBodyDeclaration
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem298(CTree* root)
//:ClassBodyDeclarations
//(ClassBodyDeclaration)(ClassBodyDeclarations)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem299(CTree* root)
//:ClassBodyDeclarations
{
	return true;
}

bool CJavaC16XCompiler::CompileItem300(CTree* root)
//:ClassBody
//(sco1f_lex)(ClassBodyDeclarations)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem301(CTree* root)
//:InterfaceBodyDeclarations
//(InterfaceBodyDeclaration)(InterfaceBodyDeclarations)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem302(CTree* root)
//:InterfaceBodyDeclarations
{
	return true;
}

bool CJavaC16XCompiler::CompileItem303(CTree* root)
//:InterfaceBody
//(sco1f_lex)(InterfaceBodyDeclarations)(sco2f_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem304(CTree* root)
//:ClassDeclaration_extends
//(extends_key_lex)(Type)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem305(CTree* root)
//:ClassDeclaration_extends
{
	return true;
}

bool CJavaC16XCompiler::CompileItem306(CTree* root)
//:ClassDeclaration_implements
//(implements_key_lex)(TypeList)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem307(CTree* root)
//:ClassDeclaration_implements
{
	return true;
}

bool CJavaC16XCompiler::CompileItem308(CTree* root)
//:ClassDeclaration
//(class_key_lex)(identifier_lex)(ClassDeclaration_extends)(ClassDeclaration_implements)(ClassBody)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem309(CTree* root)
//:InterfaceDeclaration_extends
//(extends_key_lex)(TypeList)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem310(CTree* root)
//:InterfaceDeclaration_extends
{
	return true;
}

bool CJavaC16XCompiler::CompileItem311(CTree* root)
//:InterfaceDeclaration
//(interface_key_lex)(identifier_lex)(InterfaceDeclaration_extends)(InterfaceBody)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem312(CTree* root)
//:ClassOrInterfaceDeclaration_ab
//(ClassDeclaration)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem313(CTree* root)
//:ClassOrInterfaceDeclaration_ab
//(InterfaceDeclaration)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem314(CTree* root)
//:ClassOrInterfaceDeclaration
//(ModifiersOpt)(ClassOrInterfaceDeclaration_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem315(CTree* root)
//:TypeDeclaration
//(ClassOrInterfaceDeclaration)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem316(CTree* root)
//:TypeDeclaration
//(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem317(CTree* root)
//:ImportDeclaration_identifiers_ab
//(identifier_lex)(ImportDeclaration_identifiers)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem318(CTree* root)
//:ImportDeclaration_identifiers_ab
//(operator25_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem319(CTree* root)
//:ImportDeclaration_identifiers
//(dot_lex)(ImportDeclaration_identifiers_ab)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem320(CTree* root)
//:ImportDeclaration_identifiers
{
	return true;
}

bool CJavaC16XCompiler::CompileItem321(CTree* root)
//:ImportDeclaration
//(import_key_lex)(identifier_lex)(ImportDeclaration_identifiers)(dot_z_lex)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem322(CTree* root)
//:ImportDeclarations
//(ImportDeclaration)(ImportDeclarations)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem323(CTree* root)
//:ImportDeclarations
{
	return true;
}

bool CJavaC16XCompiler::CompileItem324(CTree* root)
//:TypeDeclarations
//(TypeDeclaration)(TypeDeclarations)
{
	return true;
}

bool CJavaC16XCompiler::CompileItem325(CTree* root)
//:TypeDeclarations
{
	return true;
}

bool CJavaC16XCompiler::CompileItem326(CTree* root)
//:CompilationUnit
//(package_key_lex)(QualifiedIdentifier)(dot_z_lex)(ImportDeclarations)(TypeDeclarations)
{
	std::string _package=GetQualifiedIdentifier(root->m_vComponents[1]);
	m_ptTarget->Package(_package);
	CompileSub(root->m_vComponents[3]);
	CompileSub(root->m_vComponents[4]);
	return false;
}

bool CJavaC16XCompiler::CompileItem327(CTree* root)
//:CompilationUnit
//(ImportDeclarations)(TypeDeclarations)
{
	CompileSub(root->m_vComponents[0]);
	CompileSub(root->m_vComponents[1]);
	return false;
}

bool CJavaC16XCompiler::CompileItem328(CTree* root)
//:main
//(CompilationUnit)
{
	m_ptTarget->Prolog();
	m_ptTarget->FlashLoader();
	m_ptTarget->Initialization();
	m_ptTarget->System_gc();
	m_ptTarget->RTTI(m_stClasses,m_stInterfaces);
	m_ptTarget->StaticData(m_stClasses);
	CompileSub(root->m_vComponents[0]);
	m_ptTarget->Epilog();
	return false;
}
