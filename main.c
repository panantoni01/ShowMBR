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
    
    hexdump_MBR(mbr_content);
    
    if (mbr_content[510] != 0x55 || mbr_content[511] != 0xAA)
        printf("\nWARNING: incorrect boot signature: [%02x %02x]\n", mbr_content[510], mbr_content[511]);
    else
        printf("\nCorrect boot signature: [%02x %02x]\n", mbr_content[510], mbr_content[511]);

    print_disass(mbr_content);

    for (int i = 0; i <= 3; i++) {
        putchar('\n');
        print_part(mbr_content, i);
    }

    return 0;
}