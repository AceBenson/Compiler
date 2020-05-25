%{
	#include <stdio.h>
	#include <stdlib.h>
	int yylex();
	extern int errline;
	char* get_buf();
	int type=0;
%}


%union {
	int ival;
	double dval;
	char cval;
	char* sval;
}

%token IDENTIFIER FCONSTANT CONSTANT CCONSTANT STRING_LITERAL SIZEOF
%token INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token FUNCTION

/* Define the operator tokens and their precedences.
   The value is an integer because, if used, it is the tree code
   to use in the expression made from the operator.  */
%left  <cval> ';'
%left IDENTIFIER  SCSPEC TYPESPEC TYPEMOD
%left  <cval> ','
%right <cval> '='
%right <ival> ASSIGN 
%right <cval> '?' ':'
%left <cval> OR_OP
%left <cval> AND_OP
%left <cval> '|'
%left <cval> '^'
%left <cval> '&'
%left <ival> EQ_OP
%left <ival> ARITHCOMPARE  '>' '<' 
%left <cval> LSHIFT RSHIFT
%left <cval> '+' '-'
%left <ival> '*' '/' '%'
%right <ival> UNARY INC_OP DEC_OP 
%left HYPERUNARY 
%left <ival> POINTSAT '.' 
%right THEN ELSE

%type <sval> IDENTIFIER STRING_LITERAL FUNCTION constant primary_expression postfix_expression unary_operator unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression expression expression_statement statement argument_expression_list compound_statement compound_list selection_statement jump_statement iteration_statement labeled_statement assignment_operator declaration declaration_specifiers init_declarator_list init_declarator type_specifier declarator initializer initializer_list direct_declarator declaration_list identifier_list parameter_type_list parameter_list parameter_declaration declaration_specifiers function_definition external_declaration translation_unit program
%type <ival> CONSTANT
%type <dval> FCONSTANT
%type <cval> CCONSTANT

%start program

%%
program
	: translation_unit { printf("%s", $1); free($1); }
	;
translation_unit
	: external_declaration 					{ $$=$1; } 
	| translation_unit external_declaration { char* buf=get_buf(); sprintf(buf, "%s%s", $1, $2); $$=buf; free($1); free($2); }
	;
external_declaration
	: function_definition 	{ $$=$1; }
	| declaration 			{ $$=$1; }
	;
function_definition
	: declaration_specifiers declarator compound_statement 					{ char* buf=get_buf(); sprintf(buf, "<func_def>%s%s%s</func_def>", $1, $2, $3); $$=buf; free($1); free($2); free($3); }
	| declaration_specifiers declarator declaration_list compound_statement { char* buf=get_buf(); sprintf(buf, "<func_def>%s%s%s%s</func_def>", $1, $2, $3, $4); $$=buf; free($1); free($2); free($3); free($4); }
	| declarator compound_statement 										{ char* buf=get_buf(); sprintf(buf, "<func_def>%s%s</func_def>", $1, $2); $$=buf; free($1); free($2); }
	| declarator declaration_list compound_statement 						{ char* buf=get_buf(); sprintf(buf, "<func_def>%s%s%s</func_def>", $1, $2, $3); $$=buf; free($1); free($2); free($3); }
	;
declaration_list
	: declaration 					{ $$=$1; }
	| declaration_list declaration 	{ char* buf=get_buf(); sprintf(buf, "%s%s", $1, $2); $$=buf; free($1); free($2); }
	;
compound_statement
	: '{' '}' { char* buf=get_buf(); strcpy(buf, "{}"); $$=buf; }
	| '{' compound_list '}' { char* buf=get_buf(); sprintf(buf, "{%s}", $2); $$=buf; free($2); }
	;
compound_list
	: statement { $$=$1;}
	| declaration { $$=$1; }
	| compound_list statement { char* buf=get_buf(); sprintf(buf, "%s%s", $1, $2); $$=buf; free($1); free($2); }
	| compound_list declaration { char* buf=get_buf(); sprintf(buf, "%s%s", $1, $2); $$=buf; free($1); free($2); }
	;
