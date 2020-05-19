%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int sourceon = 1;
int tokenon = 1;
int target;

void count();

%}

%x PROGMA
%x C_COMMENT
%x C_COMMENT_L

D [0-9]
L [a-zA-Z_]

%%
"#pragma"       { BEGIN(PROGMA); }
<PROGMA>source  { target=0; }
<PROGMA>token   { target=1; }
<PROGMA>on      { 
	if(target) tokenon=1;
	else sourceon=1; 
}
<PROGMA>off     {
	if(target) tokenon=0;
	else sourceon=0;
}
<PROGMA>[ \t] { }
<PROGMA>\n { BEGIN(INITIAL); }

"//"            { BEGIN(C_COMMENT_L); }
<C_COMMENT_L>.  { }
<C_COMMENT_L>\n { BEGIN(INITIAL); }
"/*"            { BEGIN(C_COMMENT);}
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>[ \t\n.]   { }
fclose|clearerr|feof|ferror|fflush|fgetpos|fopen|fread|freopen|fseek|fsetpos|ftell|fwrite|remove|rename|rewind|setbuf|setvbuf|tmpfile|tmpnam|fprintf|printf|sprintf|vfprintf|vprintf|vsprintf|fscanf|scanf|sscanf|fgetc|fgets|fputc|fputs|getc|getchar|gets|putc|putchar|puts|ungetc|perror { count(); return FUNCTION; }
L?\"(\\.|[^\\"])*\" { count(); return(STRING_LITERAL); }
"auto"			{ count(); return(AUTO); }
"break"			{ count(); return(BREAK); }
"case"			{ count(); return(CASE); }
"char"			{ count(); return(CHAR); }
"const"			{ count(); return(CONST); }
"continue"		{ count(); return(CONTINUE); }
"default"		{ count(); return(DEFAULT); }
"do"			{ count(); return(DO); }
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"enum"			{ count(); return(ENUM); }
"extern"		{ count(); return(EXTERN); }
"float"			{ count(); return(FLOAT); }
"for"			{ count(); return(FOR); }
"goto"			{ count(); return(GOTO); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"register"		{ count(); return(REGISTER); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"signed"		{ count(); return(SIGNED); }
"sizeof"		{ count(); return(SIZEOF); }
"static"		{ count(); return(STATIC); }
"struct"		{ count(); return(STRUCT); }
"switch"		{ count(); return(SWITCH); }
"typedef"		{ count(); return(TYPEDEF); }
"union"			{ count(); return(UNION); }
"unsigned"		{ count(); return(UNSIGNED); }
"void"			{ count(); return(VOID); }
"while"			{ count(); return(WHILE); }

({L}{D}*)+|{L}+ { count(); return IDENTIFIER; }

"<<" { count(); return(LEFT_OP); }
">>" { count(); return(RIGHT_OP); }
"<=" { count(); return(LE_OP); }
">=" { count(); return(GE_OP); }
"==" { count(); return(EQ_OP); }
"!=" { count(); return(NE_OP); }
"&&" { count(); return(AND_OP); }
"||" { count(); return(OR_OP); }
"++" { count(); return(INC_OP); }
"--" { count(); return(DEC_OP); }
"<" { count(); return '<'; }
">" { count(); return '>'; }
"=" { count(); return '='; }
"!" { count(); return '!'; }
"&" { count(); return '&'; }
"|" { count(); return '|'; }
"+" { count(); return '+'; }
"-" { count(); return '-'; }
"*" { count(); return '*'; }
"/" { count(); return '/'; }
"%" { count(); return '%'; }
":" { count(); return ':'; }
";" { count(); return ';'; }
"," { count(); return ','; }
"." { count(); return '.'; }
"[" { count(); return '['; }
"]" { count(); return ']'; }
"(" { count(); return '('; }
")" { count(); return ')'; }
"{" { count(); return '{'; }
"}" { count(); return '}'; }

{D}+ { count(); return(CONSTANT); }
{D}*"."{D}+ { count(); return(CONSTANT); }
'.'|'\\.' { count(); return(CONSTANT); }
[ \t\v\n\f] { count(); }
. { }
%%

int column = 0;

void count() {
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	//ECHO;
}

