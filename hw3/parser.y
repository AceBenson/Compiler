%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define T_INT 1
	#define T_CHAR 2
	#define T_FLOAT 3
	#define T_STRING 4
	#define T_FUNCTION 4
	#define GLOBAL_MODE 1
	#define LOCAL_MODE 2
	#define ARGUMENT_MODE 3
	int yylex();
	extern int errline;
	int type=0;
	int c_type;
	int offset=0;
	typedef struct symbol {
  		char *name;
  		int scope;
		int type;
		int id;
		int totalArgs;
		char* funcName;
		int mode;
		int offset;
		struct symbol *next;
	} symbol;
	void codegen();
	void handleParams(char*);
	void funcBegin(char*);
	void funcEnd(char*);
	void callFunc(char*, int);
	symbol* put(char*);
	symbol* get(char*);
	symbol* lookup(char*);
	int check(char*);
	void printTable();
	void popScope(int);
	symbol* install(char*);
	
	symbol* table = (symbol*)0;
	int numOfSymbols = 0;
	int cur_scope=0;
	int argc=0;
	FILE *fptr;
%}

%union {
	int ival;
	double dval;
	char cval;
	char* sval;
	//Constant val;
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

%type <sval> func_definitor IDENTIFIER STRING_LITERAL FUNCTION primary_expression postfix_expression unary_operator unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression expression expression_statement statement argument_expression_list compound_statement compound_list selection_statement jump_statement iteration_statement labeled_statement assignment_operator declaration declaration_specifiers init_declarator_list init_declarator type_specifier declarator initializer initializer_list direct_declarator declaration_list parameter_type_list parameter_list parameter_declaration declaration_specifiers function_definition ext exts
%type <ival> CONSTANT
%type <dval> FCONSTANT
%type <cval> CCONSTANT

%start exts

%%

exts
	: ext 					{ } 
	| exts ext { }
	;
ext
	: function_definition 	{ }
	| declaration 			{ }
	;
function_definition
	: declaration_specifiers func_definitor {
		cur_scope++;
		handleParams($2);
		funcBegin($2);
	} compound_statement {
		funcEnd($2);
	} 
	| declaration_specifiers func_definitor declaration_list {
		cur_scope++;
		handleParams($2);
		funcBegin($2);
	} compound_statement {
		funcEnd($2);
	}
	| func_definitor {
		cur_scope++;
		handleParams($1);
		funcBegin($1);
	} compound_statement {
		funcEnd($1);
	}
	| func_definitor declaration_list {
		cur_scope++;
		handleParams($1);
		funcBegin($1);
	} compound_statement {
		funcEnd($1);
	}
	;
declaration_list
	: declaration 					{ }
	| declaration_list declaration 	{ }
	;
compound_statement
	: '{' { /*setLocalVars();*/ } { popScope(cur_scope); cur_scope--; } '}' {}
	| '{' { /*setLocalVars();*/ } compound_list { popScope(cur_scope); cur_scope--; } '}' {}
	;
compound_list
	: statement { }
	| declaration { }
	| compound_list statement { }
	| compound_list declaration { }
	;
statement
	: compound_statement 	{ }
	| expression_statement 	{ }
	| selection_statement 	{ 
		fprintf(fptr, "Exit:\n");
	}
	| labeled_statement 	{ }
	| iteration_statement 	{ }
	| jump_statement 		{ }
	;
labeled_statement
	: IDENTIFIER ':' statement { }
	| CASE conditional_expression ':' statement { }
	| DEFAULT ':' statement { }
	;
selection_statement
	: IF '(' expression ')' { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tli t1, 0\n");
		fprintf(fptr, "\tbeq t0 t1, Else\n");
		cur_scope++; 
	} compound_statement { 
		fprintf(fptr, "\tj Exit\n");
		fprintf(fptr, "Else:\n");
	}
	| selection_statement ELSE { 
		cur_scope++; 
	} compound_statement { 
	}
	| SWITCH '(' expression ')' { cur_scope++; } compound_statement { }
	;
iteration_statement
	: WHILE '(' expression ')' {
		fprintf(fptr, "Loop:\n");
	} statement { 
		fprintf(fptr, "\tbeq , , Loop");
	}
	| DO statement WHILE '(' expression ')' ';' { }
	| FOR '(' expression_statement expression_statement ')' statement { }
	| FOR '(' expression_statement expression_statement expression ')' statement { }
	;
jump_statement
	: CONTINUE ';' 			{ }
	| BREAK ';' 			{ }
	| RETURN ';' 			{ }
	| RETURN expression ';' { }
	;
expression_statement
	: ';' 				{ }
	| expression ';' 	{ }
	;
declaration
	: declaration_specifiers ';' 
	{ 
		switch(type) { 
			case 0: break;
			case 1: break;
			case 2: break;
			case 3: break;
		}
		type=0;
	}
	| declaration_specifiers init_declarator_list ';' 
	{ 
		switch(type) {
			case 0: break;
			case 1: break;
			case 2: break;
			case T_FUNCTION: fprintf(fptr, ".global %s\n", $2); break;		
		}
		type=0;
	}
	;
declaration_specifiers
	: type_specifier { }
	| type_specifier declaration_specifiers { }
	| CONST declaration_specifiers { }
	;
type_specifier
	: VOID 		{ $$="void"; 	}
	| CHAR 		{ $$="char"; 	}
	| SHORT 	{ $$="short"; 	}
	| INT 		{ $$="int"; 	}
	| LONG 		{ $$="long"; 	}
	| FLOAT 	{ $$="float"; 	}
	| DOUBLE 	{ $$="double"; 	}
	| SIGNED 	{ $$="signed"; 	}
	| UNSIGNED 	{ $$="unsigned";}
	;
init_declarator_list
	: init_declarator { $$=$1; }
	| init_declarator_list ',' init_declarator { }
	;
init_declarator
	: declarator { }
	| func_definitor { type=T_FUNCTION; $$=$1; }
	| declarator '=' initializer { 
		symbol* id = lookup($1);
		//fprintf(fptr, "\tsw  t0, %d(fp) \n", id->offset*(-4)-8);
		//fprintf(fptr, "\n");
	}
	;
func_definitor
	: IDENTIFIER { 
		symbol* f = install($1);
		f->type = T_FUNCTION;
		$$=$1;
	} func_param_list { $$=$1; }
	;
func_param_list
	: '(' { cur_scope++; } parameter_type_list ')' { cur_scope--; }
	| '(' ')' {}
	;
declarator
	: direct_declarator { }
	;
direct_declarator
	: IDENTIFIER { install($1); $$=$1;}
	| '(' declarator ')' { }
	| direct_declarator '[' conditional_expression ']' { install($1); if(type!=3) type=1; }
	;
parameter_type_list
	: parameter_list { }
	| parameter_list ',' ELLIPSIS { }
	;
parameter_list
	: parameter_declaration { }
	| parameter_list ',' parameter_declaration { }
	;
parameter_declaration
	: declaration_specifiers declarator { }
	| declaration_specifiers { }
	;
initializer
	: assignment_expression { }
	| '{' initializer_list '}' { }
	| '{' initializer_list ',' '}' { }
	;
initializer_list
	: initializer { }
	| initializer_list ',' initializer { }
	;
expression
	: assignment_expression { }
	| expression ',' assignment_expression { }
	;
assignment_expression
	: conditional_expression { }
	| unary_expression assignment_operator assignment_expression {
		//printf("%s = %d", );
 	}
	;
assignment_operator
	: '=' { }
	| MUL_ASSIGN { }
	| DIV_ASSIGN { }
	| MOD_ASSIGN { }
	| ADD_ASSIGN { }
	| SUB_ASSIGN { }
	;
conditional_expression
	: logical_or_expression { }
	| logical_or_expression '?' expression ':' conditional_expression { }
	;
logical_or_expression
	: logical_and_expression { }
	| logical_or_expression OR_OP logical_and_expression { }
	;
logical_and_expression
	: inclusive_or_expression { }
	| logical_and_expression AND_OP inclusive_or_expression { }
	;
inclusive_or_expression
	: exclusive_or_expression { }
	| inclusive_or_expression '|' exclusive_or_expression { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tor t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
	;
exclusive_or_expression
	: and_expression { }
	| exclusive_or_expression '^' and_expression { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\txor t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
	;
and_expression
	: equality_expression { }
	| and_expression '&' equality_expression {
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tand t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
	;
equality_expression
	: relational_expression { }
	| equality_expression EQ_OP relational_expression { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\txor t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
	| equality_expression NE_OP relational_expression { }
	;
relational_expression
	: shift_expression { }
	| relational_expression '<' shift_expression { }
	| relational_expression '>' shift_expression { }
	| relational_expression LE_OP shift_expression { }
	| relational_expression GE_OP shift_expression { }
	;
shift_expression
	: additive_expression { }
	| shift_expression LEFT_OP additive_expression { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tsll t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	}
	| shift_expression RIGHT_OP additive_expression {
		fprintf(fptr, "\tlw t0, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tlw t1, 0(sp)\n");
        fprintf(fptr, "\taddi sp, sp, 4\n");
        fprintf(fptr, "\tsrl t0, t0, t1\n");
        fprintf(fptr, "\taddi sp, sp, -4\n");
        fprintf(fptr, "\tsw t0, 0(sp)\n");
        fprintf(fptr, "\n");
	 }
	;
additive_expression
	: additive_expression '+' multiplicative_expression {
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tadd t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
	| additive_expression '-' multiplicative_expression { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tsub t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
	| multiplicative_expression { }
	;
multiplicative_expression
	: multiplicative_expression '*' cast_expression {
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tmul t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");	
	}
	| multiplicative_expression '/' cast_expression { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tdiv t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
	| multiplicative_expression '%' cast_expression { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\tlw t1, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\trem t0, t0, t1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
	| cast_expression { }
	;
cast_expression
	: unary_expression { }
	| '(' type_specifier ')' cast_expression { }
	;
unary_expression
	: postfix_expression { }
	| INC_OP unary_expression { }
	| DEC_OP unary_expression { }
	| unary_operator cast_expression { }
	;
unary_operator
	: '&' { }
	| '*' { }
	| '+' { }
	| '-' { }
	| '~' { }
	| '!' { }
	;
postfix_expression
	: primary_expression 									{ $$=$1; }
	| FUNCTION 												{ printf("%s\n", $1); $$=$1; }
	| postfix_expression '[' expression ']' 				{ }
	| postfix_expression '(' ')' 							{ callFunc($1, 0); }
	| postfix_expression '(' argument_expression_list ')' 	{ callFunc($1, argc); }
	| postfix_expression INC_OP { 
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\taddi t0, t0, 1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	}
	| postfix_expression DEC_OP {
		fprintf(fptr, "\tlw t0, 0(sp)\n");
		fprintf(fptr, "\taddi sp, sp, 4\n");
		fprintf(fptr, "\taddi t0, t0, -1\n");
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
	
	}
	;
argument_expression_list
	: assignment_expression { argc++; }
	| argument_expression_list ',' assignment_expression { argc++; }
	;
primary_expression
	: '(' expression ')' { }
	| CONSTANT { 
		fprintf(fptr, "\tli t0, %d\n",$1);
		fprintf(fptr, "\taddi sp, sp, -4\n");
		fprintf(fptr, "\tsw t0, 0(sp)\n");
		fprintf(fptr, "\n");
		//Constant c;
		//c.type = T_INT;
		//c.ival = $1;
	}
	| CCONSTANT {
		
	}
	| FCONSTANT {
		
	}
	| IDENTIFIER {
		symbol* id = lookup($1);
		symbol* f = NULL;
		if(id!=NULL) {
			switch(id->mode) {
				case ARGUMENT_MODE:					
					f = lookup(id->funcName);
					fprintf(fptr, "\tlw t0, %d(s0)\n", f->totalArgs *(-4)-48 +id->offset*(-4)-4);
					fprintf(fptr, "\taddi sp, sp, -4\n");
					fprintf(fptr, "\tsw t0, 0(sp)\n");
				break;
		  		case LOCAL_MODE:
					fprintf(fptr, "\tlw  t0, %d(s0) \n",id->offset*(-4)-48);
					fprintf(fptr, "\taddi sp, sp, -4\n");
					fprintf(fptr, "\tsw t0, 0(sp)\n");
					fprintf(fptr, "\n");
				break;
		  		default: /* Global Vars */
					fprintf(fptr, "\tlui t0,%%hi(%s)\n", id->name);
					fprintf(fptr, "\tlw t1, %%lo(%s)(t0)\n", id->name);
					fprintf(fptr, "\taddi sp, sp, -4\n");
					fprintf(fptr, "\tsw t1, 0(sp)\n");

			}
		} 
		$$=$1;
	}
	| STRING_LITERAL { }
	;

%%

void codeGen() {
}

void handleParams(char* name) {
	symbol* s = lookup(name);
	s->type = T_FUNCTION;
	char* fname = strdup(name);
	int totalArgs = s->totalArgs = numOfSymbols-s->id-1;
	int i;
	int index=s->id;
	for (i=totalArgs, s=table; i>0&&s!=NULL; i--, s=s->next) {
		s->scope = cur_scope;
		s->offset = i;
		s->mode = ARGUMENT_MODE;
		s->funcName = fname;
	}
	//printTable();
}

void funcBegin(char* name) {
	fprintf(fptr, "%s:\n", name);
	fprintf(fptr, "\tsw s0, -4(sp)\n");
	fprintf(fptr, "\taddi sp, sp, -4\n");
	fprintf(fptr, "\taddi s0, sp, 0\n");
	fprintf(fptr, "\tsw sp, -4(s0)\n");
	int i;
	for(i=1; i<12; i++)
		fprintf(fptr, "\tsw s%d, %d(s0)\n", i, -4+(-4)*i);
	fprintf(fptr, "\taddi sp, s0, %d\n", -48);
	fprintf(fptr, "\n");
}

void funcEnd(char* name) {
	int i;
	for(i=11; i>=1; i--)
		fprintf(fptr, "\tlw s%d, %d(s0)\n", i, -4+(-4)*i);
	fprintf(fptr, "\tlw sp, -4(s0)\n");
	fprintf(fptr, "\taddi sp, sp, 4\n");
	fprintf(fptr, "\tlw s0, -4(sp)\n");	
	fprintf(fptr, "\n");
	fprintf(fptr, "\tjalr zero, 0(ra)\n");
	offset = 0;
}

void callFunc(char* name, int cnt) {
	//printf("%s's argc: %d", name, cnt);
	int i;
	for(i=cnt-1; i>=0; i--) {
		fprintf(fptr, "\tlw a%d, 0(sp)\n", i);
		fprintf(fptr, "\taddi sp, sp, 4\n");
	}
	fprintf(fptr, "\tsw ra, -4(sp)\n");
	fprintf(fptr, "\taddi sp, sp, -4\n");
	fprintf(fptr, "\tjal ra, %s\n", name);
	fprintf(fptr, "\tlw ra, 0(sp)\n");
	fprintf(fptr, "\taddi sp, sp, 4\n");
	fprintf(fptr, "\n");
	argc=0;
}

symbol* put(char *name) {
  symbol *ptr;
  ptr = (symbol*)malloc(sizeof(symbol));
  ptr->name = strdup(name);
  ptr->next = (symbol*)table;
  table = ptr;
  return ptr;
}
symbol* get(char *name) {
	symbol *ptr;
	for (ptr=table; ptr!=(symbol *)0; ptr = (symbol *)ptr->next) {
    	if (strcmp(ptr->name, name) == 0)
      		return ptr;
  	}
	return 0;
}

symbol* lookup(char* name) {
	if(check(name)) {
		symbol* s;
		s = get(name);
		printf("lookup: %s\n", name);
		return s;
	}
	else {
    	printf("%s is not defined\n", name);
		return NULL;
	}
}

void popScope(int scope) {
	symbol* pre;
	symbol* s = table;
	while(s!=NULL) {
		if(s==table&&s->scope==scope) {
			symbol* tmp = s->next;
			free(s);
			s = tmp;
			table = s;
			numOfSymbols--;
		}
		else if(s->scope==scope) {
			symbol* tmp = s->next;
			pre->next = tmp;
			free(s);
			s = tmp;
			numOfSymbols--;
		}
		else {
			pre = s;
			s = s->next;
		}
	}
}

symbol* install(char *name) {  
	symbol* s;
   	s = get(name);
   	if(s == 0 || s->scope!=cur_scope) {
		printf("install %s\n", name);
    	s = put(name);
		s->scope = cur_scope;
		s->id = numOfSymbols;
		numOfSymbols++;
		if(cur_scope!=0) {
			offset++;
			s->offset = offset;
			s->mode = LOCAL_MODE;
		}
		return s;
	}
   	else if(s->type==T_FUNCTION) {
		s->id = numOfSymbols;
		numOfSymbols++;
		//printf("%s is already defined\n", name);
   		return s;
	}
	else {
		printf("%s is already defined\n", name);
	}
}

int check(char *name) { 
	if(get(name) == 0 && strcmp(name, "digitalWrite")==1 && strcmp(name, "delay")==1) {
    	printf("%s is an undeclared identifier\n", name);
		return 0;
	}
	return 1;
}

void printTable() {
	printf("Table:\n");
	symbol* s = table;
	while(s!=NULL) {
		printf("symbol: scope=%d, name=%s, type=%d, id=%d, mode=%d, offset=%d func=%s\n", s->scope, s->name, s->type, s->id, s->mode, s->offset, s->funcName);
		s = s->next;
	}
}

int main()
{
	fptr = fopen("codegen.S", "w+");
	yyparse();
	return 0;
}
int yyerror(char *s) 
{
	printf("YACC> Error at line %d.\n", errline);
	return 0;
}
