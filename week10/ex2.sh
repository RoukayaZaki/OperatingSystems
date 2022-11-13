touch ../week01/file.txt
echo "Hello, Roukaya Mohammed!" > ../week01/file.txt
link ../week01/file.txt _ex2.txt
INUM=$(ls -i _ex2.txt | cut -d ' ' -f 1)
find .. -inum "$INUM" > ex2.txt
find .. -inum "$INUM" -exec rm {} \;
