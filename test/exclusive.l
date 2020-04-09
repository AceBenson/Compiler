%{
#include <stdio.h>
%}

%x COMMENT

%%

"/*" {BEGIN COMMENT;}
int {printf("normal\n");}
<COMMENT>int {printf("special\n");BEGIN 0;}

%%
