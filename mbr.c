#define _DEFAULT_SOURCE

#include"wrappers.h"
#include"mbr.h"
#include"parttypes_map.h"


void hexdump_MBR(uint8_t buffer[MBR_SIZE]) {
    for (int i = 0; i < MBR_SIZE/ROW; i++) {
        printf("%08x  ", i*ROW);
        char printable[17]; 
        printable[16] = '\0';
        for (int j = 0; j < ROW; j++) {
            printf("%02x ", buffer[i*ROW + j]);
            if (buffer[i*ROW + j] <= 125 && buffer[i*ROW + j] >= 32)
                printable[j] = buffer[i*ROW + j];
            else
                printable[j] = '.'; 
        }
        printf(" |%s|\n", printable);
    }
}

static void print_chs(struct chs* chs_struct) {
    int c = (int)chs_struct->c + ((chs_struct->s & 0b11000000)<<2);
    int h = (int)(chs_struct->h);
    int s = (int)(chs_struct->s & 0b00111111);
    printf("\tC = 0x%03x = %d\n", c, c);
    printf("\tH = 0x%02x = %d\n", h, h);
    printf("\tS = 0x%02x = %d\n", s, s);
}

void print_part(uint8_t buffer[MBR_SIZE], int num) {
    if (num < 0 || num > 3) { /* we have 4 partitions: part0 ... part3 */
        fprintf(stderr, "ERROR: wrong partition number\n");
        exit(1);
    }

    /* index (in 'buffer' array) of the first byte of partition no. `num` */
    const int part_entry_addr = 510 - (4 - num) * sizeof(struct part_entry);
    struct part_entry* curr_entry = (struct part_entry*)(buffer + part_entry_addr);
   
    printf(STYLE_BOLD);
    printf("Partition no. %d:\n", num);
    printf(STYLE_NO_BOLD);

    printf("Boot flag is 0x%02x - ", (int)curr_entry->part_status);
    if (curr_entry->part_status == 0x80)
        printf("active (bootable) partition\n");
    else if (curr_entry->part_status == 0x0)
        printf("inactive (non-bootable) partition\n");
    else
        printf("invalid boot flag\n");

    printf("Partition type is 0x%02x - %s\n", curr_entry->part_type, find_parttype_by_hex(curr_entry->part_type));

    printf("CHS address of the first sector of partition:\n");
    print_chs(&(curr_entry->chs_first));
    printf("CHS address of the last sector of partition:\n");
    print_chs(&(curr_entry->chs_last));

    printf("LBA of the first partition sector: 0x%08x = %u\n", 
        le32toh(curr_entry->lba_first), le32toh(curr_entry->lba_first));
    printf("Number of sectors in the partition: 0x%08x = %u\n", 
        le32toh(curr_entry->sectors_count), le32toh(curr_entry->sectors_count));
}