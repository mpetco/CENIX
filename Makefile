g++ -static filenavetool/filenavtool.cpp -o filenavtool
g++ -static printxt/printxt.cpp -o printxt
g++ -static tictactoe/tictactoe.cpp -o tictactoe
g++ -static mte/mte.cpp -o mte 
g++ -static cesh/shell.cpp -o init
echo cesh/init | cpio2 -o -H newc > ../init.cpio
make isoimage FDARGS="initrd=/init.cpio" FINITRD=~./cesh/init.cpio
dd if=/dev/zero of=boot bs=1M count=50
mkfs -t fat ./boot
syslinux ./boot
mkdir temp
mount boot temp
mv bzImage init.cpio filenavtool printxt tictactoe mte ./temp
umount temp

