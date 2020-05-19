%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lcnt=0;
int offset=0;
char buf[301];
char string[301];
int stroff=0;
int sourceon = 1;
int tokenon = 1;
int target;
void storeBuf() {
	strcpy(&buf[offset], yytext); offset+=yyleng;
}
//0:key, 1:id, 2:op, 3:punc, 4:integer, 5:double, 6:char, 7:string
void printToken(int type) {
	if(tokenon) {
		printf("#token ");
		switch(type) {
			case 0:
				printf("key");
			break;
			case 1:
                printf("id");
            break;
			case 2:
                printf("op");
            break;
			case 3:
                printf("punc");
            break;
			case 4:
                printf("integer");
            break;
			case 5:
                printf("double");
            break;
			case 6:
                printf("char");
            break;
			case 7:
                printf("string");
            break;
		}
		printf(":%s\n", yytext);
	}
}
void printSource() {
	if(sourceon) {
		printf("%d:%s\n", lcnt, buf);
	}
}
%}

%x STRING
%x PROGMA
%x C_COMMENT
%x C_COMMENT_L

TYPE int|double|float|char
DIGIT [0-9]
ALPHA [a-zA-Z_]
ID [a-zA-Z][a-z0-9A-Z]*
SPACE " "

%%
"#pragma"       { 
	BEGIN(PROGMA); 
	storeBuf();
}
<PROGMA>source  { 
	storeBuf();	
	target=0; 
}
<PROGMA>token   { 
	storeBuf();
	target=1; 
}
<PROGMA>on      { 
	storeBuf();
	if(target) tokenon=1;
	else sourceon=1; 
}
<PROGMA>off     {
	storeBuf();
	if(target) tokenon=0;
	else sourceon=0;
}
<PROGMA>{SPACE}|\t { 
	storeBuf();
}
<PROGMA>\n {
	lcnt++;
	buf[offset]='\0';
	printSource();
	offset=0; 
	BEGIN(INITIAL); 
}
"\"" { BEGIN(STRING); storeBuf(); string[stroff]='\"';stroff++;}
<STRING>"\"" { BEGIN(INITIAL); storeBuf(); string[stroff]='\"';string[stroff+1]='\0'; printf("#token string:%s\n", string);stroff=0;}
<STRING>.|\n|\t {string[stroff]=yytext[0];stroff++;storeBuf();}
"//"            { BEGIN(C_COMMENT_L); storeBuf();}
<C_COMMENT_L>.  { strcpy(&buf[offset], yytext); offset++;}
<C_COMMENT_L>\n { lcnt++; buf[offset]='\0'; printSource(); offset=0; BEGIN(INITIAL); }
"/*"            { BEGIN(C_COMMENT); storeBuf();}
<C_COMMENT>"*/" { BEGIN(INITIAL); storeBuf();}
<C_COMMENT>\t   { storeBuf();}
<C_COMMENT>\n   { storeBuf();}
<C_COMMENT>.    { storeBuf();}
{TYPE}|void|const|NULL|for|do|while|break|continue|if|else|return|struct|switch|case|default|fclose|clearerr|feof|ferror|fflush|fgetpos|fopen|fread|freopen|fseek|fsetpos|ftell|fwrite|remove|rename|rewind|setbuf|setvbuf|tmpfile|tmpnam|fprintf|printf|sprintf|vfprintf|vprintf|vsprintf|fscanf|scanf|sscanf|fgetc|fgets|fputc|fputs|getc|getchar|gets|putc|putchar|puts|ungetc|perror {
	storeBuf();
	printToken(0);
}
({ALPHA}{DIGIT}*)+|{ALPHA}+ { 
	storeBuf();
	printToken(1); 
}
"+"|"-"|"*"|"/"|"%"|"++"|"--"|"<"|"<="|">"|">="|"=="|"!="|"="|"&&"|"||"|"!"|"&"|"|" { 
	storeBuf();
	printToken(2);
}
":"|";"|","|"."|"["|"]"|"("|")"|"{"|"}" { 
	storeBuf();
	printToken(3);
}
[+-]?{DIGIT}+ { 
	storeBuf();
	printToken(4);
}
[+-]?{DIGIT}*"."{DIGIT}+ { 
	storeBuf();
	printToken(5);
}
'.'|'\\.' { 
	storeBuf();
	printToken(6);
}
\n {
	lcnt++;
	buf[offset] = '\0';
	printSource(); 
	offset=0;
}
([ ])+|(\t)+ { 
	storeBuf();
}
. { 
	storeBuf();
}
%%

int main(void)
{
	yylex();
	return 0;
}
