%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int errline=1;

%}

%x C_COMMENT
%x C_COMMENT_L

D [0-9]
L [a-zA-Z_]

%%

"//"            { BEGIN(C_COMMENT_L); }
<C_COMMENT_L>.  { }
<C_COMMENT_L>\n { BEGIN(INITIAL); }
"/*"            { BEGIN(C_COMMENT);}
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>[ \t\n.]   { }
fclose|clearerr|feof|ferror|fflush|fgetpos|fopen|fread|freopen|fseek|fsetpos|ftell|fwrite|remove|rename|rewind|setbuf|setvbuf|tmpfile|tmpnam|fprintf|printf|sprintf|vfprintf|vprintf|vsprintf|fscanf|scanf|sscanf|fgetc|fgets|fputc|fputs|getc|getchar|gets|putc|putchar|puts|ungetc|perror {  yylval.sval = yytext; return(FUNCTION); }
L?\"(\\.|[^\\"])*\" {  char* tmp = strdup(yytext); yylval.sval = tmp; return(STRING_LITERAL); }
"auto"			{  return(AUTO); }
"break"			{  return(BREAK); }
"case"			{  return(CASE); }
"char"			{  return(CHAR); }
"const"			{  return(CONST); }
"continue"		{  return(CONTINUE); }
"default"		{  return(DEFAULT); }
"do"			{  return(DO); }
"double"		{  return(DOUBLE); }
"else"			{  return(ELSE); }
"enum"			{  return(ENUM); }
"extern"		{  return(EXTERN); }
"float"			{  return(FLOAT); }
"for"			{  return(FOR); }
"goto"			{  return(GOTO); }
"if"			{  return(IF); }
"int"			{  return(INT); }
"long"			{  return(LONG); }
"register"		{  return(REGISTER); }
"return"		{  return(RETURN); }
"short"			{  return(SHORT); }
"signed"		{  return(SIGNED); }
"sizeof"		{  return(SIZEOF); }
"static"		{  return(STATIC); }
"struct"		{  return(STRUCT); }
"switch"		{  return(SWITCH); }
"typedef"		{  return(TYPEDEF); }
"union"			{  return(UNION); }
"unsigned"		{  return(UNSIGNED); }
"void"			{  return(VOID); }
"while"			{  return(WHILE); }

({L}{D}*)+|{L}+ {  char* tmp = strdup(yytext); yylval.sval = tmp; return(IDENTIFIER); }

"<<" 			{  return(LEFT_OP); }
">>" 			{  return(RIGHT_OP); }
"<=" 			{  return(LE_OP); }
">=" 			{  return(GE_OP); }
"==" 			{  return(EQ_OP); }
"!=" 			{  return(NE_OP); }
"&&" 			{  return(AND_OP); }
"||"			{  return(OR_OP); }
"++" 			{  return(INC_OP); }
"--" 			{  return(DEC_OP); }
"<" 			{  return '<'; }
">" 			{  return '>'; }
"=" 			{  return '='; }
"!" 			{  return '!'; }
"&" 			{  return '&'; }
"|" 			{  return '|'; }
"+" 			{  return '+'; }
"-" 			{  return '-'; }
"*" 			{  return '*'; }
"/" 			{  return '/'; }
"%" 			{  return '%'; }
":" 			{  return ':'; }
";" 			{  return ';'; }
"," 			{  return ','; }
"." 			{  return '.'; }
"[" 			{  return '['; }
"]" 			{  return ']'; }
"(" 			{  return '('; }
")" 			{  return ')'; }
"{" 			{  return '{'; }
"}" 			{  return '}'; }

{D}+ 			{  yylval.ival = atoi(yytext); return(CONSTANT); }
{D}*"."{D}+ 	{  yylval.dval = atof(yytext); return(FCONSTANT); }
'.'|'\\.' 		{ 
					
					if(strlen(yytext)==4) {
						switch(yytext[2]) {
							case 'n': yylval.cval = '\n'; break;
							case 't': yylval.cval = '\t'; break;
							case '\\': yylval.cval = '\\'; break;
							case '\'': yylval.cval = '\''; break;
						}
					}
					else 
						yylval.cval = yytext[1]; 
					return(CCONSTANT); 
				}
\n { errline++; }
[ \t\v\f] 	{  }
. 				{  }
%%


