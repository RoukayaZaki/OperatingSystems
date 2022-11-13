touch _ex3.txt	
echo "Hello, Roukaya Mohammed!" > _ex3.txt	

echo -e "Permissions at the beginning:" > ex3.txt		
ls -l _ex3.txt >> ex3.txt

chmod a-x _ex3.txt
echo -e "\nAfter removing execute permission for everybody:" >> ex3.txt		
ls -l _ex3.txt >> ex3.txt

chmod u+rwx,o+rwx _ex3.txt	
echo -e "\nAfter granting all permissions to owner and others (not group):" >> ex3.txt		
ls -l _ex3.txt >> ex3.txt

chmod g=u _ex3.txt		
echo -e "\nAfter making group permissions equal to user permissions:" >> ex3.txt		
ls -l _ex3.txt >> ex3.txt

echo -e "\n\n" >> ex3.txt
cat ex3_answers.txt >> ex3.txt