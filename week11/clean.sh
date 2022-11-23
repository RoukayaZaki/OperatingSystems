loopPath=$(losetup | grep "lofs" | awk '{print $1}')
sudo umount lofsdisk
sudo losetup -d $loopPath
sudo rm -rf lofs.img lofsdisk