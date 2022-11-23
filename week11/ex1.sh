dd if=/dev/zero of=lofs.img bs=1M count=50
losetup -a
mkfs.ext4 ./lofs.img
sudo losetup -fP lofs.img
losetup -a
mkdir lofsdisk
loopPath=$(losetup | grep "lofs" | awk '{print $1}')
sudo mount -o loop $loopPath ./lofsdisk