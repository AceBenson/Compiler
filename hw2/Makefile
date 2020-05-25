build: parser
parser: lex.yy.c y.tab.c
	gcc -o parser lex.yy.c y.tab.c -lfl
lex.yy.c: scanner.l
	flex scanner.l
y.tab.c: parser.y
	byacc -v -d parser.y
clean:
	rm -f lex.yy.c y.tab.c y.tab.h parser
