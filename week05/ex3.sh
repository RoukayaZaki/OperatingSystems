gcc -pthread ex3.c -o ex3
echo "1 thread:" > ex3.txt
{ time ./ex3 10000000   1; } 2>> ex3.txt
echo -e "\n2 threads:" >> ex3.txt
{ time ./ex3 10000000   2; } 2>> ex3.txt
echo -e "\n4 threads:" >> ex3.txt
{ time ./ex3 10000000   4; } 2>> ex3.txt
echo -e "\n10 threads:" >> ex3.txt
{ time ./ex3 10000000  10; } 2>> ex3.txt
echo -e "\n100 threads:" >> ex3.txt
{ time ./ex3 10000000 100; } 2>> ex3.txt
