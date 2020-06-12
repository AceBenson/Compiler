cd ta/
cd 
cd hw1/
touch testcase2
vim testcase2
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
vim testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim testcase2
./a.out < testcase2
vim scanner.l 
gcc lex.yy.c -lfl
flex scanner.l 
gcc lex.yy.c -lfl
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
./a.out < testcase_basic
vim testcase2
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim testcase2
./a.out < testcase2
cd ../
git status
git add .
git commit -m "support comment and string"
cd hw1/
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
vim scanner.l 
vim testcase2
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase2
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase1
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase_basic
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase_basic
vim scanner.l 
vim testcase_basic
./a.out < testcase_basic
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase_basic
vim scanner.l 
vim testcase_basic
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase_basic
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase_basic
vim scanner.l 
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase_basic
vim testcase_basic
flex scanner.l 
gcc lex.yy.c -lfl
./a.out < testcase_basic
vim scanner.l 
diff ./a.out < testcase_basic testcase_basic.out
logout
cd hw1/
touch Makefile
vim Makefile 
make
vim Makefile 
make scanner.l
vim Makefile 
make
ls
rm a.out
rm lex.yy.c 
ls
vim Makefile 
cat -e -t -v Makefile
vim Makefile 
make
ls
cd ../
ls
rm -rf text
ls
rm -rf test
ls
git status
git add .
git commit -m "add makefile"
cd hw1/
ls
golden_scanner < testcase1
diff --help
diff (golden_scanner < testcase1) (scanner < testcase1)
diff <(golden_scanner < testcase1) <(scanner < testcase1)
ls
diff <(golden_scanner < testcase1) <(./scanner < testcase1)
ls
diff --help
diff -s <(golden_scanner < testcase1) <(./scanner < testcase1)
vim /dev/fd/62
diff -s <(golden_scanner < testcase1) <(./scanner < testcase2)
diff -s <(golden_scanner < testcase1) <(./scanner < testcase1)
diff -s <(golden_scanner < testcase_basic) <(./scanner < testcase_basic)
diff -s <(golden_scanner < testcase2) <(./scanner < testcase2)
./scanner
vim scanner.l 
./scanner
vim scanner.l 
make
./scanner
diff -s <(golden_scanner < testcase_basic) <(./scanner < testcase_basic)
diff -s <(golden_scanner < testcase1) <(./scanner < testcase1)
logout
cd hw1/
ls
logout
cd hw1/
vim testcase_string
diff -s <(golden_scanner < testcase_string) <(./scanner < testcase_string)
vim scanner.l 
make
scanner
./scanner 
vim scanner.l 
make
./scanner 
vim scanner.l 
make
vim scanner.l 
make
./scanner 
vim scanner.l 
make
./scanner 
vim scanner.l 
make
vim scanner.l 
make
./scanner 
vim scanner.l 
make
./scanner 
diff -s <(golden_scanner < testcase_string) <(./scanner < testcase_string)
vim scanner.l 
make
diff -s <(golden_scanner < testcase_string) <(./scanner < testcase_string)
diff -s <(golden_scanner < testcase_basic) <(./scanner < testcase_basic)
diff -s <(golden_scanner < testcase1) <(./scanner < testcase1)
./scanner 
vim scanner.l 
make
diff -s <(golden_scanner < testcase1) <(./scanner < testcase1)
diff -s <(golden_scanner < testcase2) <(./scanner < testcase2)
diff -s <(golden_scanner < testcase_basic) <(./scanner < testcase_basic)
logout
cd hw1/
ls
vim Makefile 
logout
cd hw1/
vim scanner.l
logout
ls
mkdir hw2
cp hw1/scanner.l hw2
cd hw2
ls
touch parser.y
cp ../hw1/Makefile /
chmod 777 ./ 
cp ../hw1/Makefile /
cd ../
cd hw2
vim ../hw1/Makefile 
vim Makefile
ls
make
vim Makefile 
make
vim Makefile 
make
vim parser.y 
vim Makefile 
make
vim Makefile 
make
vim Makefile 
make
ls
rm *.o *.h *.c
ls
make
vim parser.y
make
vim parser.y
make
vim parser.y
make
vim Makefile 
ls
vim y.tab.h
vim y.tab.c
vim scanner.l 
make
vim Makefile 
logout
( cd ~/hw1 && make -B && diff <( cat [testcase].txt | ./scanner; ) <( cat [testcase].txt | golden_scanner; ) && echo revisit; )
touch comment.txt
vim comment.txt 
( cd ~/hw1 && make -B && diff <( cat comment.txt | ./scanner; ) <( cat comment.txt | golden_scanner; ) && echo revisit; )
cd hw1
( cd ~/hw1 && make -B && diff <( cat comment.txt | ./scanner; ) <( cat comment.txt | golden_scanner; ) && echo revisit; )
cd ../
mv comment.txt ~/hw1
( cd ~/hw1 && make -B && diff <( cat comment.txt | ./scanner; ) <( cat comment.txt | golden_scanner; ) && echo revisit; )
cd hw1
vim scanner.l 
./scanner
vim scanner.l 
./scanner
vim scanner.l 
./scanner
golden_scanner
vim scanner.l 
make
./scanner 
( cd ~/hw1 && make -B && diff <( cat comment.txt | ./scanner; ) <( cat comment.txt | golden_scanner; ) && echo revisit; )
./scanner < comment.txt
vim scanner.l 
make
vim scanner.l 
make
vim scanner.l 
make
./scanner < comment.txt
vim scanner.l 
logout
cd hw2
ls
make
vim scanner.l 
make
vim parser.y 
vim Makefile 
make
vim parser.y 
make
vim scanner.l 
make
vim scanner.l 
vim parser
vim parser.y 
make
cp ../hw1/testcase ./
cp ../hw1/testcase.txt  ./
ls ../hw1
cp ../hw1/testcase1  ./
./parser testcase1 
golder_parser
golden_parser
cd hw2
vim parser.y 
./parser 
vim scanner.l 
vim parser.y
make
vim parser.y
make
vim y.tab.h
vim parser.y
vim Makefile 
make
vim Makefile 
make
vim parser.y 
make
vim parser.y 
vim scanner.l 
make
vim scanner.l 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
cd hw2
vim parser
vim parser.y
make
vim parser.y
make
vim parser.y
make
vim scanner.l
make
vim scanner.l
vim Makefile 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
vim scanner.l 
make
vim scanner.l 
vim parser.y
make
vim parser.y
make
vim scanner.l 
vim parser.y
logout
cd hw2
vim parser.yu
vim parser.y
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
vim scanner.l
vim parser.y 
make
vim parser.y 
make
vim parser.y 
vim scanner.l 
make
vim parser.y 
make
vim parser.y 
make
vim scanner.l 
vim parser.y 
make
vim parser.y 
vim scanner.l 
make
vim scanner.l 
make
./parser 
vim parser.y 
make
./parser 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim scanner.l 
make
vim parser.y 
vim scanner.l 
make
vim scanner.l 
vim parser.y 
vim scanner.l 
./parser 
vim parser.y 
vim scanner.l 
make
./parser 
vim scanner.l 
make
./parser 
vim scanner.l 
vim parser.y 
make
vim parser.y 
make
./parser 
1+1;
./parser 
vim parser.y 
make
./parser 
vim parser.y 
make
./parser 
vim parser.y 
make
./parser 
make
vim parser.y 
make
vim scanner.l 
make
./parser 
vim parser.y 
make
vim parser.y 
make
./parser 
vim parser.y 
vim scanner.l 
vim parser.y 
make
./parser 
vim parser.y 
make
vim parser.y 
vim scanner.l 
vim parser.y 
make
./parser 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser
vim parser.y 
./parser
make
vim parser.y 
make
vim parser.y 
make
vim scanner.l 
make
./parser 
vim scanner.l 
make
./parser 
vim parser.y 
make
vim parser.y 
make
./parser 
vim parser.y 
make
vim parser.y 
make
./parser 
vim parser.y 
make
./parser 
vim parser.y 
vim scanner.l 
make
vim scanner.l 
make
./parser 
mkdir testcase
cd testcase/
touch scalar_decl.c
touch expr.c
touch array_decl.c
vim scalar_decl.c 
vim expr.c 
vim array_decl.c 
cd ../
./parser < testcase/scalar_decl.c 
./parser < testcase/expr.c 
./parser 
vim parser.y 
./parser 
vim parser
vim parser.y 
make
./parser 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim scanner.l 
vim parser.y 
make
vim scanner.l 
make
./parser 
vim parser.y 
./parser 
touch testcase/test.c
vim testcase/test.c 
./parser < testcase/test.c 
vim parser.y 
make
vim parser.y 
make
./parser < testcase/test.c 
./parser 
./parser < testcase/expr.c 
./parser 
vim parser.y 
make
./parser 
vim parser.y 
./parser 
make
vim parser.y 
make
./parser 
vim parser.y 
make
vim parser.y 
make
./parser 
touch testcase/castle.c
vim testcase/castle.c 
./parser < testcase/castle.c 
./parser 
vim parser.y 
make
vim parser.y 
make
vim scanner.l 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser 
./parser < testcase/castle.c 
./parser 
vim parser.y 
make
./parser 
vim parser.y 
make
./parser 
vim scanner.l 
vim parser.y 
make
./parser 
vim parser.y 
./parser 
vim scanner.l 
vim parser.y 
make
./parser 
./parser < testcase/castle.c 
./parser 
vim testcase/castle.c 
vim scanner.l 
vim parser.y 
make
vim scanner.l 
make
./parser 
vim scanner.l 
make
vim scanner.l 
make
./parser 
vim scanner.l 
make
./parser 
vim scanner.l 
make
./parser 
vim parser.y 
vim scanner.l 
make
./parser < testcase/castle.c 
vim scanner.l 
make
./parser < testcase/castle.c 
./parser 
vim parser.y 
./parser 
vim parser.y 
make
./parser < testcase/castle.c 
./parser 
vim parser.y 
./parser 
vim scanner.l 
make
1
./parser 
vim scanner.l 
vim parser.y 
vim scanner.l 
vim parser.y 
make
./parser 
vim parser.y 
make
./parser 
vim parser.y 
make
./parser 
vim parser.y 
make
./parser 
vim parser.y 
./parser 
vim parser.y 
./parser testcase/test.c 
./parser < testcase/test.c 
make
./parser < testcase/test.c 
./parser 
vim scanner.l 
make
./parser 
./parser < testcase/castle.c 
vim parser.y 
vim scanner.l 
cd ../
git status
git add .
git commit -m "hw2 first commit"
logout
cd hw2/
ls
vim testcase1
./parser < testcase1
vim scanner.l
make
./parser < testcase1
vim scanner.l
cd hw2
vim parser.y 
make
./parser < testcase1
./parser < testcase/castle.c 
vim scanner.l
make
./parser < testcase/castle.c 
vim parser.y 
,ale
make
./parser < testcase/castle.c 
vim scanner.l 
./parser 
golden_parser < testcase/castle.c 
vim testcase/castle.c 
golden_parser < testcase/castle.c 
golden_parser
vim testcase/castle.c 
golden_parser
vim Makefile 
make
ls
rm scanner
ls
make
vim Makefile 
make
ls
vim Makefile 
make
vim parser.y 
golden_parser < testcase/test.c 
vim testcass/test.c
vim testcase/test.c
golden_parser < testcase1
vim parser.y 
make
./parser < testcase1
vim parser.y 
vim scanner.l 
vim parser.y 
make
./parser < testcase1
vim parser.y 
vim scanner.l 
make
./parser < testcase1
vim parser.y 
golden_parser < testcase1
vim parser.y 
logout
cd hw2
vim parser.y 
vim scanner.l 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
vim scanner.l 
vim parser.y 
make
vim parser.y 
make
./parser < testcase1
vim parser.y 
make
./parser < testcase1
vim scanner.l 
make
./parser < testcase1
make
./parser < testcase1
vim parser.y 
make
./parser < testcase1
vim parser.y 
make
./parser < testcase1
vim parser.y 
./parser 
vim parser.y 
make
./parser 
vim parser.y 
make
./parser 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
vim scanner.l 
vim parser.y 
make
vim parser.y 
make
./parser < testcase1
vim parser.y 
cd hw2
vim parser.y 
clean
cd hw2
vim parser.y 
make
vim parser.y 
vim scanner.l 
vim parser.y 
make
vim parser.y 
make
./parser <testcase1
./parser
vim parser.y 
make
vim parser
vim parser.y 
make
./parser < testcase1
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser < testcase1
vim testcase1
vim parser.y 
make
./parser < testcase1
golden_parser < testcase1
vim parser.y 
make
./parser < testcase1
vim scanner.l 
make
./parser < testcase1
vim scanner.l 
vim parser.y 
cd hw2
make
./parser < testcase/expr.c 
make
./parser < testcase/expr.c 
make
./parser < testcase/expr.c 
make
./parser < testcase/expr.c 
make
./parser < testcase/expr.c 
./parser < testcase/basic 
golden_parser < testcase/basic 
diff <(golden_parser < testcase1) <(./parser < testcase1)
./parser < testcase1
vim testcase1
./parser < testcase1
./parser 
vim testcase/basic 
./parser < testcase/basic 
make
./parser < testcase/basic 
diff <(golden_parser < testcase1) <(./parser < testcase1)
make
diff <(golden_parser < testcase1) <(./parser < testcase1)
diff <(golden_parser < testcase/basic) <(./parser < testcase/basic)
vim testcase/basic 
./parser < testcase/basic 
make
diff <(golden_parser < testcase1) <(./parser < testcase1)
./parser < testcase1
golden_parser < testcase1
diff <(cat testcase1 | golden_parser) <(cat testcase1 | ./parser)
make
diff <(cat testcase1 | golden_parser) <(cat testcase1 | ./parser)
diff <(golden_parser < testcase1) <(./parser < testcase1)
diff <(golden_parser < testcase/basic) <(./parser < testcase/basic)
diff <(golden_parser < testcase/expr.c) <(./parser < testcase/expr.c)
ls testcase
diff <(golden_parser < testcase/array_decl.c) <(./parser < testcase/array_decl.c)
./parser < testcase/array_decl.c 
golden_parser < testcase/array_decl.c 
vim testcase/basic 
golden_parser < testcase/array_decl.c 
golden_parser < testcase/basic 
diff <(golden_parser < testcase/basic) <(./parser < testcase/basic)
./parser < testcase/basic 
logout
cd hw2
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser < testcase1
vim parser.y 
./parser 
vim parser.y 
vim scanner.l 
make
./parser < testcase1
vim parser.y 
make
vim parser.y 
make
vim parser.y 
golden_parser < testcase1
make
./parser < testcase1
vim parser.y 
make
vim parser.y 
make
./parser < testcase1
./parser
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
touch testcase/easy
vim testcase/easy
./parser < testcase/easy
vim parser.y 
vim testcase/easy
./parser < testcase/easy
vim parser.y 
make
vim parser.y 
vim testcase/easy 
make
./parser < testcase/easy 
vim scanner.l 
make
./parser < testcase/easy 
golden_parser < testcase/easy 
vim scanner.l 
vim parser.y 
make
./parser < testcase/easy 
vim parser.y 
make
./parser < testcase/easy 
golden_parser < testcase/easy 
make
ls testcase
mv testcase/easy testcase/sample
vim parser.y 
make
mv testcase/sample testcase/b
mv testcase/easy testcase/basic 
golden_parser < testcase/basic 
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
make
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
vim scanner.l 
make
./parser < testcase/basic 
vim scanner.l 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
vim scanner.l 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
vim testcase/basic 
vim parser.y 
make
vim testcase/basic 
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim scanner.l 
make
./parser < testcase/basic 
vim scanner.l 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
./parser 
vim parser.y 
make
./parser < testcase/basic 
./parser 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
vim scanner.l 
make
./parser < testcase/basic 
vim scanner.l 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
golden_parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
make
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
./parser testcase1
./parser < testcase1
vim parser.y 
make
vim parser.y 
make
./parser < testcase1
vim parser.y 
make
./parser < testcase/basic 
golden_parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
golden_parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
golden_parser < testcase/basic 
vim testcase/basic 
./parser < testcase/basic 
golden_parser < testcase/basic 
vim testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
vim testcase/basic 
golden_parser < testcase/basic 
vim scanner.l 
vim parser.y 
vim testcase/basic 
golden_parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser testcase/basic 
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
golden_parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim scanner.l 
make
./parser < testcase/basic 
vim scanner.l 
make
./parser < testcase/basic 
vim scanner.l 
make
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser testcase/basic 
./parser < testcase/basic 
vim parser.y 
vim testcase1
./parser < testcase1
./parser 
vim testcase1
./parser 
vim testcase1
./parser 
vim testcase1
vim testcase/basic 
./parser <testcase/basic 
vim scanner.l 
make
./parser <testcase/basic 
vim testcase/basic 
./parser 
vim testcase/basic 
./parser <testcase/basic 
vim parser.y 
vim scanner.l 
vim parser.y 
make
vim parser.y 
make
./parser testcase/basic 
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser < testcase/basic 
vim testcase/basic 
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
golden_parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
./parser 
vim parser.y 
golden_parser 
vim parser.y 
vim testcase/basic 
./parser < testcase/basic 
vim testcase/basic 
golden_parser < testcase/basic 
vim testcase/basic 
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
ls
vim y.output 
vim parser.y 
make
./parser < testcase/basic 
vim testcase/basic 
./parser < testcase/basic 
vim scanner.l 
make
./parser < testcase/basic 
make
vim scanner.l 
make
./parser < testcase/basic 
vim parser.y 
make
vim parser.y 
make
vim testcase/expr.c 
golden_parser < testcase/expr.c 
./parser < testcase/expr.c 
vim testcase/expr.c 
vim parser.y 
make
./parser < testcase/expr.c 
vim parser.y 
make
./parser < testcase/basic 
./parser < testcase/expr.c 
vim parser.y 
make
./parser < testcase/expr.c 
vim parser.y 
make
./parser < testcase/expr.c 
vim parser.y 
make
./parser < testcase/expr.c 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./parser < testcase/expr.c 
vim parser.y 
make
./parser < testcase/expr.c 
vim parser.y 
make
./parser < testcase/expr.c 
vim parser.y 
make
./parser < testcase/expr.c 
vim parser.y 
cd hw2
./parser 
vim testcase/basic 
./parser testcase/basic 
./parser < testcase/basic 
logout
cd hw2
touch testcase/switch
vim testcase/switch 
./parser < testcase/switch 
golden_parser < testcase/switch 
vim parser.y 
make
./parser < testcase/switch 
golden_parser < testcase/switch 
vim parser.y 
make
./parser <testcase/switch 
diff <(./parser < testcase/switch) <(golden_parser < testcase/switch)
vim testcase
ls testcase
logout
cd hw2
touch testcase/while
vim testcase/while 
diff <(./parser < testcase/while) <(golden_parser < testcase/while)
./parser < testcase/while 
vim scanner.l 
vim testcase/scalar_decl.c 
./parser < testcase/scalar_decl.c 
vim testcase/scalar_decl.c 
./parser < testcase/scalar_decl.c 
diff <(./parser < testcase/scalar_decl.c) <(golden_parser < testcase/scalar_decl.c)
vim testcase/scalar_decl.c 
vim scanner.l 
make
./parser < testcase/scalar_decl.c 
diff <(./parser < testcase/while) <(golden_parser < testcase/while)
vim scanner.l 
make
vim testcase/scalar_decl.c 
./parser < testcase/scalar_decl.c 
diff <(./parser < testcase/scalar_decl.c) <(golden_parser < testcase/scalar_decl.c)
vim testcase/scalar_decl.c 
diff <(./parser < testcase/scalar_decl.c) <(golden_parser < testcase/scalar_decl.c)
vim parser.y 
logout
cd hw2
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
vim scanner.l 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
./parser 
vim parser.y 
make
./parser 
vim parser.y 

