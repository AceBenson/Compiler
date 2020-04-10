%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lcnt=0;
int offset=0;
char buf[300];
%}

%x C_COMMENT
%x C_COMMENT_L

TYPE int|double|float|char
DIGIT [0-9]
ALPHA [a-zA-Z_]
ID [a-zA-Z][a-z0-9A-Z]*
SPACE " "

%%
"//"            { BEGIN(C_COMMENT_L); strcpy(&buf[offset], yytext); offset+=2;}
<C_COMMENT_L>.  { strcpy(&buf[offset], yytext); offset++;}
<C_COMMENT_L>\n { lcnt++; buf[offset]='\0'; printf("%d:%s\n", lcnt, buf); offset=0; BEGIN(INITIAL); }
"/*"            { BEGIN(C_COMMENT); strcpy(&buf[offset], yytext); offset+=2;}
<C_COMMENT>"*/" { BEGIN(INITIAL); strcpy(&buf[offset], yytext); offset+=2;}
<C_COMMENT>\t   { strcpy(&buf[offset], yytext); offset++;}
<C_COMMENT>\n   { strcpy(&buf[offset], yytext); offset++;}
<C_COMMENT>.    { strcpy(&buf[offset], yytext); offset++;}
{TYPE}|void|const|NULL|for|do|while|break|continue|if|else|return|struct|switch|case|default|fclose|clearerr|feof|ferror|fflush|fgetpos|fopen|fread|freopen|fseek|fsetpos|ftell|fwrite|remove|rename|rewind|setbuf|setvbuf|tmpfile|tmpnam|fprintf|printf|sprintf|vfprintf|vprintf|vsprintf|fscanf|scanf|sscanf|fgetc|fgets|fputc|fputs|getc|getchar|gets|putc|putchar|puts|ungetc|perror {
	printf("#token key:"); 
	ECHO; 
	printf("\n");
	strcpy(&buf[offset], yytext);
	offset += yyleng;
}
({ALPHA}{DIGIT}*)+|{ALPHA}+ { strcpy(&buf[offset], yytext); offset+=yyleng; printf("#token id:"); ECHO; printf("\n"); }
"+"|"-"|"*"|"/"|"%"|"++"|"--"|"<"|"<="|">"|">="|"=="|"!="|"="|"&&"|"||"|"!"|"&"|"|" { strcpy(&buf[offset], yytext); offset+=yyleng; printf("#token op:"); ECHO; printf("\n"); }
":"|";"|","|"."|"["|"]"|"("|")"|"{"|"}" { strcpy(&buf[offset], yytext); offset+=yyleng; printf("#token punc:"); ECHO; printf("\n"); }
[+-]?{DIGIT}+ { strcpy(&buf[offset], yytext); offset+=yyleng; printf("#token integer:"); ECHO; printf("\n"); }
[+-]?{DIGIT}*"."{DIGIT}+ { strcpy(&buf[offset], yytext); offset+=yyleng; printf("#token double:"); ECHO; printf("\n"); }
'.'|'\\n' { strcpy(&buf[offset], yytext); offset+=yyleng; printf("#token char:"); ECHO; printf("\n"); }
"\""(.|\\n)*"\"" { strcpy(&buf[offset], yytext); offset+=yyleng; printf("#token string:"); ECHO; printf("\n"); }
\n {
	lcnt++;
	buf[offset] = '\0';
	printf("%d:%s\n", lcnt, buf); 
	offset=0;
}
([ ])+|(\t)+ { strcpy(&buf[offset], yytext); offset+=yyleng;}
. { buf[offset]=yytext[0]; offset++; }
%%

int main(void)
{
	yylex();
	return 0;
}
