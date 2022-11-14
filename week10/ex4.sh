mkdir tmp
cd tmp
touch file1 file2
ln file1 link1
cd ..
gcc ex4.c -o ex4
./ex4 > ex4.txt
rm ex4
cd tmp
rm file1 link1 file2
cd ..
rmdir tmp