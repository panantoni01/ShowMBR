#include<stdio.h>
#include<stdint.h>
#include<endian.h>

#define MBR_SIZE 512
#define ROW 16

struct part_entry{
    uint8_t part_status;
    struct {
        uint8_t h;
        uint8_t s;
        uint8_t c;
    } chs_first; /* CHS of the first sector in partition */
    uint8_t part_type;
    struct {
        uint8_t h;
        uint8_t s;
        uint8_t c;
    } chs_last; /* CHS of the last sector in partition */
    uint32_t lba_first; /* LBA of the first partition sector (LE) */
    uint32_t sectors_count; /* number of sectors in the partition (LE) */
};

void hexdump_MBR(uint8_t buffer[MBR_SIZE]);
void print_part(uint8_t buffer[MBR_SIZE], int num);