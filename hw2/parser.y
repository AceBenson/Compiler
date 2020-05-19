%{
	#include <stdio.h>
	int yylex();
	extern char yytext[];
	extern int column;
%}
%union {
	int token;
	double dval;
	char charv;
	char* ident;
}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
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
%left  <charv> ';'
%left IDENTIFIER  SCSPEC TYPESPEC TYPEMOD
%left  <charv> ','
%right <charv> '='
%right <token> ASSIGN 
%right <charv> '?' ':'
%left <charv> OR_OP
%left <charv> AND_OP
%left <charv> '|'
%left <charv> '^'
%left <charv> '&'
%left <token> EQ_OP
%left <token> ARITHCOMPARE  '>' '<' 
%left <charv> LSHIFT RSHIFT
%left <charv> '+' '-'
%left <token> '*' '/' '%'
%right <token> UNARY INC_OP DEC_OP 
%left HYPERUNARY 
%left <token> POINTSAT '.'
 
%right THEN ELSE

%start program

%%
program
	: translation_unit
	;
translation_unit
	: external_declaration 
	| translation_unit external_declaration
	;
external_declaration
	: function_definition
	| declaration
	;
function_definition
	: declaration_specifiers declarator compound_statement
	| declaration_specifiers declarator declaration_list compound_statement
	| declarator compound_statement
	| declarator declaration_list compound_statement
	;
declaration_list
	: declaration
	| declaration_list declaration
	;
compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;
statement_list
	: statement
	| statement_list statement
	;
statement
	: compound_statement
	| expression_statement
	| selection_statement
	| labeled_statement
	| iteration_statement
	| jump_statement
	;
labeled_statement
	: IDENTIFIER ':' statement
	| CASE conditional_expression ':' statement
	| DEFAULT ':' statement
	;
selection_statement
	: IF '(' expression ')' statement				%prec THEN
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;
iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;
jump_statement
	: CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;
expression_statement
	: ';'
	| expression ';'
	;
declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;
declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;
type_qualifier
	: CONST
	;
type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	;
init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;
init_declarator
	: declarator
	| declarator '=' initializer
	;
declarator
	: direct_declarator
	;
direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' conditional_expression ']'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' ')'
	;
parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;
parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;
parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers
	;
identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;
initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;
initializer_list
	: initializer
	| initializer_list ',' initializer
	;
expression
	: assignment_expression
	| expression ',' assignment_expression
	;
assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;
assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	;
conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;
logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;
logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;
inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;
exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;
and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;
equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;
relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;
shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;
additive_expression
	: additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	| multiplicative_expression
	;
multiplicative_expression
	: multiplicative_expression '*' cast_expression 
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	| cast_expression 
	;
cast_expression
	: unary_expression
	| '(' type_specifier ')' cast_expression
	;
unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	;
unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;
postfix_expression
	: primary_expression
	| FUNCTION
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;
argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;
primary_expression
	: '(' expression ')'
	| CONSTANT
	| IDENTIFIER
	| STRING_LITERAL
	;
%%

int main()
{
	yyparse();
	return 0;
}
int yyerror(char *s) 
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
	return 0;
}
