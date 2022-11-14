touch ../week01/file.txt
echo "Hello, Roukaya Mohammed!" > ../week01/file.txt
link ../week01/file.txt _ex2.txt
INUM=$(ls -i _ex2.txt | cut -d ' ' -f 1)
find .. -inum "$INUM" > ex2.txt
echo -e "Before removing _ex2.txt using link path:\n" >> ex2.txt
ls >> ex2.txt
find . -inum "$INUM" -exec rm {} \;
echo -e "After removing _ex2.txt using link path:\n" >> ex2.txt
ls >> ex2.txt