statement
	: compound_statement 	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", $1); $$=buf; free($1); }
	| expression_statement 	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", $1); $$=buf; free($1); }
	| selection_statement 	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", $1); $$=buf; free($1); }
	| labeled_statement 	{ char* buf=get_buf(); sprintf(buf, "%s", $1); $$=buf; free($1); }
	| iteration_statement 	{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", $1); $$=buf; free($1); }
	| jump_statement 		{ char* buf=get_buf(); sprintf(buf, "<stmt>%s</stmt>", $1); $$=buf; free($1); }
	;
labeled_statement
	: IDENTIFIER ':' statement { char* buf=get_buf(); sprintf(buf, "%s:%s", $1, $3); $$=buf; free($1); free($3); }
	| CASE conditional_expression ':' statement { char* buf=get_buf(); sprintf(buf, "case%s:%s", $2, $4); $$=buf; free($2); free($4); }
	| DEFAULT ':' statement { char* buf=get_buf(); sprintf(buf, "default:%s", $3); $$=buf; free($3); }
	;
selection_statement
	: IF '(' expression ')' compound_statement { char* buf=get_buf(); sprintf(buf, "if(%s)%s", $3, $5); $$=buf; free($3); free($5); } %prec THEN
	| IF '(' expression ')' compound_statement ELSE compound_statement { char* buf=get_buf(); sprintf(buf, "if(%s)%selse%s", $3, $5, $7); $$=buf; free($3); free($5); free($7); }
	| SWITCH '(' expression ')' compound_statement { char* buf=get_buf(); sprintf(buf, "switch(%s)%s", $3, $5); $$=buf; free($3); free($5); }
	;
iteration_statement
	: WHILE '(' expression ')' statement { char* buf=get_buf(); sprintf(buf, "while(%s)%s", $3, $5); $$=buf; free($3); free($5); }
	| DO statement WHILE '(' expression ')' ';' { char* buf=get_buf(); sprintf(buf, "do%swhile(%s);", $2, $5); $$=buf; free($2); free($5); }
	| FOR '(' expression_statement expression_statement ')' statement { char* buf=get_buf(); sprintf(buf, "for(%s%s)%s", $3, $4, $6); $$=buf; free($3); free($4); free($6); }
	| FOR '(' expression_statement expression_statement expression ')' statement { char* buf=get_buf(); sprintf(buf, "for(%s%s%s)%s", $3, $4, $5, $7); $$=buf; free($3); free($4); free($5); free($7); }
	;
jump_statement
	: CONTINUE ';' 			{ char* buf=get_buf(); strcpy(buf, "continue;"); $$=buf; }
	| BREAK ';' 			{ char* buf=get_buf(); strcpy(buf, "break;"); $$=buf; }
	| RETURN ';' 			{ char* buf=get_buf(); strcpy(buf, "return;"); $$=buf; }
	| RETURN expression ';' { char* buf=get_buf(); sprintf(buf, "return%s;", $2); $$=buf;}
	;
expression_statement
	: ';' 				{ char* buf=get_nbuf(2); strcpy(buf, ";"); $$=buf; }
	| expression ';' 	{ char* buf=get_buf(); sprintf(buf, "%s;", $1); $$=buf; free($1); }
	;
declaration
	: declaration_specifiers ';' 
	{ 
		char* buf=get_buf();
		switch(type) { 
			case 0: sprintf(buf, "<scalar_decl>%s;</scalar_decl>", $1); break;
			case 1: sprintf(buf, "<array_decl>%s;</array_decl>", $1); break;
			case 2: sprintf(buf, "<func_decl>%s;</func_decl>", $1); break;
			case 3: sprintf(buf, "<const_decl>%s;</const_decl>", $1); break;
		}
		type=0;
		$$=buf;
		free($1);
	}
	| declaration_specifiers init_declarator_list ';' 
	{ 
		char* buf=get_buf();
		switch(type) {
			case 0: sprintf(buf, "<scalar_decl>%s%s;</scalar_decl>", $1, $2); break;
			case 1: sprintf(buf, "<array_decl>%s%s;</array_decl>", $1, $2); break;
			case 2: sprintf(buf, "<func_decl>%s%s;</func_decl>", $1, $2); break;
			case 3: sprintf(buf, "<const_decl>%s%s;</const_decl>", $1, $2); break;		
		}
		type=0;
		$$=buf; 
		free($1);
	}
	;
declaration_specifiers
	: type_specifier { char* buf=get_buf(); strcpy(buf, $1); $$=buf; free($1); }
	| type_specifier declaration_specifiers { char* buf=get_buf(); sprintf(buf, "%s%s", $1, $2); $$=buf; free($1); free($2); }
	| CONST declaration_specifiers { type=3; char* buf=get_buf(); sprintf(buf, "const%s", $2); $$=buf; free($2); }
	;
type_specifier
	: VOID 		{ char* buf=get_buf(); strcpy(buf, "void"); $$=buf; }
	| CHAR 		{ char* buf=get_buf(); strcpy(buf, "char"); $$=buf; }
	| SHORT 	{ char* buf=get_buf(); strcpy(buf, "short"); $$=buf; }
	| INT 		{ char* buf=get_buf(); strcpy(buf, "int"); $$=buf; }
	| LONG 		{ char* buf=get_buf(); strcpy(buf, "long"); $$=buf; }
	| FLOAT 	{ char* buf=get_buf(); strcpy(buf, "float"); $$=buf; }
	| DOUBLE 	{ char* buf=get_buf(); strcpy(buf, "double"); $$=buf; }
	| SIGNED 	{ char* buf=get_buf(); strcpy(buf, "signed"); $$=buf; }
	| UNSIGNED 	{ char* buf=get_buf(); strcpy(buf, "unsigned"); $$=buf; }
	;
init_declarator_list
	: init_declarator { $$=$1; }
	| init_declarator_list ',' init_declarator { char* buf=get_buf(); sprintf(buf, "%s,%s", $1, $3); $$=buf; }
	;
init_declarator
	: declarator { $$=$1; }
	| declarator '=' initializer { char* buf=get_buf(); sprintf(buf, "%s=%s", $1, $3); $$=buf; }
	;
declarator
	: direct_declarator { $$=$1; }
	;
direct_declarator
	: IDENTIFIER { if(type!=3) type=0; $$=$1; }
	| '(' declarator ')' { char* buf=get_buf(); sprintf(buf, "(%s)", $2); $$=buf; }
	| direct_declarator '[' conditional_expression ']' { if(type!=3) type=1; char* buf = get_buf(); sprintf(buf, "%s[%s]", $1, $3); $$=buf; }
	| direct_declarator '(' identifier_list ')' { type=2; char* buf = get_buf(); sprintf(buf, "%s(%s)", $1, $3); $$=buf; }
	| direct_declarator '(' parameter_type_list ')' { type=2; char* buf = get_buf(); sprintf(buf, "%s(%s)", $1, $3); $$=buf; }
	| direct_declarator '(' ')' { type=2; char* buf = get_buf(); sprintf(buf, "%s()", $1); $$=buf; }
	;
parameter_type_list
	: parameter_list { $$=$1; }
	| parameter_list ',' ELLIPSIS { char* buf=get_buf(); sprintf(buf, "%s,...", $1); $$=buf; }
	;
parameter_list
	: parameter_declaration { $$=$1; }
	| parameter_list ',' parameter_declaration { char* buf=get_buf(); sprintf(buf, "%s,%s", $1, $3); $$=buf; }
	;
parameter_declaration
	: declaration_specifiers declarator { char* buf=get_buf(); sprintf(buf, "%s%s", $1, $2); $$=buf; }
	| declaration_specifiers { $$=$1; }
	;
identifier_list
	: IDENTIFIER { $$=$1; }
	| identifier_list ',' IDENTIFIER { char* buf=get_buf(); sprintf(buf, "%s,%s", $1, $3); $$=buf; }
	;
initializer
	: assignment_expression { $$=$1; }
	| '{' initializer_list '}' { char* buf=get_buf(); sprintf(buf, "{%s}", $2); $$=buf; }
	| '{' initializer_list ',' '}' { char* buf=get_buf(); sprintf(buf, "{%s,}", $2); $$=buf; }
	;
initializer_list
	: initializer { $$=$1; }
	| initializer_list ',' initializer { char* buf=get_buf(); sprintf(buf, "%s,%s", $1, $3); $$=buf;}
	;
expression
	: assignment_expression { $$=$1; }
	| expression ',' assignment_expression { char* buf=get_buf(); sprintf(buf, "%s,%s", $1, $3); $$=buf; }
	;
assignment_expression
	: conditional_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>", $1); $$=buf; }
	| unary_expression assignment_operator assignment_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s%s%s</expr>", $1, $2, $3); $$=buf; free($1); free($3); }
	;
assignment_operator
	: '=' { $$="=";}
	| MUL_ASSIGN { $$="*="; }
	| DIV_ASSIGN { $$="/="; }
	| MOD_ASSIGN { $$="%="; }
	| ADD_ASSIGN { $$="+="; }
	| SUB_ASSIGN { $$="-="; }
	;
conditional_expression
	: logical_or_expression { $$=$1; }
	| logical_or_expression '?' expression ':' conditional_expression { char* buf=get_buf(); sprintf(buf, "%s?%s:%s", $1, $3, $5); $$=buf; }
	;
logical_or_expression
	: logical_and_expression { $$=$1; }
	| logical_or_expression OR_OP logical_and_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>||<expr>%s</expr>", $1, $3); $$=buf; }
	;
logical_and_expression
	: inclusive_or_expression { $$=$1; }
	| logical_and_expression AND_OP inclusive_or_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>&&<expr>%s</expr>", $1, $3); $$=buf; }
	;
inclusive_or_expression
	: exclusive_or_expression { $$=$1; }
	| inclusive_or_expression '|' exclusive_or_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>|<expr>%s</expr>", $1, $3); $$=buf; }
	;
exclusive_or_expression
	: and_expression { $$=$1; }
	| exclusive_or_expression '^' and_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>^<expr>%s</expr>", $1, $3); $$=buf; }
	;
and_expression
	: equality_expression { $$=$1; }
	| and_expression '&' equality_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>&<expr>%s</expr>", $1, $3); $$=buf; }
	;
equality_expression
	: relational_expression { $$=$1; }
	| equality_expression EQ_OP relational_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>==<expr>%s</expr>", $1, $3); $$=buf; }
	| equality_expression NE_OP relational_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>!=<expr>%s</expr>", $1, $3); $$=buf; }
	;
relational_expression
	: shift_expression { $$=$1; }
	| relational_expression '<' shift_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><<expr>%s</expr>", $1, $3); $$=buf; }
	| relational_expression '>' shift_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>><expr>%s</expr>", $1, $3); $$=buf; }
	| relational_expression LE_OP shift_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><=<expr>%s</expr>", $1, $3); $$=buf; }
	| relational_expression GE_OP shift_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>>=<expr>%s</expr>", $1, $3); $$=buf; }
	;
shift_expression
	: additive_expression { $$=$1; }
	| shift_expression LEFT_OP additive_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr><<<expr>%s</expr>", $1, $3); $$=buf; }
	| shift_expression RIGHT_OP additive_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>>><expr>%s</expr>", $1, $3); $$=buf; }
	;
additive_expression
	: additive_expression '+' multiplicative_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>+<expr>%s</expr>", $1, $3); $$=buf; }
	| additive_expression '-' multiplicative_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>-<expr>%s</expr>", $1, $3); $$=buf; }
	| multiplicative_expression { $$=$1; }
	;
multiplicative_expression
	: multiplicative_expression '*' cast_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>*<expr>%s</expr>", $1, $3); $$=buf; }
	| multiplicative_expression '/' cast_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>/<expr>%s</expr>", $1, $3); $$=buf; free($1); free($3); }
	| multiplicative_expression '%' cast_expression { char* buf=get_buf(); sprintf(buf, "<expr>%s</expr>%%<expr>%s</expr>", $1, $3); $$=buf; free($1); free($3); }
	| cast_expression { char* buf=get_buf(); sprintf(buf, "%s", $1); $$=buf; free($1); }
	;
cast_expression
	: unary_expression { char* buf=get_buf(); sprintf(buf, "%s", $1); $$=buf; free($1); }
	| '(' type_specifier ')' cast_expression { char* buf=get_buf(); sprintf(buf, "(%s)%s", $2, $4); $$=buf; free($2); free($4); }
	;
unary_expression
	: postfix_expression { $$=$1; }
	| INC_OP unary_expression { char* buf=get_buf(); sprintf(buf, "++%s", $2); $$=buf; free($2); }
	| DEC_OP unary_expression { char* buf=get_buf(); sprintf(buf, "--%s", $2); $$=buf; free($2); }
	| unary_operator cast_expression { char* buf=get_buf(); sprintf(buf, "%s<expr>%s</expr>", $1, $2); $$=buf; free($2); }
	;
unary_operator
	: '&' { $$="&"; }
	| '*' { $$="*"; }
	| '+' { $$="+"; }
	| '-' { $$="-"; }
	| '~' { $$="~"; }
	| '!' { $$="!"; }
	;
postfix_expression
	: primary_expression 									{ $$=$1; }
	| FUNCTION 												{ char* buf=get_buf(); sprintf(buf, "%s", $1); $$=buf; free($1); }
	| postfix_expression '[' expression ']' 				{ char* buf=get_buf(); sprintf(buf, "%s[%s]", $1, $3); $$=buf; free($1); free($3); }
	| postfix_expression '(' ')' 							{ char* buf=get_buf(); sprintf(buf, "%s()", $1); $$=buf; free($1); }
	| postfix_expression '(' argument_expression_list ')' 	{ char* buf=get_buf(); sprintf(buf, "%s(%s)", $1, $3); $$=buf; free($1); free($3); }
	| postfix_expression INC_OP 							{ char* buf=get_buf(); sprintf(buf, "%s++", $1); $$=buf; free($1); }
	| postfix_expression DEC_OP 							{ char* buf=get_buf(); sprintf(buf, "%s--", $1); $$=buf; free($1); }
	;
argument_expression_list
	: assignment_expression { $$=$1; }
	| argument_expression_list ',' assignment_expression { char* buf=get_buf(); sprintf(buf, "%s,%s", $1, $3); $$=buf; free($1); free($3); }
	;
primary_expression
	: '(' expression ')' { char* buf=get_buf(); sprintf(buf, "(%s)", $2); $$=buf; free($2); }
	| constant { $$=$1; }
	| IDENTIFIER { $$=$1; }
	| STRING_LITERAL { $$=$1; }
	;
constant
	: CONSTANT { char* buf=get_buf(); sprintf(buf, "%d", $1); $$=buf; }
	| CCONSTANT { char* buf=get_buf(); sprintf(buf, "%c", $1); $$=buf; }
	| FCONSTANT { char* buf=get_buf(); sprintf(buf, "%f", $1); $$=buf; }
	;
%%

char* get_buf()
{
	char* buf=(char*)malloc(sizeof(char)*10000);
	return buf;
}

char* get_nbuf(int n)
{
	char* buf = (char*)malloc(sizeof(char)*n);
	return buf;
}

int main()
{
	yyparse();
	return 0;
}
int yyerror(char *s) 
{
	printf("YACC> Error at line %d.\n", errline);
	return 0;
}
