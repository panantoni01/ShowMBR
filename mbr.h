#include<stdio.h>
#include<stdint.h>
#include<endian.h>
#include<stdlib.h>

#define MBR_SIZE 512
#define ROW 16

#define STYLE_BOLD  "\033[1m"
#define STYLE_NO_BOLD  "\033[22m"

#define print_bold(...) ({ \
    printf(STYLE_BOLD); \
    printf(__VA_ARGS__); \
    printf(STYLE_NO_BOLD); \
})

struct chs {
    uint8_t h; /* 8 head bits */
    uint8_t s; /* 2 higher cylinder bits + 6 sector bits */
    uint8_t c; /* 8 lower cylinder bits */
};

struct part_entry {
    uint8_t part_status;
    struct chs chs_first;
    uint8_t part_type;
    struct chs chs_last; 
    uint32_t lba_first; /* LBA of the first partition sector (LE) */
    uint32_t sectors_count; /* number of sectors in the partition (LE) */
};

void hexdump_MBR(uint8_t buffer[MBR_SIZE]);
void print_signatures(uint8_t buffer[MBR_SIZE]);
void print_part(uint8_t buffer[MBR_SIZE], int num);
void print_disass(uint8_t buffer[MBR_SIZE]);