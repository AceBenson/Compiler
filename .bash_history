ls
mkdir ./ssh
cd ./ssh/
ls
passwd
logout
cd ./ssh/
ls
ls -a
touch authorized_keys
cd ../
ls
rm -rf ssh/
ls -a
cd .ssh
mkdir .ssh
rm .ssh
mkdir .ssh
ls -a
cd .ssh/
ls
touch authorized_keys
cat id_rsa.pub authorized_keys 
logout
mkdir hw1
ls
logout
golden_scanner 
golden_scanner
ls
cd hw1/
touch testcase_basic
vim testcase_basic 
golden_scanner testcase_basic 
lex
lex testcase_basic 
ls
flex testcase_basic 
cd ../
mkdir test
cd test/
touch count_line.l
vim count_line.l 
flex count_line.l 
ls
vim lex.yy.c 
gcc lex.yy.c -lfl
ls
./a.out
pwd
ls
touch blank.l && vim blank.l
flex blank.l 
ls
vim blank.l 
flex blank.l 
vim count_line.l 
touch exclusive.l && vim exclusive.l
flex exclusive.l 
ls
gcc lex.yy.c -lfl
ls
./a.out
cp exclusive.l inclusive.l
vim inclusive.l 
flex inclusive.l 
vim inclusive.l 
ls
gcc lex.yy.c -lfl
./a.out
cd ../hw1/
ls
touch scanner.l
flex scanner.l 
vim scanner.l 
flex scanner.l 
ls
gcc lex.yy.c -lfl
ls
./a.out < testcase_basic 
git
cd ../
git init
git add .
git commit -m "create blank scanner.l and do some tests"
git config --global user.email "bruce1198@gmail.com"
git config --global user.name "kwang"
git commit -m "create blank scanner.l and do some tests"
cd hw1/
ls
touch testcase_basic.out
vim testcase_basic.out 
ls
cd 
git status
git add .
git commit -m "uplaod test.out'
git commit -m "uplaod test.out"
logout
