sudo mkdir -p lofsdisk/{bin,lib/x86_64-linux-gnu,lib64}

sudo cp /bin/{bash,echo,ls,cat} lofsdisk/bin/

sudo cp /lib/x86_64-linux-gnu/{libtinfo.so.6,libc.so.6,libselinux.so.1,libpcre2-8.so.0} lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/

gcc ex2.c -o ex2.out

sudo bash -c "echo 'Roukaya' > lofsdisk/file1"
sudo bash -c "echo 'Mohammed' > lofsdisk/file2"

sudo cp ex2.out lofsdisk/

echo "chroot" > ex2.txt
sudo chroot lofsdisk ./ex2.out >> ex2.txt 
echo "actual root" >> ex2.txt
./ex2.out >> ex2.txt