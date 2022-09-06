date
sleep 3

mkdir root
cd root
touch root.txt


cd ..

date
sleep 3

mkdir home
cd home
touch home.txt


ls -lt -r ~ > home.txt

cd ..
cd root

ls -lt -r / > root.txt

cat root.txt
ls

cd ..

cd home
ls
cat home.txt