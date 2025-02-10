g++ -static cesh/shell.cpp -o init
make isoimage FDARGS="initrd=/init.cpio" FINITRD=~/Desktop/CENIX/cesh/init.cpio

