#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"wrappers.h"
#include"mbr.h"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <block dev>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    int fd = Open(filename, O_RDONLY);
    uint8_t mbr_content[512];
    Read(fd, mbr_content, 512); 
    Close(fd);
    
    /* The executable should be installed with SUID flag -
    root privileges are needed to read from block devices. 
    Having read the MBR sector from a block device, there is 
    no longer need to maintain these privileges. */
    Setuid(getuid());

    hexdump_MBR(mbr_content);
    print_signatures(mbr_content);
    print_disass(mbr_content);
    for (int i = 0; i <= 3; i++) {
        putchar('\n');
        print_part(mbr_content, i);
    }

    return 0;
}