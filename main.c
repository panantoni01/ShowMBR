#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include"wrappers.h"
#include"mbr.h"


int main(int argc, char* argv[]) {
    int hexdump = 0;
    int disassemble = 0;
    int ebr = 0; /* TODO: if we >=1 extended partitions, then analyze their ebrs */

    int opt;
    while ((opt = getopt(argc, argv, "hde")) != -1) {
        switch (opt) {
            case 'h':
                hexdump = 1;
                break;
            case 'd':
                disassemble = 1;
                break;
            case 'e':
                ebr = 1;
                break;
            default:
                fprintf(stderr, "usage: %s [-h] [-d] [-e] <block_dev>\n", argv[0]);
                exit(1);
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "argument missing\n");
        exit(EXIT_FAILURE);
    }

    char* filename = argv[optind];
    int fd = Open(filename, O_RDONLY);
    uint8_t mbr_content[512];
    Read(fd, mbr_content, 512); 
    Close(fd);
    
    /* The executable should be installed with SUID flag -
    root privileges are needed to read from block devices. 
    Having read the MBR sector from a block device, there is 
    no longer need to maintain these privileges. */
    Setuid(getuid());

    if (hexdump)
        hexdump_MBR(mbr_content);
    print_signatures(mbr_content);
    if (disassemble) 
        print_disass(mbr_content);
    for (int i = 0; i <= 3; i++) {
        putchar('\n');
        print_part(mbr_content, i);
    }

    return 0;
}