./parser 
vim parser.y 
make
./parser < testcase/basic 
logout
cd hw2
./parser 
vim parser.y 
vim scanner.l 
vim parser.y 
make
touch testcase/error
vim testcase/error 
./parser < testcase/error 
vim scanner.l 
vim parser.y 
make
./parser < testcase/error 
golden_parser < testcase/error 
vim parser.y 
make
vim parser.y 
make
./parser < testcase/error 
diff <(./parser < testcase/expr.c ) <(golden_parser < testcase/expr.c)
vim parser.y 
make
./parser < testcase/scalar_decl.c 
vim parser.y 
cd ../
git status
git add .
git commit -m "free ptr"
logout
cd hw2
make
./parser < testcase/expr.c 
./parser < testcase/basic 
make
./parser < testcase/basic 
make
./parser < testcase/basic 
make
./parser < testcase/basic 
make
./parser < testcase/basic 
make
./parser < testcase/basic 
make
./parser < testcase/basic 
make
./parser < testcase/basic 
logout
cd hw2
vim parser
vim parser.y 
cd ../
mkdir hw3
cp hw2/scanner.l hw3
cp hw2/parser.y hw3
cd hw3
ls
cp ../hw2/Makefile ./
ls
vim Makefile 
logout
cd hw2
vim parser.y 
make
./parser < testcase/basic 
vim parser.y 
make
logout
cd hw2
ls
./parser < testcase/castle.c 
vim testcase/castle.c 
./parser < testcase/castle.c 
./parser < testcase/basic 
vim testcase/castle.c 
./parser < testcase/basic 
./parser < testcase/castle.c 
vim parser.y 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim testcase/castle.c 
vim parser.y 
vim testcase/castle.c 
vim testcase/basic 
./parser < testcase/basic 
vim parser.y 
make
./parser < testcase/basic 
./parser < testcase/castle.c 
vim parser.y 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim scanner.l 
vim ../hw1/scanner.l 
vim scanner.l 
make
vim scanner.l 
make
./parser < testcase/castle.c 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim testcase/castle.c 
vim parser.y 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim testcase/castle.c 
vim parser.y 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim parser.y 
make
./parser < testcase/castle.c 
vim testcase/castle.c 
./parser < testcase/castle.c 
vim scanner.l 
vim parser.y 
make
./parser < testcase/castle.c 
vim testcase/castle.c 
./parser < testcase/castle.c 
logout
cd hw2
vim parser.y 
ls testcase
vim testcase/basic 
./parser < testcase/basic 
vim parser.y 
logout
cd hw2
golden_parser 
vim parser.y 
./parser 
vim parser.y 
make
./parser < testcase/basic 
cd hw2
vim testcase
ls testcase
./parser < testcase/array_decl.c 
diff <(./parser < testcase/array_decl.c ) <(golden_parser < testcase/array_decl.c )
diff <(./parser < testcase/basic ) <(golden_parser < testcase/basic )
diff <(./parser < testcase/castle.c ) <(golden_parser < testcase/castle.c )
vim testcase/castle.c 
diff <(./parser < testcase/castle.c ) <(golden_parser < testcase/castle.c )
ls testcase
diff <(./parser < testcase/expr.c ) <(golden_parser < testcase/expr.c )
diff <(./parser < testcase/scalar_decl.c ) <(golden_parser < testcase/scalar_decl.c )
diff <(./parser < testcase/switch ) <(golden_parser < testcase/switch )
diff <(./parser < testcase/test.c ) <(golden_parser < testcase/test.c )
vim testcase/test.c 
diff <(./parser < testcase/test.c ) <(golden_parser < testcase/test.c )
ls testcase
vim testcase/while 
diff <(./parser < testcase/while ) <(golden_parser < testcase/while )
vim parser.y 
logout
cd hw3
ls
cd ../hw2
vim parser.y 
logout
cd hw3
vim parser.y 
cd hw3
vim parser.y 
cd hw3
ls
ls Testcase/
vim Testcase/Basic/0.c 
vim parser.y 
logout
cd hw3
cd hw3
vim parser.y 
ls ../../
ls ../../ta
vim parser.y 
make
ls
vim Makefile 
make
vim Makefile 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
cd hw3
ls
logout
cd hw3
vim parser.y 
logout
cd hw3
ls
vim parser.y 
logout
cd hw3
ls
logout
cd hw3
vim test.c 
cd hw3
vim parser.y 
cd hw2
ls
cp parser.y parser_backup.y
ls
vim parser.y 
cd hw3
make
./codegen < Testcase/Branch/0.c 
touch test.c
vim test.c
make
./codegen < test.c 
vim test.c 
./codegen < test.c 
make
./codegen < test.c 
vim test.c 
make
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
./codegen < Testcase/Branch/0.c 
make
vim y.output 
make
./codegen < Testcase/Branch/0.c 
make
./codegen < Testcase/Branch/0.c 
make
./codegen < Testcase/Branch/0.c 
cd ../hw2
make
vim y.output 
cd ../hw3
make
./codegen < Testcase/Branch/0.c 
make
vim y.output 
make
./codegen < Testcase/Branch/0.c 
vim Testcase/Branch/0.c 
make
./codegen < Testcase/Branch/0.c 
make
./codegen < Testcase/Branch/0.c 
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
cd hw3
vim parser.y 
logout
cd hw3
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
vim test.c 
logout
cd hw3
vim parser.y 
cd hw3
./codegen < test.c 
make
./codegen < test.c 
make
./codegen < test.c 
cd hw3
vim parser.y 
cd hw3
vim parser.y 
make
./codegen < test.c 
vim parser.y 
make
vim parser.y 
./codegen < test.c 
vim parser.y 
make
vim parser.y 
make
./codegen < test.c 
vim test.c 
vim parser.y 
make
./codegen < test.c 
vim test.c 
./codegen < test.c 
vim parser.y 
make
./codegen < test.c 
vim parser.y 
make
./codegen < test.c 
vim parser.y 
make
vim codegen.S 
vim parser.y 
make
vim parser.y 
make
./codegen < test.c 
vim parser.y 
make
./codegen < test.c 
vim parser.y 
make
./codegen < test.c 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./codegen < test.c 
vim codegen.S 
vim parser.y 
make
./codegen < test.c 
vim codegen.S 
vim parser.y 
make
./codegen < test.c 
vim codegen.S 
vim parser.y 
make
./codegen < test.c 
vim codegen.S 
vim parser.y 
make
./codegen < test.c 
vim codegen.S 
vim parser.y 
make
./codegen < test.c 
vim codegen.S 
vim parser.y 
make
./codegen < test.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/Basic/0.c 
vim codegen.S 
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make\
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
./codegen < Testcase/Basic/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/Basic/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/Basic/0.c 
vim parser.y 
vim codegen.S 
./codegen < Testcase/ArithmeticExpression/0.c 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
../hw2/parser < Testcase/ArithmeticExpression/0.c 
vim parser.y 
make
vim parser.y 
make
../hw2/parser < Testcase/ArithmeticExpression/0.c 
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim parser.y 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
logout
cd hw3
make
./codegen < test.c 
vim codegen.S 
vim parser.y 
make
./codegen < test.c 
vim codegen.S 
vim test.c 
vim Testcase/Basic/0.c 
vim Testcase/Basic/1.c 
ls Testcase/
ls Testcase/ArithmeticExpression/
vim Testcase/ArithmeticExpression/0.c 
logout
cd hw3
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim parser.y 
vim codegen.S 
vim parser.y 
make
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
./codegen < test.c
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/ArithmeticExpression/0.c 
vim codegen.S 
vim parser.y 
make
cd ../
git add .
git commit -m "hw3 1st"
cd hw3
./codegen < Testcase/Function/0.c 
vim codegen.S 
vim parser.y 
vim codegen.S 
vim parse
./codegen < Testcase/Branch/0.c 
vim Testcase/Branch/0.c 
vim codegen.S 
vim parser.y 
make
vim parser.y 
make
./codegen < Testcase/Branch/0.c 
logout
cd hw3
vim parser.y 
make
vim parser.y 
make
vim parser.y 
make
vim y.output 
vim parser.y 
make
./codegen < Testcase/Branch/0.c 
vim codegen.S 
vim parser.y 
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/Branch/1.c 
vim codegen.S 
vim parser.y 
make
vim codegen.S 
vim parser.y 
make
./codegen < Testcase/Branch/0.c 
vim codegen.S 
logout
git add .
git commit -m "first commit"
git remote add origin https://github.com/bruce1198/Compiler.git
git push -u origin master
logout
